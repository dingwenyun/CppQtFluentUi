#pragma once

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QJsonArray>
#include <map>
#include "FluLogUtils.h"
#include <QString>

class FluStyleSheetUitls
{
  public:
    FluStyleSheetUitls()
    {
    }

    static QString getQssByFileName(QString fileName);
    static QString getQssByFileName(QString jsonVars, QString fileName);
    static void replaceVar(QString jsonVars, QString &styleSheet);
};
