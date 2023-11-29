#include "FluDef.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include "FluSlider.h"

FluSlider::FluSlider(QWidget* parent) : QSlider(parent)
{
    QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluSlider.qss");
    setStyleSheet(qss);
}

FluSlider::FluSlider(Qt::Orientation orientation, QWidget* parent /*= nullptr*/) : QSlider(orientation, parent)
{
    QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluSlider.qss");
    setStyleSheet(qss);
}

void FluSlider::mousePressEvent(QMouseEvent* event)
{
    QSlider::mousePressEvent(event);
    //   qDebug() << "w:" << width() << ",h:" << height() << ",maximum:" << maximum();
    int tmpValue = 0;
    if (orientation() == Qt::Horizontal)
    {
        tmpValue = event->pos().x() * 1.0 / width() * maximum();
    }
    else
    {
        tmpValue = (height() - event->pos().y()) * 1.0 / height() * maximum();
    }

    // qDebug() << "tmpValue:" << tmpValue;
    setValue(tmpValue);
    emit clicked(value());
    //  update();
}
