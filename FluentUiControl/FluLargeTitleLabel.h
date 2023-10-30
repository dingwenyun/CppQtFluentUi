#pragma once
#include "../FluentUiUtils/FluentUiFontUtils.h"
#include "FluLabelBase.h"

class FluLargeTitleLabel : public FluLabelBase
{
  public:
    FluLargeTitleLabel(QWidget* parent = nullptr);

    FluLargeTitleLabel(QString text, QWidget* parent = nullptr);

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(40, QFont::DemiBold);
    }
};