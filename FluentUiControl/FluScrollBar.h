#pragma once

#include <QToolButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QPainter>
#include "../FluentUiUtils/FluentUiIconUtils.h"

class FluArrowButton : public QToolButton
{
    Q_OBJECT
  public:
    FluArrowButton(QPixmap icon, QWidget* parent = nullptr) : QToolButton(parent)
    {
        setFixedSize(10, 10);
        m_icon = icon;
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing);

        int s = 7;
        if (!isDown())
            s = 8;

        int x = (width() - s) / 2;
        painter.drawPixmap(QRect(x, x, s, s), m_icon);
    }

  private:
    QPixmap m_icon;
};

class FluScrollBarGroove : public QWidget
{
  public:
    FluScrollBarGroove(Qt::Orientation orient, QWidget* parent) : QWidget(parent)
    {
        if (orient == Qt::Vertical)
        {
            setFixedWidth(12);
            m_upButton = new FluArrowButton(FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::ArrowUp8));
            m_downButton = new FluArrowButton(FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::ArrowDown8));

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
            m_upButton = new FluArrowButton(FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::ArrowLeft8));
            m_downButton = new FluArrowButton(FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::ArrowRight8));

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
    }

  private:
    FluArrowButton* m_upButton;
    FluArrowButton* m_downButton;

    QHBoxLayout* m_hLayout;
    QVBoxLayout* m_vLayout;

    QGraphicsOpacityEffect* m_opacityEffect;
    QPropertyAnimation* m_opcityAni;
};

class FluScrollBar
{
};
