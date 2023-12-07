#pragma once

#include "FluGalleryInterface.h"
#include "FluScrollArea.h"
#include "FluSmoothScrollArea.h"

class FluScrollInterface : public FluGalleryInterface
{
    Q_OBJECT
  public:
    FluScrollInterface(QWidget* parent = nullptr) : FluGalleryInterface("滚动条", "FluentUiControl::SrollArea", parent)
    {
        setObjectName("srollInterface");

        initScrollArea();
        initSmoothScrollArea();
    }

    void initScrollArea()
    {
        auto scrollArea = new FluScrollArea();
        auto imageLabel = new FluImageLabel("../res/chidanta2.jpg", this);
        imageLabel->scaledToWidth(775);
        // imageLabel->setBorderRadius(8, 8, 8, 8);
        scrollArea->horizontalScrollBar()->setValue(0);
        scrollArea->setWidget(imageLabel);
        scrollArea->setFixedSize(775, 430);
        addExampleCard("平滑滚动区域", scrollArea, "");
    }

    void initSmoothScrollArea()
    {
        auto scrollArea = new FluSmoothScrollArea();
        auto imageLabel = new FluImageLabel("../res/chidanta3.jpg", this);
        imageLabel->scaledToWidth(660);
        // imageLabel->setBorderRadius(8, 8, 8, 8);
        scrollArea->horizontalScrollBar()->setValue(0);
        scrollArea->setWidget(imageLabel);
        scrollArea->setFixedSize(660, 540);
        addExampleCard("平滑滚动区域", scrollArea, "");
    }
};
