#include "FluInfoBarManager.h"
#include "FluTopInfoBarManager.h"
#include "FluInfoBar.h"

//QMap<FluInfoBarPositon, FluInfoBarManager*> FluInfoBarManager::m_managers;
FluInfoBarManager::FluInfoBarManager() : QObject()
{
    m_spacing = 16;
    m_margin = 24;
}

void FluInfoBarManager::addInfoBar(FluInfoBar* infoBar)
{
    QWidget* parentWidget = (QWidget*)infoBar->parent();
    if (!parentWidget)
        return;

    if (!m_infoBars.contains(parentWidget))
    {
        parentWidget->installEventFilter(this);
        QList<FluInfoBar*> barList;

        m_infoBars[parentWidget] = barList;
        m_aniGroups[parentWidget] = new QParallelAnimationGroup(this);
    }

    if (m_infoBars[parentWidget].contains(parentWidget))
        return;

    QPropertyAnimation* dropAni = new QPropertyAnimation(infoBar, "pos");
    dropAni->setDuration(200);
    m_aniGroups[parentWidget]->addAnimation(dropAni);
    infoBar->setProperty("dropAni", QVariant::fromValue(dropAni));

    m_infoBars[parentWidget].append(infoBar);
    auto slideAni = createSlideAni(infoBar);
    m_slideAnis.append(slideAni);
    infoBar->setProperty("slideAni", QVariant::fromValue(slideAni));

    connect(infoBar, &FluInfoBar::closeSignal, [=]() {});
    slideAni->start();
}

void FluInfoBarManager::removeInfoBar(FluInfoBar* infoBar)
{
    auto parentWidget = (QWidget*)infoBar->parent();
    if (parentWidget == nullptr)
        return;

    if (!m_infoBars[parentWidget].contains(infoBar))
        return;

    auto dropAni = infoBar->property("dropAni").value<QPropertyAnimation*>();
    if (dropAni != nullptr)
    {
        m_aniGroups[parentWidget]->removeAnimation(dropAni);
        m_dropAnis.removeOne(dropAni);
    }

    auto slideAni = infoBar->property("slideAni").value<QPropertyAnimation*>();
    if (slideAni != nullptr)
    {
        m_slideAnis.removeOne(slideAni);
    }

    updateDropAni(parentWidget);  // 更新parentWidget中的属性动画
    m_aniGroups[parentWidget]->start();
}

QPropertyAnimation* FluInfoBarManager::createSlideAni(FluInfoBar* infoBar)
{
    QPropertyAnimation* slideAni = new QPropertyAnimation(infoBar, "pos");
    slideAni->setEasingCurve(QEasingCurve::OutQuad);
    slideAni->setDuration(200);
    slideAni->setStartValue(slideAniStartPos(infoBar));
    slideAni->setEndValue(slideAniEndPos(infoBar));
    return slideAni;
}

void FluInfoBarManager::updateDropAni(QWidget* parentWidget)
{
    for (auto infoBar : m_infoBars[parentWidget])
    {
        auto dropAni = infoBar->property("dropAni").value<QPropertyAnimation*>();
        if (!dropAni)
            continue;

        dropAni->setStartValue(dropAniStartPos(infoBar));  // 当前infobar的位置
        dropAni->setEndValue(dropAniEndPos(infoBar));
    }
}


FluInfoBarManagers* FluInfoBarManagers::m_infoBarManagers;
FluInfoBarManagers::FluInfoBarManagers()
{
    if (m_infoBarManagers != nullptr)
        return;
    m_infoBarManagers = new FluInfoBarManagers();
    m_infoBarManagers->m_managers[FluInfoBarPositon::TOP] = new FluTopInfoBarManager();
}

FluInfoBarManagers::~FluInfoBarManagers()
{
    for (auto itMap = m_infoBarManagers->m_managers.begin(); itMap != m_infoBarManagers->m_managers.end(); itMap++)
    {
        delete itMap.value();
    }

    m_infoBarManagers->m_managers.clear();
}

void FluInfoBarManagers::addInfoBar(FluInfoBar* infoBar, FluInfoBarPositon postion)
{
    FluInfoBarManager* manager = getInfoBarManager(postion);
    if (!manager)
        return;
    manager->addInfoBar(infoBar);
}

FluInfoBarManager* FluInfoBarManagers::getInfoBarManager(FluInfoBarPositon position)
{
    if (!m_infoBarManagers->m_managers.contains(position))
        return nullptr;
    return m_infoBarManagers->m_managers[position];
}

FluInfoBar* FluInfoBarManagers::__new(FluAwesomeType awesomeType, const QString& context, bool bClosable /*= true*/, int duration /*= 1000*/, FluInfoBarPositon position /*= FluInfoBarPositon::TOP*/, QWidget* parent /*= nullptr*/)
{
    FluInfoBar* infoBar = new FluInfoBar(awesomeType, context, bClosable, duration, position, parent);
    infoBar->show();
    return infoBar;
}

FluInfoBar* FluInfoBarManagers::success(const QString& context, bool bClosable /*= true*/, int duration /*= 1000*/, FluInfoBarPositon position /*= FluInfoBarPositon::TOP*/, QWidget* parent /*= nullptr*/)
{
    return __new(FluAwesomeType::CompletedSolid, context, bClosable, duration, position, parent);
}
