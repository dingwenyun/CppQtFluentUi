#include "FluFadeInPullUpMenuAnimationManager.h"

FluFadeInPullUpMenuAnimationManager::FluFadeInPullUpMenuAnimationManager(FluRoundMenu* menu) : FluMenuAnimationManager(menu)
{
    m_opacityAni = new QPropertyAnimation(menu, "windowOpacity", this);
    m_aniGroup = new QParallelAnimationGroup(this);
    m_aniGroup->addAnimation(m_ani);
    m_aniGroup->addAnimation(m_opacityAni);
}

QPoint FluFadeInPullUpMenuAnimationManager::_endPosition(QPoint pos)
{
    FluRoundMenu* roundMenu = m_menu;
    QRect screenRect = QApplication::screenAt(QCursor::pos())->availableGeometry();
    int nW = roundMenu->width() + 5;
    int nH = roundMenu->height();

    int nX = qMin(pos.x() - roundMenu->layout()->contentsMargins().left(), screenRect.right() - nW);
    int nY = qMax(pos.y() - nH + 15, 4);

    return QPoint(nX, nY);
}

void FluFadeInPullUpMenuAnimationManager::exec(QPoint pos)
{
    QPoint endPos = _endPosition(pos);
    m_opacityAni->setStartValue(0);
    m_opacityAni->setEndValue(1);
    m_opacityAni->setDuration(150);
    m_opacityAni->setEasingCurve(QEasingCurve::OutQuad);

    m_ani->setStartValue(pos + QPoint(0, 8));
    m_ani->setEndValue(pos);
    m_ani->setDuration(200);
    m_ani->setEasingCurve(QEasingCurve::OutQuad);
    m_aniGroup->start();
}

QSize FluFadeInPullUpMenuAnimationManager::availableViewSize(QPoint pos)
{
    QRect screenRect = QApplication::screenAt(QCursor::pos())->availableGeometry();
    int nW = screenRect.width() - 100;
    int nH = pos.y() - 28;
    return QSize(nW, nH);
}
