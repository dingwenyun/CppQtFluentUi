#include "FluRadioButton.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"

FluRadioButton::FluRadioButton(QWidget* parent /*= nullptr*/) : QRadioButton(parent)
{
    QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluRadioButton.qss");
    setStyleSheet(qss);
}

FluRadioButton::FluRadioButton(QString text, QWidget* parent /*= nullptr*/) : FluRadioButton(parent)
{
    setText(text);
}
