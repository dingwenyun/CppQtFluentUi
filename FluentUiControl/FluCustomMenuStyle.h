#pragma once

#include <QProxyStyle>
#include <QWidget>

class FluCustomMenuStyle : public QProxyStyle
{
  public:
    FluCustomMenuStyle(int iconSize = 14) : QProxyStyle()
    {
        m_iconSize = iconSize;
    }

    int pixelMetric(QStyle::PixelMetric metric, QStyleOption* option, QWidget* widget)
    {
        if (metric == QStyle::PM_SmallIconSize)
            return m_iconSize;
        return QProxyStyle::pixelMetric(metric, option, widget);
    }

  protected:
    int m_iconSize;
};
