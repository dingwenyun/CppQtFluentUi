#pragma once

#include "FluDef.h"
#include <QWidget>
#include <QScrollArea>
#include <QPropertyAnimation>
#include "FluNavigationPushButton.h"
#include "FluNavigationItemLayout.h"
#include "FluNavigationHistory.h"
#include "FluNavigationToolButton.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"
#include <QPainter>
#include <QStyleOption>
#include <QFrame>

// 导航栏显示模式
enum class FluNavigationDisplayMode
{
	MINIMAL = 0,
	COMPACT,
	EXPAND,
	MENU
};

// 导航栏位置
enum class FluNavigationItemPosition
{
	TOP = 0,
	SCROLL,
	BOTTOM
};


using FluNavigationWidgetClickedCallBack = void (*)();

class FluNavigationPanel : public QFrame
{
	Q_OBJECT
public:
	FluNavigationPanel(bool bMinimalEnable = false, QWidget* parent = nullptr)
		: QFrame(parent)
	{
		m_parent = parent;
		m_bMenuButtonVisible = true;
		m_bReturnButtonVisible = false;
		m_bCollapsible = true;

		m_scrollArea = new QScrollArea(this);
		m_scrollWidget = new QWidget();

		m_menuButton = new FluNavigationToolButton(FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::GlobalNavButton), this);
		//m_returnButton = new FluNavigationToolButton(this, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::Back));
		//m_returnButton->setVisible(false);
		m_vLayout = new FluNavigationItemLayout(this);
		setLayout(m_vLayout);

		m_vTopLayout = new FluNavigationItemLayout();
		LogDebug << "vlayout size hint:" << m_vLayout->sizeHint();
		m_vBottomLayout = new FluNavigationItemLayout();
		m_vScrollLayout = new FluNavigationItemLayout(m_scrollWidget);
		LogDebug << "vScrolllayout size hint:" << m_vScrollLayout->sizeHint();

		m_expandAnimation = new QPropertyAnimation(this, "geometry", this);
		m_expandWidth = 322;

		m_bMinimalEnabled = bMinimalEnable;
		if (bMinimalEnable)
			m_displayMode = FluNavigationDisplayMode::MINIMAL;
		else
			m_displayMode = FluNavigationDisplayMode::COMPACT;

		__initWidget(parent, bMinimalEnable);
		__initLayout();
		__connect();

		//setStyleSheet("background-color: pink;");
		//setStyleSheet("background-color:red;");
	}

	void __initWidget(QWidget* parent, bool bMinimalEnable)
	{
		//resize(48, height());
		setFixedSize(48, height());

		setAttribute(Qt::WA_StyledBackground);
		window()->installEventFilter(this);

		//	LogDebug << "resize:" << "w:" << width() << ",h:" << height();

		//	m_returnButton->hide();
		//	m_returnButton->setDisabled(true);

		m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		m_scrollArea->setWidget(m_scrollWidget);
		m_scrollArea->setWidgetResizable(true);

		m_expandAnimation->setEasingCurve(QEasingCurve::OutQuad);
		m_expandAnimation->setDuration(150);

		setProperty("menu", false);
		m_scrollWidget->setObjectName("scrollWidget");

		//m_scrollWidget->resize(48, height());
		//m_scrollArea->resize(48, height());

		//FluSetStyleSheet(FluNavigationPanel);

		//QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluNavigationPanel.qss");
		//setStyleSheet(qss);

		//setStyleSheet("background-color: pink;");
		setStyleSheet("background-color:red;");

		LogDebug << "panel size:" << "w:" << width() << ",h:" << height();
		LogDebug << "scroll widget:" << "w:" << m_scrollWidget->width() << ",h:" << m_scrollWidget->height();
	}

	void __connect()
	{
		connect(m_menuButton, &FluNavigationToolButton::clicked, this, &FluNavigationPanel::toggle);
	}

	void __initLayout()
	{
		m_vLayout->setContentsMargins(0, 5, 0, 5);
		m_vTopLayout->setContentsMargins(4, 0, 4, 0);
		m_vBottomLayout->setContentsMargins(4, 0, 4, 0);
		m_vScrollLayout->setContentsMargins(4, 0, 4, 0);

		m_vLayout->setSpacing(4);
		m_vTopLayout->setSpacing(4);
		m_vScrollLayout->setSpacing(4);
		m_vBottomLayout->setSpacing(4);

		m_vLayout->addLayout(m_vTopLayout);
		m_vLayout->addWidget(m_scrollArea, 1);
		m_vLayout->addLayout(m_vBottomLayout);

		m_vLayout->setAlignment(Qt::AlignTop);
		m_vTopLayout->setAlignment(Qt::AlignTop);
		m_vScrollLayout->setAlignment(Qt::AlignTop);
		m_vBottomLayout->setAlignment(Qt::AlignBottom);

		//m_vTopLayout->addWidget(m_menuButton);
		LogDebug << "panel size:" << "w:" << width() << ",h:" << height();
	}

	void insertWidget(int index, QString routeKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack onClicked, FluNavigationItemPosition postion, QString toolTip, QString parentRouteKey)
	{
		if (routeKey.isEmpty())
			return;

		auto itf = m_items.find(routeKey);
		if (itf != m_items.end())
			return;

	}

	void registerWidget(QString routeKey, QString parentRouteKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack onClicked, QString toopTip)
	{
		//connect(widget, &FluNavigationWidget::signalClicked, nullptr, &onClicked);
		if (onClicked != nullptr)
		{

		}
	}

	void onWidgetClicked()
	{
		FluNavigationWidget* widget = dynamic_cast<FluNavigationWidget*> (sender());
		if (widget->getSelectable() == false)
			return;

		QString routeKey = widget->property("routeKey").toString();
		setCurrentItem(routeKey);


		if (widget != m_menuButton && m_displayMode == FluNavigationDisplayMode::MENU && !widget->isLeaf())
		{
			collapse();
		}
	}

	void toggle()
	{
		if (m_displayMode == FluNavigationDisplayMode::COMPACT || m_displayMode == FluNavigationDisplayMode::MINIMAL)
			expand();
		else
			collapse();
	}

	// 折叠
	void collapse()
	{

	}



	void setCurrentItem(QString routeKey)
	{
		if (routeKey.isEmpty())
			return;

		auto itf = m_items.find(routeKey);
		if (itf == m_items.end())
			return;

		itf.value()->setSelectable(true);
	}

	void addWidget(QString routeKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack callback, FluNavigationItemPosition position = FluNavigationItemPosition::TOP)
	{
		auto itf = m_items.find(routeKey);
		if (itf != m_items.end())
		{
			return;
		}

		widget->setProperty("routeKey", routeKey);
		m_items[routeKey] = widget;

		if (m_displayMode == FluNavigationDisplayMode::EXPAND || m_displayMode == FluNavigationDisplayMode::MENU)
		{
			widget->setCompacted(false);
		}

		addWidgetToLayout(widget, position);
	}

	void addWidgetToLayout(FluNavigationWidget* widget, FluNavigationItemPosition postion)
	{
		switch (postion)
		{
		case FluNavigationItemPosition::TOP:
			widget->setParent(this);
			m_vTopLayout->addWidget(widget, 0, Qt::AlignTop);
			break;
		case FluNavigationItemPosition::SCROLL:
			widget->setParent(m_scrollWidget);
			m_vScrollLayout->addWidget(widget, 0, Qt::AlignTop);
			break;
		case FluNavigationItemPosition::BOTTOM:
			widget->setParent(this);
			m_vBottomLayout->addWidget(widget, 0, Qt::AlignBottom);
			break;
		default:
			break;
		}
		widget->show();
	}

	void addItem(QString routeKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack callback, FluNavigationItemPosition position = FluNavigationItemPosition::TOP)
	{

	}

	void expand(bool bUseAni = true)
	{
		_setWidgetCompacted(false);
		m_expandAnimation->setProperty("expand", true);
		m_menuButton->setToolTip("Close Navigation");// 关闭导航栏
		//determine the display mode according to the width of window
		//https://learn.microsoft.com/en-us/windows/apps/design/controls/navigationview#default
		//int nExpandWidth = 1007 + m_expandWidth - 322;
		//if (window()->width() > nExpandWidth && !m_bMinimalEnabled && !m_bCollapsible)
		//{
		//	m_displayMode = FluNavigationDisplayMode::EXPAND;
		//}
		//else
		//{
		//	setProperty("menu", true);
		//	//setStyle(QApplication::style());
		//	m_displayMode = FluNavigationDisplayMode::MENU;
		//}

		//setExpandWidth(nExpandWidth);
		m_displayMode = FluNavigationDisplayMode::EXPAND;
		setFixedWidth(312);
	}

	void _setWidgetCompacted(bool bCompacted)
	{
		QList<FluNavigationWidget*> widgets = findChildren<FluNavigationWidget*>();
		for (auto itList = widgets.begin(); itList != widgets.end(); itList++)
		{
			(*itList)->setCompacted(bCompacted);
		}
	}

	void removeWidget(QString routeKey)
	{
		auto itf = m_items.find(routeKey);
		if (itf == m_items.end())
		{
			return;
		}

		FluNavigationWidget* widget = m_items[routeKey];
		m_items.remove(routeKey);
		widget->deleteLater();
		m_history->remove(routeKey, true);
	}

	void setMenuButtonVisible(bool bVisible)
	{
		m_bMenuButtonVisible = bVisible;
		//if(m_menuButton)
		//	m_menuButton->setVisible(bVisible);
	}

	void setReturnButtonVisible(bool bVisible)
	{
		m_bReturnButtonVisible = bVisible;
		//m_returnButton->setVisible(bVisible);
	}

	void setCollapsible(bool bOn)
	{
		m_bCollapsible = bOn;
		if (!bOn && m_displayMode != FluNavigationDisplayMode::EXPAND)
			expand(false);
	}

	void setExpandWidth(int width)
	{
		if (width <= 42)
		{
			return;
		}

		m_expandWidth = width;
		//
	}

protected:
private:
	FluNavigationDisplayMode m_displayMode;
	FluNavigationHistory* m_history;
	FluNavigationItemLayout* m_vBottomLayout;
	FluNavigationItemLayout* m_vLayout;
	FluNavigationItemLayout* m_vScrollLayout;
	FluNavigationItemLayout* m_vTopLayout;
	FluNavigationToolButton* m_menuButton;
	FluNavigationToolButton* m_returnButton;
	QMap<QString, FluNavigationWidget*> m_items;
	QPropertyAnimation* m_expandAnimation;
	QScrollArea* m_scrollArea;
	QWidget* m_parent;
	QWidget* m_scrollWidget;

	bool m_bCollapsible;
	bool m_bMenuButtonVisible;
	bool m_bMinimalEnabled;
	bool m_bReturnButtonVisible;
	int m_expandWidth;
};

