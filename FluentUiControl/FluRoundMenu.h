#pragma once

#include <QMenu>
#include <list>
#include <QHBoxLayout>
#include <QTimer>
#include <QGraphicsDropShadowEffect>
#include "FluMenuActionListWidget.h"

class FluSubMenuItemWidget;
class FluMenuAnimationManager;
class FluRoundMenu : public QMenu
{
    Q_OBJECT
  public:
    FluRoundMenu(QString title, QWidget* parent = nullptr);

  public:
    void __initWidgets();

    void setMaxVisibleItems(int num);

    void setItemHeight(int height);

    FluMenuActionListWidget* getView();

    void setShadowEffect(int blurRadius = 30, QPoint offset = QPoint(0, 8), QColor color = QColor(0, 0, 0, 30));

    void _setParentMenu(FluRoundMenu* menu, QListWidgetItem* item);

    void adjustSize();

    QPixmap getIcon();

    void setIcon(QPixmap icon);

    QString getTitle();

    void clear();

    void addAction(QAction* action);

    QListWidgetItem* _createActionItem(QAction* action, QAction* preAction = nullptr);

    int _adjustItemText(QListWidgetItem* item, QAction* action);

    int _longestShortcutWidth();

    QIcon _createItemIcon(QAction* action);

    QIcon _createItemIcon(FluRoundMenu* menu);

    bool _hasItemIcon();

    void insertAction(QAction* before, QAction* action);

    void addActions(const QList<QAction*> actions);

    void insertActions(QAction* before, const QList<QAction*>& actions);

    void removeAction(QAction* action);

    void setDefaultAction(QAction* action);

    void addMenu(FluRoundMenu* menu);

    void insertMenu(QAction* before, FluRoundMenu* menu);

    FluSubMenuItemWidget* _createSubMenuItem(FluRoundMenu* menu);

    void addSeparator();

    void _hideMenu(bool bHideBySystem = false);

    void _closeParentMenu();

    QList<QAction*> getMenuActions();

    void adjustPosition();

    void exec(QPoint pos, bool bAni = true, FluMenuAnimationType aniType = FluMenuAnimationType::DROP_DOWN);

  signals:
    void closedSignal();
  public slots:

    void _onShowMenuTimeOut();

    void _onItemClicked(QListWidgetItem* item);

    void _onItemEntered(QListWidgetItem* item);

    void _onActionChanged();

    void _showSubMenu(QListWidgetItem* item);

  protected:
    void hideEvent(QHideEvent* event);

    void closeEvent(QCloseEvent* event);

    void mousePressEvent(QMouseEvent* event);

    void mouseMoveEvent(QMouseEvent* event);

  private:
    bool m_bSubMenu;
    FluRoundMenu* m_parentMenu = nullptr;
    QListWidgetItem* m_menuItem;
    QListWidgetItem* m_lastHoverItem;
    QListWidgetItem* m_lastHoverSubMenuItem;

    bool m_bHideBySystem;
    int m_itemHeight;

    QHBoxLayout* m_hBoxLayout;
    FluMenuActionListWidget* m_view;
    FluMenuAnimationManager* m_aniManager;

    QTimer* m_timer;

    QString m_title;
    QPixmap m_icon;

    QList<QAction*> m_actions;
    QList<FluRoundMenu*> m_subMenus;
    QGraphicsDropShadowEffect* m_shadowEffect;
};
