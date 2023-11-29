#pragma once

#include "FluLabelBase.h"
#include "../FluentUiUtils/FluFontUtils.h"

class FluDisplayLabel : public FluLabelBase
{
  public:
    FluDisplayLabel(QWidget* parent = nullptr);

    FluDisplayLabel(QString text, QWidget* parent = nullptr);

    QFont _getFont()
    {
        return FluFontUtils::getFont(68, QFont::DemiBold);
    }
};