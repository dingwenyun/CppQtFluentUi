#pragma once

#include "FluDef.h"
#include "FluNavigationPanel.h"
#include "../FluentUiUtils/FluentUiLogUtils.h"
#include <QFunctionPointer>
#include <QFrame>
#include <QStyleOption>
#include <QHBoxLayout>

class FluNavigationInterface : public QWidget
{
	Q_OBJECT
public:
	FluNavigationInterface(QWidget* parent = nullptr, bool bShowMenuButton = true, bool bShowReturnButton = false, bool bCollapsible = true);
protected:
	void resizeEvent(QResizeEvent* event)
	{
		LogDebug << "w:" << width() << ",h:" << height() << "; panel w:" << m_panel->width() << ",panel h:" << m_panel->height();
		m_panel->setFixedHeight(height());
	}

	///*void paintEvent(QPaintEvent* event)
	//{
	//	QStyleOption opt;
	//	opt.initFrom(this);
	//	QPainter painter(this);
	//	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
	//}*/
public:
	
private:
	FluNavigationPanel* m_panel;
	QHBoxLayout* m_hLayout;
};

