#pragma once

#include "FluDef.h"
#include "FluPushButton.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"

class FluTransparentPushButton : public FluPushButton
{
    Q_OBJECT
  public:
    FluTransparentPushButton(QWidget* parent) : FluPushButton(parent)
    {
        // FluSetStyleSheet(FluTransparentPushButton);
        QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluTransparentPushButton.qss");
        setStyleSheet(qss);
    }

    FluTransparentPushButton(QString text, QWidget* parent = nullptr, QIcon icon = QIcon()) : FluPushButton(text, parent, icon)
    {
        // FluSetStyleSheet(FluTransparentPushButton);
        QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluTransparentPushButton.qss");
        setStyleSheet(qss);
    }
};