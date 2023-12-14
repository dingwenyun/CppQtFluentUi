#include "FluTopInfoBarManager.h"

//FluTopInfoBarManager::FluTopInfoBarManager() : FluInfoBarManager()
//{
//}
//
//QPoint FluTopInfoBarManager::slideAniStartPos(FluInfoBar* infoBar)
//{
//    return (getInfoBarPos(infoBar) - QPoint(0, m_spacing));
//}
//
//QPoint FluTopInfoBarManager::slideAniEndPos(FluInfoBar* infoBar)
//{
//    return getInfoBarPos(infoBar);
//}
//
//QPoint FluTopInfoBarManager::dropAniStartPos(FluInfoBar* infoBar)
//{
//    return infoBar->pos();
//}
//
//QPoint FluTopInfoBarManager::dropAniEndPos(FluInfoBar* infoBar)
//{
//    return getInfoBarPos(infoBar);
//}
//
//QPoint FluTopInfoBarManager::getInfoBarPos(FluInfoBar* infoBar)
//{
//    QWidget* parentWidget = (QWidget*)infoBar->parent();
//    int nX = (parentWidget->width() - infoBar->width()) / 2;
//    int nIndex = m_infoBars[parentWidget].indexOf(infoBar);
//    int nY = m_margin + (infoBar->height() + m_spacing) * nIndex;
//    return QPoint(nX, nY);
//}
