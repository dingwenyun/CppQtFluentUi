#include "FluLabelBase.h"
#include "../FluentUiUtils/FluentUiFontUtils.h"

class FluSubTitleLabel : public FluLabelBase
{
  public:
    FluSubTitleLabel(QWidget* parent = nullptr);

    FluSubTitleLabel(QString text, QWidget* parent = nullptr);

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(20, QFont::DemiBold);
    }
};