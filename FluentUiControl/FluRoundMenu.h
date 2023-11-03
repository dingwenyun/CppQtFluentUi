#pragma once

#include <QMenu>
#include <list>
#include <QHBoxLayout>
#include <QTimer>
#include <QGraphicsDropShadowEffect>
#include "FluMenuActionListWidget.h"
#include "FluSubMenuItemWidget.h"


class FluMenuAnimationManager;
class FluRoundMenu : public QMenu
{
	//Q_OBJECT
  public:
    FluRoundMenu(QString title, QWidget* parent = nullptr);

  public:
    void __initWidgets()
    {
        setWindowFlags(Qt::Popup | Qt::FramelessWindowHint | Qt::NoDropShadowWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        setMouseTracking(true);

        m_timer->setSingleShot(true);
        m_timer->setInterval(400);
        connect(m_timer, &QTimer::timeout, this, &FluRoundMenu::_onShowMenuTimeOut);

        // 添加阴影效果

    }

    FluMenuActionListWidget* getView()
    {
        return m_view;
    }


    void setShadowEffect(int blurRadius = 30, QPoint offset = QPoint(0,8), QColor color = QColor(0,0,0,30))
    {
        m_shadowEffect = new QGraphicsDropShadowEffect(m_view);
        m_shadowEffect->setBlurRadius(blurRadius);
        m_shadowEffect->setOffset(offset);
        m_shadowEffect->setColor(color);
        m_view->setGraphicsEffect(nullptr);
        m_view->setGraphicsEffect(m_shadowEffect);
    }
  public slots:

  void _onShowMenuTimeOut()
  {
  }

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

    QTimer *m_timer;

    QString m_title;
    QPixmap m_icon;

    std::list<QAction> m_actions;
    std::list<FluRoundMenu*> m_subMenus;

    QGraphicsDropShadowEffect* m_shadowEffect;
};
