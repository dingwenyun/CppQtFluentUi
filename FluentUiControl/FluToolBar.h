#pragma once

#include <QWidget>
#include "FluLabel.h"
#include "FluButton.h"
#include "FluSeparator.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include "FluToolTip.h"

#include <QVBoxLayout>
#include <QHBoxLayout>

class FluToolBar : public QWidget
{
  public:
    FluToolBar(QString title, QString subTitle, QWidget* parent = nullptr) : QWidget(parent)
    {
        m_titleLabel = new FluTitleLabel(title, this);
        m_subTitleLabel = new FluSubTitleLabel(subTitle, this);

        m_documentButton = new FluPushButton("在线文档",this, FluIconUtils::GetFluentIcon(FluAwesomeType::Document));
        m_sourceButton = new FluPushButton("源代码", this, FluIconUtils::GetFluentIcon(FluAwesomeType::Code));
        m_themeButton = new FluPushButton("", this, FluIconUtils::GetFluentIcon(FluAwesomeType::Light));// 主题色按钮
        m_separator = new FluSeparator(FluSeparatorDirection::Vertical, this);
        m_supportButton = new FluPushButton("", this, FluIconUtils::GetFluentIcon(FluAwesomeType::Heart));
        m_feedbackButton = new FluPushButton("", this, FluIconUtils::GetFluentIcon(FluAwesomeType::Feedback));

        m_vBoxLayout = new QVBoxLayout(this);
        m_hButtonBoxLayout = new QHBoxLayout();

        __initWidget();
    }

    void __initWidget()
    {
        setFixedHeight(138);
        m_vBoxLayout->setSpacing(0);
        m_vBoxLayout->setContentsMargins(36, 22, 36, 12);
        m_vBoxLayout->addWidget(m_titleLabel);
        m_vBoxLayout->addSpacing(4);
        m_vBoxLayout->addWidget(m_subTitleLabel);
        m_vBoxLayout->addSpacing(4);
        m_vBoxLayout->addLayout(m_hButtonBoxLayout, 1);
        m_vBoxLayout->setAlignment(Qt::AlignTop);

        m_hButtonBoxLayout->setSpacing(4);
        m_hButtonBoxLayout->setContentsMargins(0, 0, 0, 0);
        m_hButtonBoxLayout->addWidget(m_documentButton, 0, Qt::AlignLeft);
        m_hButtonBoxLayout->addWidget(m_sourceButton, 0, Qt::AlignLeft);
        m_hButtonBoxLayout->addStretch(1);
        m_hButtonBoxLayout->addWidget(m_themeButton, 0, Qt::AlignRight);
        m_hButtonBoxLayout->addWidget(m_separator, 0, Qt::AlignRight);
        m_hButtonBoxLayout->addWidget(m_supportButton, 0, Qt::AlignRight);
        m_hButtonBoxLayout->addWidget(m_feedbackButton, 0, Qt::AlignRight);
        m_hButtonBoxLayout->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

        m_themeButton->installEventFilter(new FluToolTipFilter(m_themeButton));
        m_supportButton->installEventFilter(new FluToolTipFilter(m_supportButton));
        m_feedbackButton->installEventFilter(new FluToolTipFilter(m_feedbackButton));

        m_themeButton->setToolTip("主题");
        m_supportButton->setToolTip("支持我");
        m_feedbackButton->setToolTip("反哺");

        // connect
    }

  private:
    FluTitleLabel* m_titleLabel;
    FluSubTitleLabel* m_subTitleLabel;
    FluPushButton* m_documentButton;
    FluPushButton* m_sourceButton;
    FluPushButton* m_themeButton;
    FluSeparator* m_separator;
    FluPushButton* m_supportButton;
    FluPushButton* m_feedbackButton;
    QVBoxLayout* m_vBoxLayout;
    QHBoxLayout* m_hButtonBoxLayout;
};
