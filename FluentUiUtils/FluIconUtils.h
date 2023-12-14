#pragma once

#include <QPixmap>
#include <QFont>
#include <QIcon>

#include "../FluentUiControl/FluDef.h"

#define FluGetIcon(nType) FluIconUtils::GetFluentIcon(nType)
#define FluGetIconPixmap(nType) FluIconUtils::GetFluentIconPixmap(nType)

class FluIconUtils
{
  private:
    FluIconUtils();
    ~FluIconUtils();

  public:
    static FluIconUtils* getInstance();
    static QPixmap GetFluentIconPixmap(FluAwesomeType nType);
    static QIcon GetFluentIcon(FluAwesomeType nType);

    static QPixmap GetFluentIconPixmap(FluAwesomeType nType, QColor penColor);
    static QIcon GetFluentIcon(FluAwesomeType nType, QColor penColor);
  private:
    QFont m_fluentFont;
};
