#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <vector>
#include "../FluentUiControl/FluNavigationAvatarWidget.h"

class FluAvatarWidgetDemo : public QWidget
{
  public:
    FluAvatarWidgetDemo(QWidget* parent = nullptr) : QWidget(parent)
    {
        resize(400, 300);
        setStyleSheet("FluAvatarWidgetDemo{background:white}");
        std::vector<int> sizes = {96, 48, 32, 24};
        for (auto s : sizes)
        {
        }
    }

  private:
};
