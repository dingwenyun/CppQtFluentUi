#include "FluBannerWidget.h"
#include <QPainter>
#include <QPainterPath>

FluBannerWidget::FluBannerWidget(QWidget* parent /*= nullptr*/) : QWidget(parent)
{
    setFixedHeight(360);
    m_vLayout = new QVBoxLayout(this);
    m_galleryLabel = new QLabel("FluentUI Gallery", this);
    //	m_galleryLabel->setStyleSheet("font: 42px 'Segoe UI', 'Microsoft YaHei';font-weight: bold;background-color: transparent;color: black;padding-left: 28px;");
    m_img = QPixmap("../res/bg_home_header.png");

    m_linkCardView = new FluLinkCardView(this);
    m_galleryLabel->setObjectName("galleryLabel");

    m_vLayout->setSpacing(0);
    m_vLayout->setContentsMargins(0, 20, 0, 20);
    m_vLayout->addWidget(m_galleryLabel);
    m_vLayout->addWidget(m_linkCardView, 1, Qt::AlignBottom);
    m_vLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    m_linkCardView->addCard(QPixmap("../res/logo.png"), "Getting started", "An overview of app development options and samples.", "");
    m_linkCardView->addCard(QPixmap("../res/ic_home_github.png"), "Github repo", "The latest FluentUI controls and styles for your applications.", "https://github.com/mowangshuying/CppQtFluentUI");
}

void FluBannerWidget::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHints(QPainter::SmoothPixmapTransform | QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);

    m_img.scaled(rect().width(), rect().height());
    painter.drawPixmap(rect(), m_img);
}
