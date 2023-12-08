#include "FluStyleSheetUitls.h"

QString FluStyleSheetUitls::getThemeQssByFileName(QString fileName)
{
    std::map<QString, QString> kvMap;
    kvMap["ThemeColorNormal"] = FluThemeUtils::getThemeColorNormal().name();
    kvMap["ThemeColorLight"] = FluThemeUtils::getThemeColorLight().name();
    kvMap["ThemeColorLighter"] = FluThemeUtils::getThemeColorLighter().name();
    kvMap["ThemeColorLightest"] = FluThemeUtils::getThemeColorLightest().name();
    kvMap["ThemeColorDark"] = FluThemeUtils::getThemeColorDark().name();
    kvMap["ThemeColorDarker"] = FluThemeUtils::getThemeColorDarker().name();
    kvMap["ThemeColorDarkest"] = FluThemeUtils::getThemeColorDarkest().name();

    return getQssByFileName(kvMap, fileName);
}

QString FluStyleSheetUitls::getQssByFileName(QString fileName)
{
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly))
    {
        QString qssStr = file.readAll();
        file.close();
        return qssStr;
    }

    return "";
}

QString FluStyleSheetUitls::getQssByFileName(QString jsonVars, QString fileName)
{
    QString styleSheet = getQssByFileName(fileName);
    replaceVar(jsonVars, styleSheet);
    return styleSheet;
}

QString FluStyleSheetUitls::getQssByFileName(std::map<QString, QString> &kvMap, QString fileName)
{
    QString styleSheet = getQssByFileName(fileName);
    replaceVar(kvMap, styleSheet);
    return styleSheet;
}

void FluStyleSheetUitls::replaceVar(QString jsonVars, QString &styleSheet)
{
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonVars.toUtf8(), &jsonError);

    QString jsonStr(jsonDoc.toJson());
    // LogDebug << "jsonStr:" << jsonStr;
    if (!jsonDoc.isArray())
    {
        LogErr << jsonError.errorString();
        return;
    }
    //[{key:k1,value:v1},{key:k2,value:v2}]
    std::map<QString, QString> KVMap;
    QJsonArray jsonArray = jsonDoc.array();
    for (int i = 0; i < jsonArray.size(); i++)
    {
        QJsonValue jsonValue = jsonArray.at(i);
        if (!jsonValue.isObject())
            continue;

        QJsonObject jsonObject = jsonValue.toObject();
        QJsonValue keyJsonValue = jsonObject.take("key");
        QJsonValue valueJsonValue = jsonObject.take("value");
        if (keyJsonValue.isString() && valueJsonValue.isString())
        {
            KVMap[keyJsonValue.toString()] = valueJsonValue.toString();
        }
    }

    replaceVar(KVMap, styleSheet);
}

void FluStyleSheetUitls::replaceVar(std::map<QString, QString> &kvMap, QString &styleSheet)
{
    for (auto itMap = kvMap.begin(); itMap != kvMap.end(); itMap++)
    {
        QString key = "[[" + itMap->first + "]]";
        QString value = itMap->second;
        styleSheet.replace(key, value);
    }
}
