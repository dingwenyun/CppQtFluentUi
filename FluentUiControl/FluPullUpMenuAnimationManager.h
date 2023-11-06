#pragma once

#include "FluMenuAnimationManager.h"
#include "FluRoundMenu.h"
#include <QScreen>
#include <QApplication>
#include <QSize>
#include <QPoint>

class FluPullUpMenuAnimationManager : public FluMenuAnimationManager
{
  public:
    FluPullUpMenuAnimationManager(FluRoundMenu* menu) : FluMenuAnimationManager(menu)
    {
    }

    QPoint _endPosition(QPoint pos);

    void exec(QPoint pos);

    QSize availableViewSize(QPoint pos);

    void _onValueChanged();
};
