#include "FluSubTitleLabel.h"
FluSubTitleLabel::FluSubTitleLabel(QWidget* parent /*= nullptr*/) : FluLabelBase(parent)
{
    setFont(_getFont());
}
