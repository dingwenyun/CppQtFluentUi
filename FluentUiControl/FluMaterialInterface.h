#pragma once

#include "FluGalleryInterface.h"

class FluMaterialInterface : public FluGalleryInterface
{
    Q_OBJECT
  public:
    FluMaterialInterface(QWidget* parent = nullptr) : FluGalleryInterface("材料", "FluentUiControl::Material", parent)
    {
        setObjectName("materialInterface");
    }
};
