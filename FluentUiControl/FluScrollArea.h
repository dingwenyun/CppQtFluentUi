#pragma once

#include <QScrollArea>
#include "FluSmoothScrollDelegate.h"

class FluScrollArea : public QScrollArea
{
  public:
    FluScrollArea(QWidget* parent = nullptr) : QScrollArea(parent)
    {
        m_srollDelegate = new FluSmoothScrollDelegate(this);
    }

    protected:
    FluSmoothScrollDelegate* m_srollDelegate;
};
