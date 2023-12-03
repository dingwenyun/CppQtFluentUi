#pragma once

#include "FluDef.h"
#include <QFrame>
#include "FluIconWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

class FluIconInfoPanel : public QFrame
{
    Q_OBJECT
  public:
    FluIconInfoPanel(FluAwesomeType type, QWidget* parent = nullptr) : QFrame(parent)
    {
        m_nameLabel = new QLabel(EnumTypeToQString(type), this);
        m_iconWidget = new FluIconWidget(type, this);
        m_iconWidget->setFixedSize(32, 32);

        m_iconNameTitleLabel = new QLabel("图标名", this);
        m_iconNameLabel = new QLabel(EnumTypeToQString(type), this);
        m_enumNameTitleLabel = new QLabel("图标枚举", this);
        m_enumNameLabel = new QLabel("FluAwesomeType::" + EnumTypeToQString(type), this);

        m_vBoxLayout = new QVBoxLayout(this);
        m_vBoxLayout->setContentsMargins(16, 20, 16, 20);
        m_vBoxLayout->setSpacing(0);
        m_vBoxLayout->setAlignment(Qt::AlignTop);

        m_vBoxLayout->addWidget(m_nameLabel);
        m_vBoxLayout->addSpacing(10);

        m_vBoxLayout->addWidget(m_iconWidget);
        m_vBoxLayout->addSpacing(5);

        m_vBoxLayout->addWidget(m_iconNameTitleLabel);
        m_vBoxLayout->addSpacing(5);

        m_vBoxLayout->addWidget(m_iconNameLabel);
        m_vBoxLayout->addSpacing(5);

        m_vBoxLayout->addWidget(m_enumNameTitleLabel);
        m_vBoxLayout->addSpacing(5);

        m_vBoxLayout->addWidget(m_enumNameLabel);

        setFixedWidth(180);

        m_nameLabel->setObjectName("nameLabel");
        m_iconNameTitleLabel->setObjectName("subTitleLabel");
        m_enumNameTitleLabel->setObjectName("subTitleLabel");
    }

    void setIcon(FluAwesomeType type)
    {
        m_iconWidget->setIcon(FluIconUtils::GetFluentIcon(type));
        m_nameLabel->setText(EnumTypeToQString(type));
        m_iconNameLabel->setText(EnumTypeToQString(type));
        m_enumNameLabel->setText("FluAwesomeType::" + EnumTypeToQString(type));
    }

  private:
    QLabel* m_nameLabel;
    FluIconWidget* m_iconWidget;
    QLabel* m_iconNameTitleLabel;
    QLabel* m_iconNameLabel;
    QLabel* m_enumNameTitleLabel;
    QLabel* m_enumNameLabel;

    QVBoxLayout* m_vBoxLayout;
};
