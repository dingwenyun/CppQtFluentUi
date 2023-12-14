#include "FluInfoBar.h"
#include "FluInfoBarManager.h"

FluInfoBar::FluInfoBar(FluAwesomeType awesomeType, QString context, bool bClosable /*= true*/, int duration /*= 1000*/, FluInfoBarPositon position /*= FluInfoBarPositon::TOP*/, QWidget *parent /*= nullptr*/) : QFrame(parent)
{
    m_awesomeType = awesomeType;
    m_context = context;
    m_duration = duration;
    m_bClosable = bClosable;
    m_positon = position;

    m_hBoxLayout = new QHBoxLayout(this);
    setLayout(m_hBoxLayout);

    m_contextLabel = new QLabel(this);
    m_contextLabel->setText(context);
    m_closeButton = new FluTransparentToolButton(this, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::ChromeClose));
    m_iconWidget = new FluInfoBarIconWidget(awesomeType, this);

    m_opacityEffect = new QGraphicsOpacityEffect(this);
    m_opacityAni = new QPropertyAnimation(m_opacityEffect, "opacity", this);

    //setProperty("type", "Success");

    __initWidget();
    __initLayout();
    __setQss();
}

void FluInfoBar::__initWidget()
{
    m_opacityEffect->setOpacity(1);
    setGraphicsEffect(m_opacityEffect);

    m_iconWidget->setFixedSize(28, 28);
    m_closeButton->setFixedSize(28, 28);
    m_closeButton->setIconSize(QSize(12, 12));
    m_closeButton->setVisible(m_bClosable);
    m_contextLabel->setWordWrap(true);
    m_contextLabel->adjustSize();
    resize(300, 40);
}

void FluInfoBar::__initLayout()
{
    m_hBoxLayout->setContentsMargins(6, 6, 6, 6);
    m_hBoxLayout->addWidget(m_iconWidget, 0, Qt::AlignHCenter);
    m_hBoxLayout->addWidget(m_contextLabel, 1);
    m_hBoxLayout->addWidget(m_closeButton, 0, Qt::AlignRight | Qt::AlignTop);
}

void FluInfoBar::__setQss()
{
    m_contextLabel->setObjectName("contextLabel");
    QString qss = FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluInfoBar.qss");
    setStyleSheet(qss);
}

void FluInfoBar::__fadeOut()
{
    m_opacityAni->setDuration(200);
    m_opacityAni->setStartValue(1);
    m_opacityAni->setEndValue(0);
    connect(m_opacityAni, &QPropertyAnimation::finished, this, &FluInfoBar::close);
    m_opacityAni->start();
}

void FluInfoBar::closeEvent(QCloseEvent *event)
{
    QFrame::closeEvent(event);
    emit closeSignal();
    deleteLater();
}

void FluInfoBar::showEvent(QShowEvent *event)
{
    QFrame::showEvent(event);
    if (m_duration > 0)
    {
        QTimer::singleShot(m_duration, this, &FluInfoBar::__fadeOut);
    }

    if (m_positon != FluInfoBarPositon::NONE)
    {
        FluInfoBarManagers::addInfoBar(this, m_positon);
    }
}
