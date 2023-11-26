#pragma once

#include "../FluentUiUtils/FluentUiColorUtils.h"
#include <QWidget>
#include <QPainter>

class FluColorDemo : public QWidget
{
  public:
    FluColorDemo(QWidget* parent = nullptr) : QWidget(parent)
    {
        resize(250, 280);
    }

    void fillColorSet(const FluentUiColorSet& colorSet, QVector<QString>& colors)
    {
        colors.push_back(colorSet.darkest);
        colors.push_back(colorSet.darker);
        colors.push_back(colorSet.dark);
        colors.push_back(colorSet.normal);
        colors.push_back(colorSet.light);
        colors.push_back(colorSet.lighter);
        colors.push_back(colorSet.lightest);
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        QPainter painter(this);
        painter.setPen(Qt::NoPen);

        QVector<QString> colors;
        fillColorSet(FluentUiColorUtils::getInstance()->Yellow, colors);
        fillColorSet(FluentUiColorUtils::getInstance()->Orange, colors);
        fillColorSet(FluentUiColorUtils::getInstance()->Red, colors);
        fillColorSet(FluentUiColorUtils::getInstance()->Magenta, colors);
        fillColorSet(FluentUiColorUtils::getInstance()->Purple, colors);
        fillColorSet(FluentUiColorUtils::getInstance()->Blue, colors);
        fillColorSet(FluentUiColorUtils::getInstance()->Green, colors);

        for (int i = 0; i < (colors.size() / 7); i++)
        {
            for (int j = 0; j < 7; j++)
            {
                QString color = colors[i * 7 + j];
                QBrush brush;
                brush.setStyle(Qt::SolidPattern);
                brush.setColor(QColor(color.toStdString().c_str()));
                painter.setBrush(brush);
                painter.drawRoundedRect(25 + 30 * j, 25 + 30 * i, 25, 25, 5, 5);
            }
        }
    }
};
