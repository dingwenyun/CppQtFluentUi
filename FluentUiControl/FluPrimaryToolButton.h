#pragma once

#include "FluToolButton.h"
#include "../FluentUiUtils/FluThemeUtils.h"
#include <QPainter>

class FluPrimaryToolButton : public FluToolButton
{
    Q_OBJECT
  public:
    FluPrimaryToolButton(QWidget* parent = nullptr) : FluToolButton(parent)
    {
        QString qss = FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluPrimaryToolButton.qss");
        setStyleSheet(qss);
    }

    FluPrimaryToolButton(FluAwesomeType awesomeType, QWidget* parent = nullptr) : FluToolButton(awesomeType, parent)
    {
        QString qss = FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluPrimaryToolButton.qss");
        setStyleSheet(qss);
    }

    FluPrimaryToolButton(QIcon icon, QWidget* parent = nullptr) : FluToolButton(icon, parent)
    {
        QString qss = FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluPrimaryToolButton.qss");
        setStyleSheet(qss);
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        QToolButton::paintEvent(event);
        if (m_icon.isNull())
            return;

        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        if (isEnabled())
        {
            painter.setOpacity(0.43);
        }
        else
        {
            if (FluThemeUtils::isDarkMode())
                painter.setOpacity(0.786);
            else
                painter.setOpacity(0.9);
        }

        int iconW = iconSize().width();
        int iconH = iconSize().height();

        int nX = (width() - iconW) / 2;
        int nY = (height() - iconH) / 2;

        painter.drawPixmap(QRect(nX, nY, iconW, iconH), m_icon.pixmap(iconH, iconW));
    }
};