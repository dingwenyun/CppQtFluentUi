#include "FluLabelBase.h"
#include "../FluentUiUtils/FluentUiFontUtils.h"

class FluSubTitleLabel : public FluLabelBase
{
  public:
    FluSubTitleLabel(QWidget* parent = nullptr) : FluLabelBase(parent)
    {
        setFont(_getFont());
    }

    FluSubTitleLabel(QString text, QWidget* parent = nullptr) : FluSubTitleLabel(parent)
    {
        setText(text);
    }

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(20, QFont::DemiBold);
    }
};