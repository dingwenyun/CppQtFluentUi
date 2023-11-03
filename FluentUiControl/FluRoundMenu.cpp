#include "FluRoundMenu.h"

FluRoundMenu::FluRoundMenu(QString title, QWidget* parent /*= nullptr*/) : QMenu(parent)
{
    m_title = title;
    m_icon = QPixmap();

    m_bSubMenu = false;
    m_parentMenu = nullptr;
    m_menuItem = nullptr;
    m_lastHoverItem = nullptr;
    m_lastHoverSubMenuItem = nullptr;
    m_bHideBySystem = true;
    m_itemHeight = 28;

    m_hBoxLayout = new QHBoxLayout(this);
    m_view = new FluMenuActionListWidget(this);

    m_aniManager = nullptr;
    m_timer = new QTimer(this);

    __initWidgets();
}
