#include "FluApiTest_WheelEvent.h"

FluApiTest_WheelEvent::FluApiTest_WheelEvent(QWidget* widget /*= nullptr*/) : QWidget(widget)
{
}

// 该函数只是为了确认一件事情，如果鼠标滚轮滚动的足够快，angleDelta角度也越大
void FluApiTest_WheelEvent::wheelEvent(QWheelEvent* event)
{
    QWidget::wheelEvent(event);
    LogDebug << "pixelDelta:" << event->pixelDelta() << "angleDelta:" << event->angleDelta();
}
