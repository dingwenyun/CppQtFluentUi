#include "FluDummyMenuAnimationManager.h"

FluDummyMenuAnimationManager::FluDummyMenuAnimationManager(FluRoundMenu* menu) : FluMenuAnimationManager(menu)
{
}

void FluDummyMenuAnimationManager::exec(QPoint pos)
{
    m_menu->move(_endPosition(pos));
}
