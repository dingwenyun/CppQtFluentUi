#include "FluTitleLabel.h"

FluTitleLabel::FluTitleLabel(QWidget* parent /*= nullptr*/) : FluLabelBase(parent)
{
    setFont(_getFont());
}
