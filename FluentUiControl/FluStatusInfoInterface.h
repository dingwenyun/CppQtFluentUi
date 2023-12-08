#pragma once

#include "FluGalleryInterface.h"

class FluStatusInfoInterface : public FluGalleryInterface
{
    Q_OBJECT
  public:
    FluStatusInfoInterface(QWidget* parent = nullptr) : FluGalleryInterface("状态与信息", "FluentUiControl::Status", parent)
    {
        setObjectName("statusInfoInterface");
        initToolTipPushButtonExample();
    }

    void initToolTipPushButtonExample()
    {
        auto button = new FluPushButton("带工具提示的按钮");
        auto toolTipFilter = new FluToolTipFilter(button);
        button->setToolTip("只因在人群中多看了你一眼");
        button->installEventFilter(toolTipFilter);
        addExampleCard("带工具提示的按钮", button, "");
    }
};
