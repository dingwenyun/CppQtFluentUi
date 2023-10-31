#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <vector>
#include "../FluentUiControl/FluAvatarWidget.h"

class FluAvatarWidgetDemo : public QWidget
{
  public:
    FluAvatarWidgetDemo(QWidget* parent = nullptr) : QWidget(parent)
    {
        resize(400, 300);
        setStyleSheet("FluAvatarWidgetDemo{background:white}");
        QHBoxLayout* hBoxLayout = new QHBoxLayout(this);

        QPixmap avatar = QPixmap("../res/shoko.png");
        std::vector<int> sizes = {96, 48, 32, 24};
        for (auto s : sizes)
        {
            FluAvatarWidget* w = new FluAvatarWidget(avatar, this);
            w->setRadius(s / 2);
            hBoxLayout->addWidget(w);
        }
    }

  private:
};
