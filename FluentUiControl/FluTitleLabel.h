#pragma once

#include "FluLabelBase.h"
#include "../FluentUiUtils/FluentUiFontUtils.h"

class FluTitleLabel : public FluLabelBase
{
  public:
    FluTitleLabel(QWidget* parent = nullptr);

    FluTitleLabel(QString text, QWidget* parent = nullptr) : FluTitleLabel(parent)
    {
        setText(text);
    }

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(28, QFont::DemiBold);
    }
};