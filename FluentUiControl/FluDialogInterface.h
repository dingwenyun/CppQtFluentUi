#pragma once

#include "FluGalleryInterface.h"

class FluDialogInterface : public FluGalleryInterface
{
  public:
    FluDialogInterface(QWidget* parent = nullptr) : FluGalleryInterface("对话框与弹出窗口", "FlentUiControl::Dialog")
    {
        setObjectName("dialogInterface");
    }
};
