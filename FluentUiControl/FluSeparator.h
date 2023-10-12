#pragma once

#include <QWidget>
#include <QPainter>
#include "../FluentUiUtils/FluentUiThemeUtils.h"

// "---"
class FluHorizontalSeparator : public QWidget
{
  public:
    FluHorizontalSeparator(QWidget* parent) : QWidget(parent)
    {
        setFixedHeight(3);
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        QPainter painter;
        painter.setRenderHints(QPainter::Antialiasing);

        if (FluentUiThemeUtils::getInstance()->getDarkMode() == FluentUiThemeUtilsDarkMode::Dark)
            painter.setPen(QColor(255, 255, 255, 51));
        else
            painter.setPen(QColor(0, 0, 0, 22));
        painter.drawLine(0, 1, width(), 1);
    }
};

// "|"
class FluVerticalSeparator : public QWidget
{
  public:
    FluVerticalSeparator(QWidget* parent) : QWidget(parent)
    {
        setFixedWidth(3);
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        QPainter painter;
        painter.setRenderHints(QPainter::Antialiasing);
        if (FluentUiThemeUtils::getInstance()->getDarkMode() == FluentUiThemeUtilsDarkMode::Dark)
            painter.setPen(QColor(255, 255, 255, 51));
        else
            painter.setPen(QColor(0, 0, 0, 22));
        painter.drawLine(1, 0, 1, height());
    }
};
