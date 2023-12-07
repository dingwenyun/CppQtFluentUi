#pragma once

#include "FluGalleryInterface.h"
#include "FluButton.h"
#include "FluCheckBox.h"
#include "FluComboBox.h"
#include "FluRoundMenu.h"
#include <QAction>

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

        auto twoStateCheckButton = new FluCheckBox("双态复选框", nullptr);
        addExampleCard("复选框", twoStateCheckButton, "");

        auto threeStateCheckButton = new FluCheckBox("三态复选框", nullptr);
        threeStateCheckButton->setTristate(true);
        addExampleCard("复选框", threeStateCheckButton, "");

        auto comboBox = new FluComboBox();
        comboBox->addItems({" shoko 🥰 ", "西宫硝子 😊 ", "一级棒卡哇伊的硝子酱 😘"});
        comboBox->setCurrentIndex(0);
        comboBox->setMinimumWidth(210);
        addExampleCard("下拉框", comboBox, "");

        // EditableComboBox

        auto roundMenu = new FluRoundMenu("", this);
        QAction* sendAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Send), "发送");
        QAction* saveAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Save), "保存");
        roundMenu->addActions({sendAction, saveAction});
    }
};
