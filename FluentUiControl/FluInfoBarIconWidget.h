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
        setFixedSize(28, 28);
        m_awesomeType = awesomeType;
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        QWidget::paintEvent(event);
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        QRect rect(0, 0, 28, 28);
        painter.drawPixmap(rect, FluIconUtils::GetFluentIconPixmap(m_awesomeType));
    }

  private:
    FluAwesomeType m_awesomeType;
};
