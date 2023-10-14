#pragma once

#include "FluToolTip.h"
#include "FluNavigationWidget.h"

class FluNavigationToolTipFilter : public FluToolTipFilter
{
  public:
    FluNavigationToolTipFilter(QWidget* parent = nullptr, int showDelay = 300, FluToolTipPositon position = FluToolTipPositon::TOP) : FluToolTipFilter(parent, showDelay, position)
    {
    }

  public:
    bool _canShowToolTip();
};
