#include "FluSubTitleLabel.h"
FluSubTitleLabel::FluSubTitleLabel(QWidget* parent /*= nullptr*/) : FluLabelBase(parent)
{
    setFont(_getFont());
}

FluSubTitleLabel::FluSubTitleLabel(QString text, QWidget* parent /*= nullptr*/) : FluSubTitleLabel(parent)
{
    setText(text);
}
