#include "../FluentUiControl/FluDef.h"
#include "FluIconUtils.h"
#include <QFontDatabase>
#include <QPainter>
#include "../FluentUiControl/FluDef.h"

FluIconUtils::FluIconUtils()
{
    int fontId = QFontDatabase::addApplicationFont("../res/Segoe_Fluent_Icons.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    m_fluentFont.setFamily(fontFamilies.at(0));
}

FluIconUtils::~FluIconUtils()
{
}

FluIconUtils* FluIconUtils::getInstance()
{
    static FluIconUtils utils;
    return &utils;
}

QPixmap FluIconUtils::GetFluentIconPixmap(FluAwesomeType nType)
{
    return GetFluentIconPixmap(nType, QColor(Qt::black));
}

QPixmap FluIconUtils::GetFluentIconPixmap(FluAwesomeType nType, QColor penColor)
{
    QFont tmpFont = getInstance()->m_fluentFont;
    tmpFont.setPixelSize(20);

    QPixmap tmpPixMap(30, 30);
    tmpPixMap.fill(Qt::transparent);
    QPainter painter;
    painter.begin(&tmpPixMap);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);
    painter.setPen(penColor);
    //   painter.setBrush(Qt::black);
    tmpFont.setPointSize(15);
    painter.setFont(tmpFont);
    painter.drawText(tmpPixMap.rect(), Qt::AlignCenter, QChar((int)nType));
    painter.end();
    // tmpPixMap.save("tmp.png");
    return tmpPixMap;
}

QIcon FluIconUtils::GetFluentIcon(FluAwesomeType nType)
{
    return QIcon(GetFluentIconPixmap(nType));
}

QIcon FluIconUtils::GetFluentIcon(FluAwesomeType nType, QColor penColor)
{
    return QIcon(GetFluentIconPixmap(nType, penColor));
}
