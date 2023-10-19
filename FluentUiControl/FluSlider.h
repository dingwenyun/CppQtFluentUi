#pragma once

#include <QSlider>
#include <QFile>
#include <QMouseEvent>
#include <QDebug>

class FluSlider : public QSlider
{
    Q_OBJECT
  public:
    FluSlider(QWidget* parent);

    FluSlider(Qt::Orientation orientation, QWidget* parent = nullptr);
  signals:
    void clicked(int v);

  protected:
    void mousePressEvent(QMouseEvent* event);
};
