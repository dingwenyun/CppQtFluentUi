#include "FluPullUpMenuAnimationManager.h"

QPoint FluPullUpMenuAnimationManager::_endPosition(QPoint pos)
{
    FluRoundMenu* roundMenu = m_menu;
    QRect screenRect = QApplication::screenAt(QCursor::pos())->availableGeometry();
    int nW = roundMenu->width() + 5;
    int nH = roundMenu->height();

    int nX = qMin(pos.x() - roundMenu->layout()->contentsMargins().left(), screenRect.height() - nW);
    int nY = qMax(pos.y() - nH + 13, 4);

    return QPoint(nX, nY);
}

void FluPullUpMenuAnimationManager::exec(QPoint pos)
{
    QPoint endPos = _endPosition(pos);
    int nH = m_menu->height() + 5;
    m_ani->setStartValue(endPos + QPoint(0, nH / 2));
    m_ani->setEndValue(endPos);
    m_ani->start();
}

QSize FluPullUpMenuAnimationManager::availableViewSize(QPoint pos)
{
    QRect screenRect = QApplication::screenAt(QCursor::pos())->availableGeometry();

    int nW = screenRect.width() - 100;
    int nH = qMax(pos.y() - 28, 1);

    return QSize(nW, nH);
}

void FluPullUpMenuAnimationManager::_onValueChanged()
{
    int nW = _menuSize().width();
    int nH = _menuSize().height();
    int nY = m_ani->endValue().toPoint().y() - m_ani->currentValue().toPoint().y();
    m_menu->setMask(QRegion(0, nY, nW, nH - 28));
}
