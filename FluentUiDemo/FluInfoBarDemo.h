#pragma once

#include <QWidget>

#include "../FluentUiControl/FluInfoBarManager.h"
#include "../FluentUiControl/FluInfoBar.h"
#include <QVBoxLayout>
#include "../FluentUiControl/FluPushButton.h"

class FluInfoBarDemo : public QWidget
{
  public:
    FluInfoBarDemo(QWidget* parent = nullptr)
    {
        auto hBoxLayout = new QHBoxLayout(this);
        auto infoButton = new FluPushButton("info", this);
        auto succButton = new FluPushButton("succ", this);
        auto warnButton = new FluPushButton("warn", this);
        auto errorButton = new FluPushButton("error", this);

        hBoxLayout->addWidget(infoButton);
        hBoxLayout->addWidget(succButton);
        hBoxLayout->addWidget(warnButton);
        hBoxLayout->addWidget(errorButton);

        connect(infoButton, &FluPushButton::clicked, [=](bool bclicked) { FluInfoBar::__info("这是一个信息的消息条", true, 1000, this); });
        connect(succButton, &FluPushButton::clicked, [=](bool bclicked) { FluInfoBar::__succ("这是一个成功的消息条", true, 1000, this); });
        connect(warnButton, &FluPushButton::clicked, [=](bool bclicked) { FluInfoBar::__warn("这是一个警告的消息条", true, 1000, this); });
        connect(errorButton, &FluPushButton::clicked, [=](bool bclicked) { FluInfoBar::__err("这是一个错误的消息条", true, 1000, this); });

        resize(600, 400);
    }
};
