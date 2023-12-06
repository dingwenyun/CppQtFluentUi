#pragma once

#include "FluGalleryInterface.h"

class FluScrollInterface : public FluGalleryInterface
{
    Q_OBJECT
  public:
    FluScrollInterface(QWidget* parent = nullptr) : FluGalleryInterface("滚动条", "FluentUiControl::SrollArea", parent)
    {
        setObjectName("srollInterface");
    }
};
