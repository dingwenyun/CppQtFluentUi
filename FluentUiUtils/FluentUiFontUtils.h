#pragma once

#include <QWidget>
#include <QFont>

class FluentUiFontUtils
{
  public:
    static void setFont(QWidget* widget, int fontSize = 14, QFont::Weight weight = QFont::Normal)
    {
        widget->setFont(getFont(fontSize, weight));
    }

    static const QFont getFont(int fontSize, QFont::Weight weight = QFont::Normal)
    {
        QFont tmpFont = QFont();
        tmpFont.setFamilies({"Segoe UI", "Microsoft YaHei", "PingFang SC"});
        tmpFont.setPixelSize(fontSize);
        tmpFont.setWeight(weight);
        return tmpFont;
    }
};
