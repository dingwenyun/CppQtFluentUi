#include "FluSampleCardView.h"
#include "FluSampleCard.h"
#include <QDebug>
#include <QStyleOption>
#include <QPainter>
#include <QStyle>
#include "../FluentUiUtils/FluStyleSheetUitls.h"

FluSampleCardView::FluSampleCardView(QWidget* parent /*= nullptr*/, QString title /*= ""*/) : QWidget(parent)
{
    m_titleLabel = new QLabel(this);
    m_titleLabel->setText(title);
    m_titleLabel->setObjectName("viewTitleLabel");

    m_vLayout = new QVBoxLayout();
    m_flowLayout = new FluFlowLayout();

    m_vLayout->setContentsMargins(36, 0, 36, 0);
    m_vLayout->setSpacing(10);

    m_flowLayout->setContentsMargins(0, 0, 0, 0);

    m_vLayout->addWidget(m_titleLabel);
    m_vLayout->addLayout(m_flowLayout);
    m_vLayout->addStretch(1);
    setLayout(m_vLayout);

    QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluSampleCardView.qss");
    setStyleSheet(qss);
}

void FluSampleCardView::resizeEvent(QResizeEvent* event)
{
    // qDebug() << __FUNCTION__ << __LINE__ << "width:" << width() << "height:" << height() << "\n";
}

void FluSampleCardView::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}

void FluSampleCardView::addSampleCard(QPixmap img, QString title, QString content, QString routeKey, int index)
{
    FluSampleCard* card = new FluSampleCard(this, img, title, content, routeKey, index);
    m_flowLayout->addWidget(card);
}
