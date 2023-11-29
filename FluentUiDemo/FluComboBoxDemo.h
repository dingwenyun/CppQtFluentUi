#pragma once
#include <QWidget>
#include "../FluentUiControl/FluComboBox.h"
#include "../FluentUiUtils/FluLogUtils.h"
class FluComboBoxDemo : public QWidget
{
    Q_OBJECT
  public:
    FluComboBoxDemo(QWidget* widget = nullptr) : QWidget(widget)
    {
        FluComboBox* comboBox = new FluComboBox(this);
        QList<QString> items = {" shoko 🥰 ", "西宫硝子 ", "aiko-----------", "柳井爱子"};
        comboBox->addItems(items);
        comboBox->setCurrentIndex(0);
        connect(comboBox, &FluComboBox::currentTextChanged, [=](QString text) { LogDebug << "current Text:" << text; });
        comboBox->move(200, 200);

        resize(500, 500);
        setStyleSheet("FluComboBoxDemo{background:white;}");
    }
};
