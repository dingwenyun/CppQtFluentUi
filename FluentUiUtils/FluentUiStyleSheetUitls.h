#pragma once

#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QByteArray>
#include <QJsonArray>
#include <map>
#include "FluentUiLogUtils.h"

class FluentUiStyleSheetUitls
{
public:
	FluentUiStyleSheetUitls()
	{

	}

	static QString getQssByFileName(QString fileName)
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

	static QString getQssByFileName(QString jsonVars, QString fileName)
	{
		QString styleSheet = getQssByFileName(fileName);
		replaceVar(jsonVars, styleSheet);
		return styleSheet;
	}


	static void replaceVar(QString jsonVars, QString &styleSheet)
	{
		QJsonParseError jsonError;
		QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonVars.toUtf8(), &jsonError);

		QString jsonStr(jsonDoc.toJson());
		LogDebug << "jsonStr:" << jsonStr;
		if (!jsonDoc.isArray())
		{
			LogDebug << jsonError.errorString();
			return;
		}
		//[{key:k1,value:v1},{key:k2,value:v2}]
		std::map<QString, QString> KVMap;
		QJsonArray jsonArray = jsonDoc.array();
		for (int i = 0; i < jsonArray.size(); i++)
		{
			QJsonValue jsonValue = jsonArray.at(i);
			if(!jsonValue.isObject())
				continue;

			QJsonObject jsonObject = jsonValue.toObject();
			QJsonValue keyJsonValue = jsonObject.take("key");
			QJsonValue valueJsonValue = jsonObject.take("value");
			if (keyJsonValue.isString() && valueJsonValue.isString())
			{
				KVMap[keyJsonValue.toString()] = valueJsonValue.toString();
			}
		}

		for (auto itMap = KVMap.begin(); itMap != KVMap.end(); itMap++)
		{
			QString key = "[[" + itMap->first + "]]";
			QString value = itMap->second;

			styleSheet.replace(key, value);
		}
	}
};

