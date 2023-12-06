#pragma once

#include "FluPushButton.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"

class FluPrimaryPushButton : public FluPushButton
{
    Q_OBJECT
  public:
    FluPrimaryPushButton(QWidget* parent) : FluPushButton(parent)
    {
       QString qss =  FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluPrimaryPushButton.qss");
       setStyleSheet(qss);
    }
    FluPrimaryPushButton(QString text, QWidget* parent = nullptr, QIcon icon = QIcon()) : FluPushButton(text, parent, icon)
    {
        QString qss = FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluPrimaryPushButton.qss");
        setStyleSheet(qss);
    }
};