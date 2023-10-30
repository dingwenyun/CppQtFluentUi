#include "FluLargeTitleLabel.h"

FluLargeTitleLabel::FluLargeTitleLabel(QWidget* parent /*= nullptr*/) : FluLabelBase(parent)
{
    setFont(_getFont());
}

FluLargeTitleLabel::FluLargeTitleLabel(QString text, QWidget* parent /*= nullptr*/) : FluLargeTitleLabel(parent)
{
    setText(text);
}
