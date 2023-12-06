#pragma once

#include "FluGalleryInterface.h"

class FluNavigationViewInterface : public FluGalleryInterface
{
    Q_OBJECT
  public:
    FluNavigationViewInterface(QWidget* parent = nullptr) : FluGalleryInterface("导航", "FluentUiControl::Navigation", parent)
    {
        setObjectName("navigationViewInterface");
    }
};
