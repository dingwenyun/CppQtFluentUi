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
#include "FluThemeUtils.h"

class FluStyleSheetUitls
{
  public:
    FluStyleSheetUitls()
    {
    }

    static QString getThemeQssByFileName(QString fileName);
    static QString getQssByFileName(QString fileName);
    static QString getQssByFileName(QString jsonVars, QString fileName);
    static QString getQssByFileName(std::map<QString, QString> &kvMap, QString fileName);

    static void replaceVar(QString jsonVars, QString &styleSheet);
    static void replaceVar(std::map<QString, QString> &kvMap, QString &styleSheet);
};
