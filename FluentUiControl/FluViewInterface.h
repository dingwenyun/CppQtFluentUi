#pragma once

#include "FluGalleryInterface.h"
#include "FluTableFrame.h"
#include "FluListFrame.h"

class FluViewInterface : public FluGalleryInterface
{
    Q_OBJECT
  public:
    FluViewInterface(QWidget* parent = nullptr) : FluGalleryInterface("视图", "FluentUiControl::View", parent)
    {
        setObjectName("viewInterface");

        auto listFrame = new FluListFrame(this);
        addExampleCard("简单的列表控件", listFrame, "");

        auto taleFrame = new FluTableFrame(this);
        addExampleCard("简单的表格组件", taleFrame, "");
    }
};
