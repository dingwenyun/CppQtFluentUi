#pragma once

#include <QString>
#include "FluNavigationWidget.h"

class FluNavigationItem
{
public:
	FluNavigationItem(QString routeKey, QString parentRouteKey, FluNavigationWidget* widget)
		: m_routeKey(routeKey), m_parentRouteKey(parentRouteKey), m_widget(widget)
	{

	}
public:
	QString m_routeKey;
	QString m_parentRouteKey;
	FluNavigationWidget* m_widget;
};

