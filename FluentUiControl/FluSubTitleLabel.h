#include "FluLabelBase.h"
#include "../FluentUiUtils/FluFontUtils.h"

class FluSubTitleLabel : public FluLabelBase
{
  public:
    FluSubTitleLabel(QWidget* parent = nullptr);

    FluSubTitleLabel(QString text, QWidget* parent = nullptr);

    QFont _getFont()
    {
        return FluFontUtils::getFont(20, QFont::DemiBold);
    }
};