#pragma once

#include <QWidget>
#include <QPainter>
#include "../FluentUiUtils/FluThemeUtils.h"

class FluSeparatorWidget : public QWidget
{
    Q_OBJECT
  public:
    FluSeparatorWidget(QWidget* parent = nullptr) : QWidget(parent)
    {
    }

  protected:
    void paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        QPen pen = QPen(1);
        pen.setCosmetic(true);
        
        QColor penColor;
        if (FluThemeUtils::isDarkMode())
        {
            penColor = QColor(255, 255, 255, 21);
        }
        else
        {
            penColor = QColor(0, 0, 0, 15);
        }

        int nX = width() / 2;
        painter.drawLine(nX, 0, nX, height());
    }
};
