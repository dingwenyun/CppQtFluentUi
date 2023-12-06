#pragma once

#include "FluGalleryInterface.h"

class FluStatusInfoInterface : public FluGalleryInterface
{
    Q_OBJECT
  public:
    FluStatusInfoInterface(QWidget* parent = nullptr) : FluGalleryInterface("状态与信息", "FluentUiControl::Status", parent)
    {
        setObjectName("statusInfoInterface");
    }
};
