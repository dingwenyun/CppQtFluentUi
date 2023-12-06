#pragma once

#include "FluGalleryInterface.h"
#include "FluTableFrame.h"

class FluViewInterface : public FluGalleryInterface
{
    Q_OBJECT
  public:
    FluViewInterface(QWidget* parent = nullptr) : FluGalleryInterface("视图", "FluentUiControl::View", parent)
    {
        setObjectName("viewInterface");

        auto taleFrame = new FluTableFrame(this);
        addExampleCard("简单的表格组件", taleFrame, "");
    }
};
