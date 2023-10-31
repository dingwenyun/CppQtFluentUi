#include "FluTitleLabel.h"

FluTitleLabel::FluTitleLabel(QWidget* parent /*= nullptr*/) : FluLabelBase(parent)
{
    setFont(_getFont());
}

FluTitleLabel::FluTitleLabel(QString text, QWidget* parent /*= nullptr*/) : FluTitleLabel(parent)
{
    setText(text);
}
