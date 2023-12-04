#pragma once

#include "FluGalleryInterface.h"

class FluLayoutInterface : public FluGalleryInterface
{
  public:
    FluLayoutInterface(QWidget* parent = nullptr) : FluGalleryInterface("布局", "FluentUiControl::Layout", parent)
    {
        setObjectName("layoutInterface");
    }
};
