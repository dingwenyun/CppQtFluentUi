#pragma once

#include <QObject>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class FluUiMessBox : public QObject
{
	Q_OBJECT
  public:

signals:
    void yesSignal();
    void noSignal();

  public:
    void setupUi(QString title, QString content, QWidget* parent)
    {
        __initWidget(title, content, parent);
        __initLayout();
        __setQss();
        __setConnect();
    }

    void __initWidget(QString title, QString content, QWidget* parent)
    {
        m_titleLabel = new QLabel(title);
        m_contentLabel = new QLabel(content);
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

    void __setConnect()
    {
        connect(m_yesButton, &QPushButton::clicked, this, &FluUiMessBox::__onYesButtonClicked);
        connect(m_noButton, &QPushButton::clicked, this, &FluUiMessBox::__onCancelButtonClicked);
    }

    void __onCancelButtonClicked()
    {
        emit noSignal();
    }

    void __onYesButtonClicked()
    {
        emit yesSignal();
    }


  private:
    QLabel* m_titleLabel;
    QLabel* m_contentLabel;

    QPushButton* m_yesButton;
    QPushButton* m_noButton;

    QVBoxLayout* m_vBoxLayout;
    QHBoxLayout* m_hBtnLayout;
};
