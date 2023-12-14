#include "FluInfoBarManager.h"
#include "FluInfoBar.h"

FluInfoBarManager* FluInfoBarManager::m_infoBarManager = nullptr;
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
    dropAni->setDuration(500);
    m_aniGroups[parentWidget]->addAnimation(dropAni);
    infoBar->setProperty("dropAni", QVariant::fromValue(dropAni));

    m_infoBars[parentWidget].append(infoBar);
    auto slideAni = createSlideAni(infoBar);
    m_slideAnis.append(slideAni);
    infoBar->setProperty("slideAni", QVariant::fromValue(slideAni));
    connect(infoBar, &FluInfoBar::closeSignal, [=]() { removeInfoBar(infoBar); });
    slideAni->start();
}

void FluInfoBarManager::removeInfoBar(FluInfoBar* infoBar)
{
    auto parentWidget = (QWidget*)infoBar->parent();
    if (parentWidget == nullptr)
        return;

    if (!m_infoBars[parentWidget].contains(infoBar))
        return;

    m_infoBars[parentWidget].removeOne(infoBar);
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
    slideAni->setDuration(500);
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

QPoint FluInfoBarManager::slideAniStartPos(FluInfoBar* infoBar)
{
    return (getInfoBarPos(infoBar) - QPoint(0, m_spacing));
}

QPoint FluInfoBarManager::slideAniEndPos(FluInfoBar* infoBar)
{
    return getInfoBarPos(infoBar);
}

QPoint FluInfoBarManager::dropAniStartPos(FluInfoBar* infoBar)
{
    return infoBar->pos();
}

QPoint FluInfoBarManager::dropAniEndPos(FluInfoBar* infoBar)
{
    return getInfoBarPos(infoBar);
}

QPoint FluInfoBarManager::getInfoBarPos(FluInfoBar* infoBar)
{
    QWidget* parentWidget = (QWidget*)infoBar->parent();
    int nX = (parentWidget->width() - infoBar->width()) / 2;
    int nIndex = m_infoBars[parentWidget].indexOf(infoBar);
    int nY = m_margin + (infoBar->height() + m_spacing) * nIndex;
    return QPoint(nX, nY);
}

FluInfoBarManager* FluInfoBarManager::getInstance()
{
    if (m_infoBarManager != nullptr)
        return m_infoBarManager;
    m_infoBarManager = new FluInfoBarManager();
    return m_infoBarManager;
}

FluInfoBar* FluInfoBarManager::__new(FluAwesomeType awesomeType, FluInfoBarType type, const QString& context, bool bClosable /*= false*/, int duration /*= 1000*/, QWidget* parent /*= nullptr*/)
{
    FluInfoBar* infoBar = new FluInfoBar(awesomeType, type, context, bClosable, duration, parent);
    FluInfoBarManager::getInstance()->addInfoBar(infoBar);
    infoBar->show();
    return infoBar;
}

void FluInfoBarManager::__info(const QString& context, bool bClosable /*= false*/, int duration /*= 1000*/, QWidget* parent /*= nullptr*/)
{
    __new(FluAwesomeType::InfoSolid, FluInfoBarType::INFO, context, bClosable, duration, parent);
}

void FluInfoBarManager::__warn(const QString& context, bool bClosable /*= false*/, int duration /*= 1000*/, QWidget* parent /*= nullptr*/)
{
    __new(FluAwesomeType::InfoSolid, FluInfoBarType::WARN, context, bClosable, duration, parent);
}

void FluInfoBarManager::__succ(const QString& context, bool bClosable /*= false*/, int duration /*= 1000*/, QWidget* parent /*= nullptr*/)
{
    __new(FluAwesomeType::CompletedSolid, FluInfoBarType::SUCC, context, bClosable, duration, parent);
}

void FluInfoBarManager::__err(const QString& context, bool bClosable /*= false*/, int duration /*= 1000*/, QWidget* parent /*= nullptr*/)
{
    __new(FluAwesomeType::StatusErrorFull, FluInfoBarType::ERR, context, bClosable, duration, parent);
}