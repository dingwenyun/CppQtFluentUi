#pragma once

#include <QPixmap>
#include <QFont>
#include <QIcon>

#include "../FluentUiControl/FluDef.h"

#define FluGetIcon(nType) FluentUiIconUtils::GetFluentIcon(nType)
#define FluGetIconPixmap(nType) FluentUiIconUtils::GetFluentIconPixmap(nType)

class FluentUiIconUtils
{
  private:
    FluentUiIconUtils();
    ~FluentUiIconUtils();

  public:
    static FluentUiIconUtils* getInstance();
    static QPixmap GetFluentIconPixmap(FluAwesomeType nType);
    static QIcon GetFluentIcon(FluAwesomeType nType);

  private:
    QFont m_fluentFont;
};
