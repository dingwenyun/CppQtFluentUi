#pragma once

#include <QColor>
#include <QObject>
#include <QString>

#include "FluColorSet.h"

class FluColorUtils
{
  public:
    QString Black;
    QString White;
    QString Grey10;
    QString Grey20;
    QString Grey30;
    QString Grey40;
    QString Grey50;
    QString Grey60;
    QString Grey70;
    QString Grey80;
    QString Grey90;
    QString Grey100;
    QString Grey110;
    QString Grey120;
    QString Grey130;
    QString Grey140;
    QString Grey150;
    QString Grey160;
    QString Grey170;
    QString Grey180;
    QString Grey190;
    QString Grey200;
    QString Grey210;
    QString Grey220;

    FluColorSet Yellow;
    FluColorSet Orange;
    FluColorSet Red;
    FluColorSet Magenta;
    FluColorSet Purple;
    FluColorSet Blue;
    FluColorSet Teal;
    FluColorSet Green;

  private:
    FluColorUtils();

  public:
    static FluColorUtils* getInstance()
    {
        static FluColorUtils utils;
        return &utils;
    }
};
