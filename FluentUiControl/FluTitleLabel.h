#pragma once

#include "FluLabelBase.h"
#include "../FluentUiUtils/FluFontUtils.h"

class FluTitleLabel : public FluLabelBase
{
  public:
    FluTitleLabel(QWidget* parent = nullptr);

    FluTitleLabel(QString text, QWidget* parent = nullptr);

    QFont _getFont()
    {
        return FluFontUtils::getFont(28, QFont::DemiBold);
    }
};