#pragma once

#include "FluGalleryInterface.h"

class FluIconInterface : public FluGalleryInterface
{
  public:
    FluIconInterface(QWidget* parent = nullptr) : FluGalleryInterface("Icons", "FluentUi::Icons", parent)
    {
        setObjectName("iconInterface");
    }
};
