#pragma once

#include <QFrame>
#include "FluDef.h"
#include "FluTransparentToolButton.h"
#include "FluInfoBarIconWidget.h"
#include <QHBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include <QTimer>
#include "FluInfoBarManager.h"

enum class FluInfoBarPositon
{
	NONE,
	TOP,
	BOTTOM,
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT,
};

// CompletedSolid
// InfoSolid
// InfoSolid
// StatusErrorFull
class FluInfoBar : public QFrame
{
	Q_OBJECT
  public:
    FluInfoBar(FluAwesomeType awesomeType, QString context, bool bClosable = true, int duration = 1000, FluInfoBarPositon position = FluInfoBarPositon::TOP, QWidget* parent = nullptr) 
		: QFrame(parent)
    {
        // 成员变量赋值
        m_awesomeType = awesomeType;
        m_context = context;
        m_duration = duration;
        m_bClosable = bClosable;
        m_positon = position;

        m_hBoxLayout = new QHBoxLayout(this);
        setLayout(m_hBoxLayout);
        m_contextLabel = new QLabel(this);
        m_closeButton = new FluTransparentToolButton(this, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::ChromeClose));
        m_iconWidget = new FluInfoBarIconWidget(awesomeType, this);

        m_opacityEffect = new QGraphicsOpacityEffect(this);
        m_opacityAni = new QPropertyAnimation(m_opacityEffect, "opacity", this);

        __initWidget();
        __initLayout();
        __setQss();

    }

    void __initWidget()
    {
        m_opacityEffect->setOpacity(1);
        setGraphicsEffect(m_opacityEffect);

        m_closeButton->setFixedSize(36, 36);
        m_closeButton->setIconSize(QSize(12, 12));
        m_closeButton->setVisible(m_bClosable);
    }

    void __initLayout()
    {
        m_hBoxLayout->setContentsMargins(6, 6, 6, 6);
        m_hBoxLayout->addWidget(m_iconWidget, 0);
        m_hBoxLayout->addWidget(m_contextLabel, 1);
        m_hBoxLayout->addWidget(m_closeButton, 0, Qt::AlignRight | Qt::AlignTop);
     }


    void __setQss()
    {
        m_contextLabel->setObjectName("contextLabel");
        QString qss = FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluInfoBar.qss");
        setStyleSheet(qss);
    }

    void __fadeOut()
    {
        m_opacityAni->setDuration(200);
        m_opacityAni->setStartValue(1);
        m_opacityAni->setEndValue(0);
        connect(m_opacityAni, &QPropertyAnimation::finished, this, &FluInfoBar::close);
        m_opacityAni->start();
    }

  protected:
    void closeEvent(QCloseEvent *event)
    {
        QFrame::closeEvent(event);
        emit closeSignal();
        deleteLater();
    }

    void showEvent(QShowEvent *event)
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

  signals:
    void closeSignal();
  private:
  //  QString m_title; // 去掉title
    QString m_context;
    int m_duration;
    FluInfoBarPositon m_positon;

//	QLabel *m_titleLabel;
    QLabel* m_contextLabel;

    FluInfoBarIconWidget* m_iconWidget;
	FluTransparentToolButton* m_closeButton;
    bool m_bClosable;// 是否可以关闭

    FluAwesomeType m_awesomeType;
	QHBoxLayout* m_hBoxLayout;

    QGraphicsOpacityEffect* m_opacityEffect;
    QPropertyAnimation* m_opacityAni;
};
