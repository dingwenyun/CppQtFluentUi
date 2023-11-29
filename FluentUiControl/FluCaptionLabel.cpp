#include "FluCaptionLabel.h"

FluCaptionLabel::FluCaptionLabel(QWidget* parent /*= nullptr*/) : FluLabelBase(parent)
{
    setFont(_getFont());
}

FluCaptionLabel::FluCaptionLabel(QString text, QWidget* parent /*= nullptr*/) : FluCaptionLabel(parent)
{
    setText(text);
}

QFont FluCaptionLabel::_getFont()
{
    return FluFontUtils::getFont(12);
}
