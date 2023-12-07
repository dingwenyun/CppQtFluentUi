#pragma once

#include "FluGalleryInterface.h"
#include "FluMessageBox.h"

class FluDialogInterface : public FluGalleryInterface
{
  public:
    FluDialogInterface(QWidget* parent = nullptr) : FluGalleryInterface("对话框与弹出窗口", "FlentUiControl::Dialog")
    {
        setObjectName("dialogInterface");
        initMessBox();
    }

    void initMessBox()
    {
        auto button = new FluPushButton("显示对话框");
        connect(button, &FluPushButton::clicked, [=](bool bClicked) {
            FluMessageBox* msgBox = new FluMessageBox("遮罩对话框", "文本.../文本...文本...文本...文本...", window());
            msgBox->exec();
        });

        addExampleCard("带遮罩的消息框", button, "");
    }
};
