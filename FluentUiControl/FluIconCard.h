#pragma once

#include <QFrame>
#include "../FluentUiUtils/FluIconUtils.h"
#include "FluIconWidget.h"
#include <QApplication>

class FluIconCard : public QFrame
{
    Q_OBJECT
  public:
    FluIconCard(FluAwesomeType awesomeType, QWidget* parent = nullptr)
    {
        m_awesomeType = awesomeType;
        m_bSelected = false;

        m_iconWidget = new FluIconWidget(awesomeType, this);
        m_nameLabel = new QLabel(this);
        m_vBoxLayout = new QVBoxLayout(this);
        setFixedSize(48, 48);
        m_vBoxLayout->setSpacing(0);
        m_vBoxLayout->setContentsMargins(4, 16, 4, 0);
        m_vBoxLayout->setAlignment(Qt::AlignTop);

        m_iconWidget->setFixedSize(16, 16);
        m_vBoxLayout->addWidget(m_iconWidget, 0, Qt::AlignHCenter);
        // m_vBoxLayout->addSpacing(8);
        m_vBoxLayout->addWidget(m_nameLabel, 0, Qt::AlignHCenter);
        QString text = EnumTypeToQString(m_awesomeType);
        m_nameLabel->setText(text);
    }

    void setSelected(bool bSelected, bool force = false)
    {
        if (bSelected == m_bSelected && !force)
        {
            return;
        }

        m_bSelected = bSelected;
        m_iconWidget->setIcon(FluIconUtils::GetFluentIcon(m_awesomeType));
        //  if (!bSelected)
        //  {
        //      m_iconWidget->setIcon(FluIconUtils::GetFluentIcon(m_awesomeType));
        //  }
        //   else
        //   {
        //
        //    }

        setProperty("isSelected", m_bSelected);
        setStyle(QApplication::style());
    }

  protected:
    void mouseReleaseEvent(QMouseEvent* event)
    {
        if (m_bSelected)
            return;

        emit clicked(m_awesomeType);
    }
  signals:
    void clicked(FluAwesomeType awesomeType);

  private:
    FluAwesomeType m_awesomeType;
    bool m_bSelected;

    FluIconWidget* m_iconWidget;
    QLabel* m_nameLabel;
    QVBoxLayout* m_vBoxLayout;
};
