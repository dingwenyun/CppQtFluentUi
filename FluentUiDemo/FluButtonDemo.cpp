#include "FluButtonDemo.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"

FluPushButtonDemo::FluPushButtonDemo(QWidget* parent /*= nullptr*/)
	: QWidget(parent)
{
	m_gridLayout = new QGridLayout();
	setLayout(m_gridLayout);

	m_pushBtn1 = new FluPushButton("Standard push button");
	m_pushBtn2 = new FluPushButton("Standard push button with icon", this, FluentUiIconUtils::GetFluentIcon(FluAwesomeType::Folder));

	m_gridLayout->addWidget(m_pushBtn1, 0, 0);
	m_gridLayout->addWidget(m_pushBtn2, 0, 1);

	resize(600, 400);
}

