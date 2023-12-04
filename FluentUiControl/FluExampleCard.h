#pragma once

#include <QWidget>
#include "FluBodyLabel.h"
#include "FluStrongBodyLabel.h"
#include <QFrame>
#include "FluIconWidget.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include <QEvent>
#include <QMouseEvent>
#include <QDesktopServices>

class FluExampleCard : public QWidget
{
    Q_OBJECT
  public:
    FluExampleCard(QString title, QWidget* widget, QString sourcePath, int stretch = 0, QWidget* parent = nullptr) : QWidget(parent)
    {
        m_Widget = widget;
        m_stretch = stretch;

        m_titleLabel = new FluStrongBodyLabel(title, this);

        m_card = new QFrame(this);
        m_sourceWidget = new QFrame(m_card); 
        m_sourcePath = sourcePath;

        m_sourcePathLabel = new FluBodyLabel("源代码", m_sourceWidget);
        m_linkIcon = new FluIconWidget(FluAwesomeType::OpenInNewWindow, m_sourceWidget);

        m_vBoxLayout = new QVBoxLayout(this);
        m_vCardLayout = new QVBoxLayout(m_card);
        m_hTopLayout = new QHBoxLayout();
        m_hBottomLayout = new QHBoxLayout(m_sourceWidget);

        __initWidget();
    }

    void __initWidget()
    {
        m_linkIcon->setFixedSize(16, 16);
        __initLayout();

        m_sourceWidget->setCursor(Qt::PointingHandCursor);
        m_sourceWidget->installEventFilter(this);

        m_card->setObjectName("card");
        m_sourceWidget->setObjectName("sourceWidget");
    }

    void __initLayout()
    {
        m_vBoxLayout->setSizeConstraint(QVBoxLayout::SetMinAndMaxSize);
        m_vCardLayout->setSizeConstraint(QVBoxLayout::SetMinAndMaxSize);
        m_hTopLayout->setSizeConstraint(QHBoxLayout::SetMinAndMaxSize);

        m_vBoxLayout->setSpacing(12);
        m_vBoxLayout->setContentsMargins(0, 0, 0, 0);
        m_hTopLayout->setContentsMargins(12, 12, 12, 12);
        m_hBottomLayout->setContentsMargins(18, 18, 18, 18);
        m_vCardLayout->setContentsMargins(0, 0, 0, 0);

        m_vBoxLayout->addWidget(m_titleLabel, 0, Qt::AlignTop); // 标题
        m_vBoxLayout->addWidget(m_card, 0, Qt::AlignTop);       // 卡片
        m_vBoxLayout->setAlignment(Qt::AlignTop);

        m_vCardLayout->setSpacing(0);
        m_vCardLayout->setAlignment(Qt::AlignTop);
        m_vCardLayout->addLayout(m_hTopLayout, 0);
        m_vCardLayout->addWidget(m_sourceWidget, 0, Qt::AlignBottom);

        m_Widget->setParent(m_card);
        m_hTopLayout->addWidget(m_Widget);

        if (m_stretch == 0)
            m_hTopLayout->addStretch(1);

        m_Widget->show();
        m_hBottomLayout->addWidget(m_sourcePathLabel, 0, Qt::AlignLeft);// 底部标签
        m_hBottomLayout->addStretch(1);
        m_hBottomLayout->addWidget(m_linkIcon, 0, Qt::AlignRight);// 设置链接标签右部
        m_hBottomLayout->setAlignment(Qt::AlignLeft | Qt::AlignCenter);
    }

  protected:
    bool eventFilter(QObject* watched, QEvent* event)
    {
        if ((QWidget*)watched == (QWidget*)m_sourceWidget && event->type() == QEvent::MouseButtonRelease)
        {
            QDesktopServices::openUrl(QUrl(m_sourcePath));
        }
        return QWidget::eventFilter(watched, event);
    }

  private:
    QWidget* m_Widget;
    FluStrongBodyLabel* m_titleLabel;
    QFrame* m_card;

    QFrame* m_sourceWidget;
    QString m_sourcePath;
    FluBodyLabel* m_sourcePathLabel;

    FluIconWidget* m_linkIcon;
    QVBoxLayout* m_vBoxLayout;
    QVBoxLayout* m_vCardLayout;
    QHBoxLayout* m_hTopLayout;
    QHBoxLayout* m_hBottomLayout;

    int m_stretch;
};
