#include "FluNavigationToolTipFilter.h"

bool FluNavigationToolTipFilter::_canShowToolTip()
{
	FluNavigationWidget* widget = dynamic_cast<FluNavigationWidget*>(parent());
	return FluToolTipFilter::_canShowToolTip() && widget->getCompacted();
}
