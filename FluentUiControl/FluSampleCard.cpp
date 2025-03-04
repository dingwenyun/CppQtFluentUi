#include "FluSampleCard.h"
#include <QStyle>
#include <QPainter>
#include <QStyleOption>
#include "../FluentUiUtils/FluStyleSheetUitls.h"

FluSampleCard::FluSampleCard(QWidget* parent /*= nullptr*/, QPixmap img /*= QPixmap()*/, QString title /*= ""*/, QString content /*= ""*/, QString routeKey /*= ""*/, int index /*= -1*/) : QWidget(parent), m_routeKey(routeKey), m_index(index)
{
    m_imgWidget = new FluImgWidget(this, img);
    m_titleLabel = new QLabel(title);
    m_contentLabel = new QLabel(content);

    m_vLayout = new QVBoxLayout();

    m_hLayout = new QHBoxLayout();  // layout一般不指定父窗口
    setLayout(m_hLayout);           // 设置窗口为左右布局

    m_titleLabel->setWordWrap(true);  //
    m_contentLabel->setWordWrap(true);

    m_imgWidget->setFixedSize(48, 48);
    setFixedSize(360, 90);

    m_hLayout->setSpacing(28);
    m_hLayout->setContentsMargins(20, 0, 0, 0);
    m_vLayout->setSpacing(2);
    m_vLayout->setContentsMargins(0, 0, 0, 0);
    m_vLayout->setAlignment(Qt::AlignVCenter);
    m_hLayout->setAlignment(Qt::AlignVCenter);

    m_hLayout->addWidget(m_imgWidget);  // 设置窗口的图片左边
    m_hLayout->addLayout(m_vLayout);
    m_vLayout->addStretch(1);
    m_vLayout->addWidget(m_titleLabel);    // 右上部分：标题
    m_vLayout->addWidget(m_contentLabel);  // 右下部分:描述内容
    m_vLayout->addStretch(1);

    m_titleLabel->setObjectName("titleLabel");
    m_contentLabel->setObjectName("contentLabel");
}

void FluSampleCard::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget::mouseReleaseEvent(event);
    emit swithSampleCard(m_routeKey, m_index);
}

void FluSampleCard::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);

    QStyleOption opt;
    opt.initFrom(this);
    QPainter painter(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
}
