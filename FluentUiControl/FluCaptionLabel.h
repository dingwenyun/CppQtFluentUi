#pragma once

#include "FluLabelBase.h"
#include "../FluentUiUtils/FluentUiFontUtils.h"

class FluCaptionLabel : public FluLabelBase
{
    // Q_OBJECT
  public:
    FluCaptionLabel(QWidget* parent = nullptr);

    FluCaptionLabel(QString text, QWidget* parent = nullptr);

    QFont _getFont();
};