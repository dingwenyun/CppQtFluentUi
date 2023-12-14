#pragma once

#include <QWidget>
#include "FluDef.h"
#include <QPainter>
#include "../FluentUiUtils/FluIconUtils.h"
//#include "FluInfoBar.h"

enum class FluInfoBarType;
class FluInfoBarIconWidget : public QWidget
{
    Q_OBJECT
  public:
    FluInfoBarIconWidget(FluAwesomeType awesomeType, FluInfoBarType type, QWidget* parent = nullptr);

  protected:
    void paintEvent(QPaintEvent* event);

  private:
    FluAwesomeType m_awesomeType;
    FluInfoBarType m_infoBarType;
};
