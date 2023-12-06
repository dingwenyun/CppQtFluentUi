#pragma once

#include "FluGalleryInterface.h"
#include "FluLineEdit.h"
#include "FluSearchLineEdit.h"
#include "FluPasswordLineEdit.h"

class FluTextInterface : public FluGalleryInterface
{
    Q_OBJECT
  public:
    FluTextInterface(QWidget* parent = nullptr) : FluGalleryInterface("文本", "FluentUiControl::Text", parent)
    {
        setObjectName("textInterface");

        FluLineEdit* lineEdit = new FluLineEdit();
        lineEdit->setText("这是一条文本内容...");
        lineEdit->setClearButtonEnabled(true);
        addExampleCard("带清空按钮的输入框", lineEdit, "");

        FluSearchLineEdit* searchLineEidt = new FluSearchLineEdit();
        searchLineEidt->setPlaceholderText("输入文本内容");
        searchLineEidt->setClearButtonEnabled(true);
        // searchLineEidt->setFixedHeight(230);

        QStringList list = {"Star Platinum", "Hierophant Green", "Made in Haven",     "King Crimson",     "Silver Chariot", "Crazy diamond",  "Metallica",        "Another One Bites The Dust",
                            "Heaven's Door", "Killer Queen",     "The Grateful Dead", "Stone Free",       "The World",      "Sticky Fingers", "Ozone Baby",       "Love Love Deluxe",
                            "Hermit Purple", "Gold Experience",  "King Nothing",      "Paper Moon King",  "Scary Monster",  "Mandom",         "20th Century Boy", "Tusk Act 4",
                            "Ball Breaker",  "Sex Pistols",      "D4C • Love Train",  "Born This Way",    "SOFT & WET",     "Paisley Park",   "Wonder of U",      "Walking Heart",
                            "Cream Starter", "November Rain",    "Smooth Operators",  "The Matte Kudasai"};
        QCompleter* completer = new QCompleter(list, searchLineEidt);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        completer->setMaxVisibleItems(10);
        searchLineEidt->setCompleter(completer);
        addExampleCard("带补全功能的输入框", searchLineEidt, "");

        auto passwordLineEdit = new FluPasswordLineEdit(this);
        passwordLineEdit->setFixedWidth(230);
        passwordLineEdit->setPlaceholderText("请输入你的密码");
        addExampleCard("密码输入框", passwordLineEdit, "");
    }
};
