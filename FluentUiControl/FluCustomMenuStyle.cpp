#include "FluCustomMenuStyle.h"

FluCustomMenuStyle::FluCustomMenuStyle(int iconSize /*= 14*/) : QProxyStyle()
{
    m_iconSize = iconSize;
}

int FluCustomMenuStyle::pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget)
{
    if (metric == QStyle::PM_SmallIconSize)
        return m_iconSize;
    return QProxyStyle::pixelMetric(metric, option, widget);
}
