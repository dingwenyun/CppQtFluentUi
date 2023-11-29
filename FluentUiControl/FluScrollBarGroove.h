#pragma once

#include <QWidget>
#include "FluArrowButton.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include "../FluentUiUtils/FluThemeUtils.h"
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>

class FluScrollBarGroove : public QWidget
{
    Q_OBJECT
  public:
    FluScrollBarGroove(Qt::Orientation orient, QWidget* parent) : QWidget(parent)
    {
        if (orient == Qt::Vertical)
        {
            setFixedWidth(12);
            m_upButton = new FluArrowButton(FluIconUtils::GetFluentIconPixmap(FluAwesomeType::CaretSolidUp));
            m_downButton = new FluArrowButton(FluIconUtils::GetFluentIconPixmap(FluAwesomeType::CaretSolidDown));

            m_vLayout = new QVBoxLayout(this);
            setLayout(m_vLayout);
            m_vLayout->addWidget(m_upButton, 0, Qt::AlignHCenter);
            m_vLayout->addStretch(1);
            m_vLayout->addWidget(m_downButton, 0, Qt::AlignHCenter);
            m_vLayout->setContentsMargins(0, 3, 0, 3);
        }
        else
        {
            setFixedHeight(12);
            m_upButton = new FluArrowButton(FluIconUtils::GetFluentIconPixmap(FluAwesomeType::CaretSolidLeft));
            m_downButton = new FluArrowButton(FluIconUtils::GetFluentIconPixmap(FluAwesomeType::CaretSolidRight));

            m_hLayout = new QHBoxLayout(this);
            setLayout(m_hLayout);
            m_hLayout->addWidget(m_upButton, 0, Qt::AlignVCenter);
            m_hLayout->addStretch(1);
            m_hLayout->addWidget(m_downButton, 0, Qt::AlignVCenter);
            m_hLayout->setContentsMargins(3, 0, 3, 0);
        }

        m_opacityEffect = new QGraphicsOpacityEffect(this);
        m_opcityAni = new QPropertyAnimation(m_opacityEffect, "opacity", this);
        setGraphicsEffect(m_opacityEffect);
        m_opacityEffect->setOpacity(0);
    }

    void fadeIn()
    {
        m_opcityAni->setEndValue(1);
        m_opcityAni->setDuration(150);
        m_opcityAni->start();
    }

    void fadeOut()
    {
        m_opcityAni->setEndValue(0);
        m_opcityAni->setDuration(150);
        m_opcityAni->start();
    }

    void paintEvent(QPaintEvent* event)
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing);
        painter.setPen(Qt::NoPen);

        bool bDarkMode = FluThemeUtils::getInstance()->getThemeMode() == FluThemeMode::Dark;

        if (!bDarkMode)
        {
            QBrush brush(QColor(252, 252, 252, 217));
            painter.setBrush(brush);
        }
        else
        {
            QBrush brush(QColor(44, 44, 44, 245));
            painter.setBrush(brush);
        }

        painter.drawRoundedRect(rect(), 6, 6);
    }

    FluArrowButton* getUpButton()
    {
        return m_upButton;
    }

    FluArrowButton* getDownButton()
    {
        return m_downButton;
    }

    QPropertyAnimation* getOpcityAni()
    {
        return m_opcityAni;
    }

    QGraphicsOpacityEffect* getOpacityEffect()
    {
        return m_opacityEffect;
    }

  private:
    FluArrowButton* m_upButton;
    FluArrowButton* m_downButton;

    QHBoxLayout* m_hLayout;
    QVBoxLayout* m_vLayout;

    QGraphicsOpacityEffect* m_opacityEffect;
    QPropertyAnimation* m_opcityAni;
};