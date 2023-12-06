#pragma once

#include "FluGalleryInterface.h"
#include "FluButton.h"
#include "FluCheckBox.h"

class FluBasicInputInterface : public FluGalleryInterface
{
    Q_OBJECT
  public:
    FluBasicInputInterface(QWidget* parent = nullptr) : FluGalleryInterface("基本输入", "FluentUiControl::Inputs", parent)
    {
        setObjectName("basicInputInterface");

        auto standardPushButton = new FluPushButton("标准按钮");
        addExampleCard("带文本的简单按钮", standardPushButton, "");

        auto toolButton = new FluToolButton(QIcon("../res/kunkun.png"));
        toolButton->setIconSize(QSize(40, 40));
        toolButton->resize(70, 70);
        addExampleCard("带图标按钮", toolButton, "");

        auto primaryPushButton = new FluPrimaryPushButton("主题色按钮");
        addExampleCard("主题色按钮", primaryPushButton, "");

        auto primaryToolButton = new FluPrimaryToolButton(FluIconUtils::GetFluentIcon(FluAwesomeType::Globe));
        addExampleCard("主题色工具按钮", primaryToolButton, "");

        auto transparentButton = new FluTransparentPushButton("透明按钮", this, FluIconUtils::GetFluentIcon(FluAwesomeType::BookmarksMirrored));
        addExampleCard("透明按钮", transparentButton, "");

        auto transparentToolButton = new FluTransparentToolButton(this, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::BookmarksMirrored));
        addExampleCard("透明工具按钮", transparentToolButton, "");

        auto checkButton = new FluCheckBox("双态复选框", this);
        addExampleCard("双态复选框", checkButton, "");
    }
};
