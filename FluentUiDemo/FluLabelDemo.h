#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include "../FluentUiControl/FluLabel.h"

class FluLabelDemo : public QWidget
{
  public:
    FluLabelDemo(QWidget* parent = nullptr) : QWidget(parent)
    {
        QVBoxLayout* vLayout = new QVBoxLayout(this);
        vLayout->setContentsMargins(30, 30, 30, 30);
        vLayout->setSpacing(20);
        vLayout->addWidget(new FluHyperLinkLabel("https://www.bilibili.com/", "bilibili.com"));
        vLayout->addWidget(new FluCaptionLabel("Caption"));
        vLayout->addWidget(new FluBodyLabel("Body"));
        vLayout->addWidget(new FluStrongBodyLabel("Strong Body"));
        vLayout->addWidget(new FluSubTitleLabel("Sub Title"));
        vLayout->addWidget(new FluTitleLabel("Title"));
        vLayout->addWidget(new FluLargeTitleLabel("Large Title"));
        vLayout->addWidget(new FluDisplayLabel("Display"));
    }
};
