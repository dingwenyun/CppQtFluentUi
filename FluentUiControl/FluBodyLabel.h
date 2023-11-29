#pragma once

#include "FLuLabelBase.h"
#include "../FluentUiUtils/FluFontUtils.h"

class FluBodyLabel : public FluLabelBase
{
  public:
    FluBodyLabel(QWidget* parent = nullptr);

    FluBodyLabel(QString text, QWidget* parent = nullptr);

    QFont _getFont();
};