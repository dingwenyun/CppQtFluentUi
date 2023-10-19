#include "FluSliderDemo.h"

FluSliderDemo::FluSliderDemo(QWidget* parent /*= nullptr*/) : QWidget(parent)
{
    hSlider = new FluSlider(Qt::Horizontal, this);
    hSlider->setFixedWidth(150);
    hSlider->move(50, 30);

    vSlider = new FluSlider(Qt::Vertical, this);
    vSlider->setFixedHeight(150);
    vSlider->move(140, 80);
}
