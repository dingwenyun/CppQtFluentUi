#include "FluDisplayLabel.h"

FluDisplayLabel::FluDisplayLabel(QWidget* parent /*= nullptr*/) : FluLabelBase(parent)
{
    setFont(_getFont());
}

FluDisplayLabel::FluDisplayLabel(QString text, QWidget* parent /*= nullptr*/) : FluDisplayLabel(parent)
{
    setText(text);
}
