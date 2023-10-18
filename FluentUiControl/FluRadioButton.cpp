#include "FluRadioButton.h"
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"

FluRadioButton::FluRadioButton(QWidget* parent /*= nullptr*/) : QRadioButton(parent)
{
    QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluRadioButton.qss");
    setStyleSheet(qss);
}

FluRadioButton::FluRadioButton(QString text, QWidget* parent /*= nullptr*/) : FluRadioButton(parent)
{
    setText(text);
}
