#include "FluNavigationInterface.h"

FluNavigationInterface::FluNavigationInterface(QWidget* parent /*= nullptr*/, bool bShowMenuButton /*= true*/, bool bShowReturnButton /*= false*/, bool bCollapsible /*= true*/)
	: QWidget(parent)
{
	setMouseTracking(true);
	m_hLayout = new QHBoxLayout(this);
	setLayout(m_hLayout);

	m_hLayout->setContentsMargins(0, 0, 0, 0);
	m_panel = new FluNavigationPanel(this);
	m_hLayout->addWidget(m_panel);
	
	
//	m_panel->setMenuButtonVisible(bShowMenuButton && bCollapsible);
//	m_panel->setReturnButtonVisible(bShowReturnButton);
//	m_panel->setCollapsible(bCollapsible);
	m_panel->installEventFilter(this);

	//todo display mode change
//	setMinimumWidth(48);
	resize(48, height());
	setAttribute(Qt::WA_TranslucentBackground);
	//setWindowFlag(Qt::FramelessWindowHint);

	//setAttribute(Qt::WA_StyledBackground);
	//setStyleSheet("background-color:pink;");
	//setStyleSheet("background-color:red;");// 样式表未生效

	LogDebug << "w:" << width() << ",h:" << height();
}
