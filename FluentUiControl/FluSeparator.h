#pragma once

#include <QWidget>
#include <QPainter>
#include "../FluentUiUtils/FluThemeUtils.h"

enum class FluSeparatorDirection
{
    Horizontal,
    Vertical,
};

class FluSeparator : public QWidget
{
  public:
    FluSeparator(FluSeparatorDirection direction, QWidget* parent) : QWidget(parent)
    {
        m_direction = direction;
        if (direction == FluSeparatorDirection::Horizontal)
        {
            setFixedHeight(3);
        }
        else
        {
            setFixedWidth(3);
        }
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        QPainter painter;
        painter.setRenderHints(QPainter::Antialiasing);

        if (FluThemeUtils::isDarkMode())
            painter.setPen(QColor(255, 255, 255, 51));
        else
            painter.setPen(QColor(0, 0, 0, 22));

        if (m_direction == FluSeparatorDirection::Horizontal)
            painter.drawLine(1, 0, 1, height());
        else
            painter.drawLine(0, 1, width(), 1);
    }

  private:
    FluSeparatorDirection m_direction;
};