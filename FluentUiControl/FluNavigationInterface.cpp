#include "FluNavigationInterface.h"

FluNavigationInterface::FluNavigationInterface(QWidget* parent /*= nullptr*/, bool bShowMenuButton /*= true*/, bool bShowReturnButton /*= false*/, bool bCollapsible /*= true*/) : QWidget(parent)
{
    // setMouseTracking(true);
    // m_vLayout = new QVBoxLayout();
    // setLayout(m_vLayout);

    // m_vLayout->setContentsMargins(0, 0, 0, 0);
    m_panel = new FluNavigationPanel(false, this);
    m_panel->setMenuButtonVisible(bShowMenuButton && bCollapsible);
    m_panel->setReturnButtonVisible(bShowReturnButton);
    m_panel->setCollapsible(bCollapsible);
    m_panel->installEventFilter(this);
    connect(this, &FluNavigationInterface::displayModeChanged, m_panel, &FluNavigationPanel::displayModeChanged);

    // m_vLayout->addWidget(m_panel);
    // m_vLayout->addStretch();
    // todo display mode change
    resize(48, height());
    setMinimumWidth(48);
    // setFixedWidth(48);
    setAttribute(Qt::WA_TranslucentBackground);
    // setWindowFlag(Qt::FramelessWindowHint);
    // setAttribute(Qt::WA_StyledBackground);
    // setStyleSheet("background-color:pink;");
    // setStyleSheet("background-color:pink;");  // 样式表未生效
    // LogDebug << "w:" << width() << ",h:" << height();
    // m_panel->show();
}

FluNavigationTreeWidget* FluNavigationInterface::addItem(QString routeKey,
                                                         QPixmap icon,
                                                         QString text,
                                                         FluNavigationWidgetClickedCallBack onClick /*= nullptr*/,
                                                         bool bSelectable /*= true*/,
                                                         FluNavigationItemPosition position /*= FluNavigationItemPosition::TOP*/,
                                                         QString toolTip /*= ""*/,
                                                         QString parentRouteKey /*= ""*/)
{
    return insertItem(-1, routeKey, icon, text, onClick, bSelectable, position, toolTip, parentRouteKey);
}

void FluNavigationInterface::addWidget(QString routeKey,
                                       FluNavigationWidget* widget,
                                       FluNavigationWidgetClickedCallBack onClick,
                                       FluNavigationItemPosition position /*= FluNavigationItemPosition::TOP*/,
                                       QString tooltip /*= ""*/,
                                       QString parentRouteKey /*= ""*/)
{
    insertWidget(-1, routeKey, widget, onClick, position, tooltip, parentRouteKey);
}

void FluNavigationInterface::insertWidget(int nIndex,
                                          QString routeKey,
                                          FluNavigationWidget* widget,
                                          FluNavigationWidgetClickedCallBack onClick /*= nullptr*/,
                                          FluNavigationItemPosition position /*= FluNavigationItemPosition::TOP*/,
                                          QString toolTip /*= ""*/,
                                          QString parentRouteKey /*= ""*/)
{
    m_panel->insertWidget(nIndex, routeKey, widget, onClick, position, toolTip, parentRouteKey);
    // setMinimumHeight(m_panel->layoutMinHeight());
}

void FluNavigationInterface::addSeparator(FluNavigationItemPosition position /*= FluNavigationItemPosition::TOP*/)
{
    insertSeparator(-1, position);
}
