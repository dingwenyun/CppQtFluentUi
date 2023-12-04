#pragma once

#include "FluScrollArea.h"

class FluSettingInterface : public FluScrollArea
{
    Q_OBJECT
  public:
    FluSettingInterface(QWidget* parent = nullptr) : FluScrollArea(parent)
    {
        setObjectName("settingInterface");
        setStyleSheet(" \
            FluSettingInterface{background-color: transparent;} \
            QScrollArea {border:none;background - color : transparent;} \
            ");
    }
};
