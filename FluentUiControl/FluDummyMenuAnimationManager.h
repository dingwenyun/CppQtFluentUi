#pragma once

#include "FluMenuAnimationManager.h"
#include "FluRoundMenu.h"

class FluDummyMenuAnimationManager : public FluMenuAnimationManager
{
  public:
    FluDummyMenuAnimationManager(FluRoundMenu* menu);

    void exec(QPoint pos);
};
