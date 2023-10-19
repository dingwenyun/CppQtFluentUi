#pragma once

#include <QApplication>
#include <QWidget>
#include "../FluentUiControl/FluSlider.h"

class FluSliderDemo : public QWidget
{
    // Q_OBJECT
  public:
    FluSliderDemo(QWidget* parent = nullptr);

  private:
    FluSlider* hSlider;
    FluSlider* vSlider;
};