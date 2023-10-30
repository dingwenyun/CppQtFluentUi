#include "FluBodyLabel.h"

FluBodyLabel::FluBodyLabel(QWidget* parent /*= nullptr*/) : FluLabelBase(parent)
{
    setFont(_getFont());
}

FluBodyLabel::FluBodyLabel(QString text, QWidget* parent /*= nullptr*/) : FluBodyLabel(parent)
{
    setText(text);
}

QFont FluBodyLabel::_getFont()
{
    return FluentUiFontUtils::getFont(14);
}
