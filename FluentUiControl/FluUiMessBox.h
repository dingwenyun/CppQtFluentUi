#pragma once

#include <QObject>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "../FluentUiUtils/FluLogUtils.h"

class FluUiMessBox : public QObject
{
    Q_OBJECT
  public:
  signals:
    void yesSignal();
    void noSignal();

  public:
      // parent为顶层窗口
    void setupUi(QString title, QString content, QWidget* parent)
    {
        __initWidget(title, content, parent);
        __initLayout();
        __setQss();
       // __setConnect();
    }

    void __initWidget(QString title, QString content, QWidget* parent)
    {
        m_titleLabel = new QLabel(title, parent);
        m_contentLabel = new QLabel(content, parent);
        m_yesButton = new QPushButton("确定");
        m_noButton = new QPushButton("取消");
        m_vBoxLayout = new QVBoxLayout(parent);
        m_hBtnLayout = new QHBoxLayout();
    }

    void __initLayout()
    {
        m_vBoxLayout->addWidget(m_titleLabel);
        m_vBoxLayout->addWidget(m_contentLabel);
        m_hBtnLayout->addWidget(m_yesButton);
        m_hBtnLayout->addWidget(m_noButton);
        m_vBoxLayout->addLayout(m_hBtnLayout);
    }

    void __setQss()
    {
        m_titleLabel->setObjectName("titleLabel");
        m_contentLabel->setObjectName("contentLabel");
        m_yesButton->setObjectName("yesButton");
        m_noButton->setObjectName("noButton");
    }

  protected:
    QLabel* m_titleLabel;
    QLabel* m_contentLabel;

    QPushButton* m_yesButton;
    QPushButton* m_noButton;

    QVBoxLayout* m_vBoxLayout;
    QHBoxLayout* m_hBtnLayout;
};
