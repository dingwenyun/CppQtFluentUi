#pragma once

#include "FluMenuAnimationManager.h"
#include <QRegion>
#include "FluRoundMenu.h"
#include <QApplication>
#include <QCursor>
#include <QScreen>

class FluDropDownMenuAnimationManager : public FluMenuAnimationManager
{
  public:
    FluDropDownMenuAnimationManager(FluRoundMenu* menu) : FluMenuAnimationManager(menu)
    {
    }

    void exec(QPoint pos)
    {
        QPoint endPos = _endPosition(pos);
        int nH = m_menu->height() + 5;

        m_ani->setStartValue(endPos - QPoint(0, nH / 2));
        m_ani->setEndValue(endPos);
        m_ani->start();
    }

    QSize availableViewSize(QPoint pos)
    {
        QRect screenRect = QApplication::screenAt(QCursor::pos())->availableGeometry();
        QSize viewSize;
        viewSize.setWidth(screenRect.width() - 100);

        int nHeight = qMax(screenRect.bottom() - pos.y() - 10, 1);
        viewSize.setHeight(nHeight);

        return viewSize;
    }

    void _onValueChanged()
    {
        int menuW = _menuSize().width();
        int menuH = _menuSize().height();

        int nY = m_ani->endValue().toPoint().y() - m_ani->currentValue().toPoint().y();
        m_menu->setMask(QRegion(0, nY, menuW, menuH));
    }
};
