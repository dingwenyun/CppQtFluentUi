#include "FluMainWidget.h"
#include "FluLabel.h"
#include "FluLinkCardWidget.h"
#include "FluSampleCardView.h"
#include "FluSampleCard.h"
#include "FluHomeInterface.h"

FluMainWidget::FluMainWidget(QWidget* parent /*= nullptr*/, QWidget* centerWidget /*= nullptr*/) : FluFrameLessWidgetV1(parent, centerWidget)
{
    // 设置水平布局
    m_hLayout = new QHBoxLayout(m_centerWidget);
    m_centerWidget->setLayout(m_hLayout);
    m_centerWidget->setMouseTracking(true);

    m_hLayout->setContentsMargins(0, 0, 0, 0);
    m_stackLayout = new QStackedLayout(m_centerWidget);
    m_navigationInterface = new FluNavigationInterface(m_centerWidget, true, true);
    m_hLayout->addWidget(m_navigationInterface, 0);
    m_hLayout->addLayout(m_stackLayout, 1);

    // 手动添加第一个页面
    FluHomeInterface* homeInterFace = new FluHomeInterface(m_centerWidget);
    m_stackLayout->addWidget(homeInterFace);
}
