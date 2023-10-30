#pragma once

#include "FluLabelBase.h"
#include "../FluentUiUtils/FluentUiFontUtils.h"

class FluDisplayLabel : public FluLabelBase
{
  public:
    FluDisplayLabel(QWidget* parent = nullptr);

    FluDisplayLabel(QString text, QWidget* parent = nullptr);

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(68, QFont::DemiBold);
    }
};