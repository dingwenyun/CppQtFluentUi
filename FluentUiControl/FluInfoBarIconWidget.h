#pragma once

#include <QWidget>
#include "FluDef.h"
#include <QPainter>
#include "../FluentUiUtils/FluIconUtils.h"

class FluInfoBarIconWidget : public QWidget
{
    Q_OBJECT
  public:
    FluInfoBarIconWidget(FluAwesomeType awesomeType, QWidget* parent = nullptr) : QWidget(parent)
    {
        setFixedSize(36, 36);
        m_awesomeType = awesomeType;
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        QWidget::paintEvent(event);
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        QRect rect(10, 10, 15, 15);
        painter.drawPixmap(rect, FluIconUtils::GetFluentIconPixmap(m_awesomeType));
    }

  private:
    FluAwesomeType m_awesomeType;
};
