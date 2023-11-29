#pragma once

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include "../FluentUiUtils/FluThemeUtils.h"

class FluScrollBarHandle : public QWidget
{
  public:
    FluScrollBarHandle(Qt::Orientation orient, QWidget* parent = nullptr) : QWidget(parent)
    {
        m_orient = orient;
        if (orient == Qt::Vertical)
        {
            setFixedWidth(3);
        }
        else
        {
            setFixedHeight(3);
        }
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing);
        painter.setPen(Qt::NoPen);

        int nR = 0;
        // int nC = 0;
        if (m_orient == Qt::Vertical)
        {
            nR = width() / 2;
        }
        else
        {
            nR = height() / 2;
        }

        bool darkMode = FluThemeUtils::getInstance()->getThemeMode() == FluThemeMode::Dark;

        QColor color;
        if (darkMode)
        {
            color = QColor(255, 255, 255, 139);
        }
        else
        {
            color = QColor(0, 0, 0, 114);
        }

        painter.setBrush(QBrush(color));
        painter.drawRoundedRect(rect(), nR, nR);
    }

  private:
    Qt::Orientation m_orient;
};
