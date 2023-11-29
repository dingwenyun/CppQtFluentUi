#pragma once

#include <QCheckBox>

#include "FluDef.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"

class FluCheckBox : public QCheckBox
{
    Q_OBJECT
  public:
    FluCheckBox(QWidget* parent = nullptr) : QCheckBox(parent)
    {
        QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluCheckBox.qss");
        setStyleSheet(qss);
    }

    FluCheckBox(QString text, QWidget* parent)
    {
        QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluCheckBox.qss");
        setStyleSheet(qss);
        setText(text);
    }
};
