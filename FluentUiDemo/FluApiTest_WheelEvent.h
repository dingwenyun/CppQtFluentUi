#pragma once

#include <QWidget>
#include <QWheelEvent>
#include "../FluentUiUtils/FluLogUtils.h"

class FluApiTest_WheelEvent : public QWidget
{
    Q_OBJECT
  public:
    FluApiTest_WheelEvent(QWidget* widget = nullptr);

  protected:
    void wheelEvent(QWheelEvent* event);
};
