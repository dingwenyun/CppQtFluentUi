#pragma once

#include <QScrollArea>
#include "FluSmoothScrollDelegate.h"

class FluSmoothScrollArea : public QScrollArea
{
  public:
    FluSmoothScrollArea(QWidget* widget = nullptr) : QScrollArea(widget)
    {
        m_delegate = new FluSmoothScrollDelegate(this);
    }

    void setScrollAnimation(Qt::Orientation orient, int duration, QEasingCurve easingCurve = QEasingCurve::OutCubic)
    {
        FluSmoothScrollBar* bar;
        if (orient == Qt::Horizontal)
        {
            bar = m_delegate->getHScrollBar();
        }
        else
        {
            bar = m_delegate->getVScrollBar();
        }

        bar->setScrollAnimation(duration, easingCurve);
    }

  public:
    FluSmoothScrollDelegate* m_delegate;
};
