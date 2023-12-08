#include "FluMessageBox.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"

FluMessageBox::FluMessageBox(QString title, QString content, QWidget* parent /*= nullptr*/) : FluMaskDialog(parent)
{
    setupUi(title, content, m_widget);
    // LogDebug << "centerWidget w: " << m_widget->width() << "h: " << m_widget->height();
    setShadowEffect(60, QPoint(0, 10), QColor(0, 0, 0, 50));
    setMaskColor(QColor(0, 0, 0, 76));
}

void FluMessageBox::setupUi(QString title, QString content, QWidget* parent)
{
    __initWidget(title, content, parent);
    __initLayout();
    __setQss();
    __setConnect();
}

void FluMessageBox::__initWidget(QString title, QString content, QWidget* parent)
{
    m_titleLabel = new QLabel(title, parent);
    m_contentLabel = new QLabel(content, parent);
    m_yesButton = new FluPrimaryPushButton("确定");
    m_noButton = new FluPushButton("取消");
    m_vBoxLayout = new QVBoxLayout(parent);
    m_hBtnLayout = new QHBoxLayout();

    m_titleLabel->setWordWrap(true);
    m_contentLabel->setWordWrap(true);
}

void FluMessageBox::__initLayout()
{
    //标题
    m_vBoxLayout->setContentsMargins(24, 24, 24, 24);
    m_vBoxLayout->addWidget(m_titleLabel);

    // 内容
    m_vBoxLayout->addWidget(m_contentLabel);

    // 按钮
    m_hBtnLayout->addWidget(m_yesButton);
    m_hBtnLayout->addWidget(m_noButton);
    //  m_hBtnLayout->setContentsMargins(24, 24, 24, 24);
    m_vBoxLayout->addLayout(m_hBtnLayout);
}

void FluMessageBox::__setQss()
{
    m_titleLabel->setObjectName("titleLabel");
    m_contentLabel->setObjectName("contentLabel");
    m_yesButton->setObjectName("yesButton");
    m_noButton->setObjectName("noButton");

    QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluMessageBox.qss");
    setStyleSheet(qss);
}

void FluMessageBox::__setConnect()
{
    connect(m_yesButton, &QPushButton::clicked, this, &FluMessageBox::__onYesButtonClicked);
    connect(m_noButton, &QPushButton::clicked, this, &FluMessageBox::__onCancelButtonClicked);
}
