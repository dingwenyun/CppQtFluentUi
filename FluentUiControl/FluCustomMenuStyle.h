#pragma once

#include <QProxyStyle>
#include <QWidget>
#include <QStyleOption>

class FluCustomMenuStyle : public QProxyStyle
{
  public:
    FluCustomMenuStyle(int iconSize = 14);

    int pixelMetric(PixelMetric metric, const QStyleOption *option = nullptr, const QWidget *widget = nullptr);

  protected:
    int m_iconSize;
};
