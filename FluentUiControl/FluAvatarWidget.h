#pragma once

#include "FluImageLabel.h"
#include <QLabel>

class FluAvatarWidget : public FluImageLabel
{
    Q_PROPERTY(int radius READ getRadius WRITE setRadius)
  public:
    FluAvatarWidget(QWidget* parent = nullptr);

    FluAvatarWidget(QString image, QWidget* parent = nullptr);

    FluAvatarWidget(QImage image, QWidget* parent = nullptr);

    FluAvatarWidget(QPixmap image, QWidget* parent = nullptr); 

    void _postInit();

    int getRadius();

    void setRadius(int radius);

  protected:
    void paintEvent(QPaintEvent* event);
  private:
    int m_radius;
};
