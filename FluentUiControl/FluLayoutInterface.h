#pragma once

#include "FluGalleryInterface.h"
#include "FluFlowLayout.h"

class FluLayoutInterface : public FluGalleryInterface
{
  public:
    FluLayoutInterface(QWidget* parent = nullptr) : FluGalleryInterface("布局", "FluentUiControl::Layout", parent)
    {
        setObjectName("layoutInterface");

        initFlowLayoutExample();
    }

    void initFlowLayoutExample()
    {
        QList<QString> texts = {"白金之星", "法皇之绿", "银色战车", "疯狂砖石", "黑蚊子多", "杀手皇后", "黄金体验", "钢链手指", "性感手枪", "D4C"};
        QWidget* widget = new QWidget();
        FluFlowLayout* layout = new FluFlowLayout(widget);
        layout->setContentsMargins(0, 0, 0, 0);
        for (auto text : texts)
        {
            auto button = new FluPushButton(text);
            layout->addWidget(button);
        }

        addExampleCard("流式布局", widget, "", 1);
    }
};
