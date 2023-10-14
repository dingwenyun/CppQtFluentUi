#pragma once

#include "FluDef.h"
#include <QWidget>
#include <QScrollArea>
#include <QPropertyAnimation>
#include "FluNavigationPushButton.h"
#include "FluNavigationItemLayout.h"
#include "FluNavigationHistory.h"
#include "FluNavigationToolButton.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"
#include "FluNavigationTreeWidget.h"
#include <QPainter>
#include <QStyleOption>
#include <QFrame>
#include "FluNavigationItem.h"
#include "FluNavigationSeparator.h"
#include "FluNavigationToolTipFilter.h"

// 导航栏显示模式
enum class FluNavigationDisplayMode
{
    MINIMAL = 0,
    COMPACT,
    EXPAND,
    MENU
};

// 导航栏位置
enum class FluNavigationItemPosition
{
    TOP = 0,
    SCROLL,
    BOTTOM
};

using FluNavigationWidgetClickedCallBack = void (*)();

class FluNavigationPanel : public QFrame
{
    Q_OBJECT

  public:
    FluNavigationPanel(bool bMinimalEnable = false, QWidget* parent = nullptr) : QFrame(parent)
    {
        m_parent = parent;
        m_bMenuButtonVisible = true;     // 显示菜单按钮
        m_bReturnButtonVisible = false;  // 显示返回按钮
        m_bCollapsible = true;

        m_scrollArea = new QScrollArea(this);
        m_scrollWidget = new QWidget();

        m_menuButton = new FluNavigationToolButton(FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::GlobalNavButton), this);
        m_returnButton = new FluNavigationToolButton(FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::Back), this);
        m_returnButton->setVisible(false);

        // ---
        m_vLayout = new FluNavigationItemLayout(this);
        setLayout(m_vLayout);

        m_vTopLayout = new FluNavigationItemLayout();
        LogDebug << "vlayout size hint:" << m_vLayout->sizeHint();
        m_vBottomLayout = new FluNavigationItemLayout();
        m_vScrollLayout = new FluNavigationItemLayout(m_scrollWidget);
        LogDebug << "vScrolllayout size hint:" << m_vScrollLayout->sizeHint();

        m_expandAni = new QPropertyAnimation(this, "geometry", this);
        m_expandWidth = 322;

        m_bMinimalEnabled = bMinimalEnable;
        if (bMinimalEnable)
            m_displayMode = FluNavigationDisplayMode::MINIMAL;
        else
            m_displayMode = FluNavigationDisplayMode::COMPACT;

        __initWidget(parent, bMinimalEnable);
        // __initLayout();
        //  __connect();

        // setStyleSheet("background-color: pink;");
        // setStyleSheet("background-color:red;");
    }
  signals:
    void displayModeChanged(FluNavigationDisplayMode mode);
  public:
    void __initWidget(QWidget* parent, bool bMinimalEnable)
    {
        // resize(48, height());
        setFixedSize(48, height());
        setAttribute(Qt::WA_StyledBackground);
        window()->installEventFilter(this);  // 事件处理器

        //	LogDebug << "resize:" << "w:" << width() << ",h:" << height();

        //	m_returnButton->hide();
        //	m_returnButton->setDisabled(true);

        m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_scrollArea->setWidget(m_scrollWidget);
        m_scrollArea->setWidgetResizable(true);

        m_expandAni->setEasingCurve(QEasingCurve::OutQuad);
        m_expandAni->setDuration(150);

        connect(m_menuButton, &FluNavigationToolButton::clicked, this, &FluNavigationPanel::toggle);
        connect(m_expandAni, &QPropertyAnimation::finished, this, &FluNavigationPanel::_onExpandAniFinished);
        // mark it!
        // mark it!

        // mark it!
        // mark it!
        setProperty("menu", false);
        m_scrollWidget->setObjectName("scrollWidget");
        // mark it! styleSheet

        // m_scrollWidget->resize(48, height());
        // m_scrollArea->resize(48, height());

        // FluSetStyleSheet(FluNavigationPanel);

        // QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluNavigationPanel.qss");
        // setStyleSheet(qss);

        // setStyleSheet("background-color: pink;");
        // setStyleSheet("background-color:red;");

        // LogDebug << "panel size:"
        //        << "w:" << width() << ",h:" << height();
        // LogDebug << "scroll widget:"
        //         << "w:" << m_scrollWidget->width() << ",h:" << m_scrollWidget->height();

        __initLayout();
    }

    // void __connect()
    //{
    //    connect(m_menuButton, &FluNavigationToolButton::clicked, this, &FluNavigationPanel::toggle);
    //}

    void __initLayout()
    {
        m_vLayout->setContentsMargins(0, 5, 0, 5);
        m_vTopLayout->setContentsMargins(4, 0, 4, 0);
        m_vBottomLayout->setContentsMargins(4, 0, 4, 0);
        m_vScrollLayout->setContentsMargins(4, 0, 4, 0);

        m_vLayout->setSpacing(4);
        m_vTopLayout->setSpacing(4);
        m_vScrollLayout->setSpacing(4);
        m_vBottomLayout->setSpacing(4);

        m_vLayout->addLayout(m_vTopLayout);
        m_vLayout->addWidget(m_scrollArea, 1, Qt::AlignTop);
        m_vLayout->addLayout(m_vBottomLayout);

        m_vLayout->setAlignment(Qt::AlignTop);
        m_vTopLayout->setAlignment(Qt::AlignTop);
        m_vScrollLayout->setAlignment(Qt::AlignTop);
        m_vBottomLayout->setAlignment(Qt::AlignBottom);

        m_vTopLayout->addWidget(m_returnButton);
        m_vTopLayout->addWidget(m_menuButton);
        LogDebug << "panel size:"
                 << "w:" << width() << ",h:" << height();
    }

    FluNavigationWidget* __widget(QString routeKey)
    {
        auto itf = m_items.find(routeKey);
        if (itf == m_items.end())
            return nullptr;
        return itf->second->m_widget;
    }

    FluNavigationTreeWidget* addItem(QString routeKey,
                                     QPixmap icon,
                                     QString text,
                                     FluNavigationWidgetClickedCallBack onClick = nullptr,
                                     bool bSelectable = true,
                                     FluNavigationItemPosition position = FluNavigationItemPosition::TOP,
                                     QString toolTip = "",
                                     QString parentRouteKey = "")
    {
        return insertItem(-1, routeKey, icon, text, onClick, bSelectable, position, toolTip, parentRouteKey);
    }

    void addWidget(QString routeKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack callback, FluNavigationItemPosition position = FluNavigationItemPosition::TOP, QString toolTip = "", QString parentRouteKey = "")
    {
        insertWidget(-1, routeKey, widget, callback, position, toolTip, parentRouteKey);
    }

    FluNavigationTreeWidget* insertItem(int nIndex,
                                        QString routeKey,
                                        QPixmap icon,
                                        QString text,
                                        FluNavigationWidgetClickedCallBack onClick,
                                        bool bSelectable,
                                        FluNavigationItemPosition position = FluNavigationItemPosition::TOP,
                                        QString toolTip = "",
                                        QString parentRouteKey = "")
    {
        auto itf = m_items.find(routeKey);
        if (itf != m_items.end())
            return nullptr;

        FluNavigationTreeWidget* treeWidget = new FluNavigationTreeWidget(icon, text, bSelectable, this);
        insertWidget(nIndex, routeKey, treeWidget, onClick, position, toolTip, parentRouteKey);
        return treeWidget;
    }

    void insertWidget(int index, QString routeKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack onClicked, FluNavigationItemPosition postion, QString toolTip, QString parentRouteKey)
    {
        auto itf = m_items.find(routeKey);
        if (itf != m_items.end())
            return;

        _registerWidget(routeKey, parentRouteKey, widget, onClicked, toolTip);
        if (parentRouteKey.isEmpty())
        {
            FluNavigationTreeWidget* treeWidget = (FluNavigationTreeWidget*)(__widget(parentRouteKey));
        }
        else
        {
            _insertWidgetToLayout(index, widget, postion);
        }
    }

    void addSeparator(FluNavigationItemPosition position = FluNavigationItemPosition::TOP)
    {
        insertSeparator(-1, position);
    }

    void insertSeparator(int nIndex, FluNavigationItemPosition position = FluNavigationItemPosition::TOP)
    {
        FluNavigationSeparator* separator = new FluNavigationSeparator(this);
        _insertWidgetToLayout(nIndex, separator, position);
    }

    void _registerWidget(QString routeKey, QString parentRouteKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack onClicked, QString toopTip)
    {
        connect(widget, &FluNavigationWidget::clicked, this, &FluNavigationPanel::_onWidgetClicked);
        if (onClicked != nullptr)
        {
            connect(widget, &FluNavigationWidget::clicked, [&]() { onClicked(); });
        }

        widget->setProperty("routeKey", routeKey);
        widget->setProperty("parentRouteKey", parentRouteKey);
        m_items[routeKey] = new FluNavigationItem(routeKey, parentRouteKey, widget);

        if (m_displayMode == FluNavigationDisplayMode::EXPAND || m_displayMode == FluNavigationDisplayMode::MENU)
            widget->setCompacted(false);

        if (!toopTip.isEmpty())
        {
            widget->setToolTip(toolTip());
            widget->installEventFilter(new FluNavigationToolTipFilter(widget, 1000));
        }
    }

    void _insertWidgetToLayout(int nIndex, FluNavigationWidget* widget, FluNavigationItemPosition position)
    {
        switch (position)
        {
            case FluNavigationItemPosition::TOP:
            {
                widget->setParent(this);
                m_vTopLayout->insertWidget(nIndex, widget, 0, Qt::AlignTop);
            }
            break;
            case FluNavigationItemPosition::SCROLL:
            {
                widget->setParent(m_scrollWidget);
                m_vScrollLayout->insertWidget(nIndex, widget, 0, Qt::AlignTop);
            }
            break;
            case FluNavigationItemPosition::BOTTOM:
            {
                widget->setParent(this);
                m_vBottomLayout->insertWidget(nIndex, widget, Qt::AlignBottom);
            }
            break;
            default:
                break;
        }
        widget->show();
    }

    void removeWidget(QString routeKey)
    {
        auto itf = m_items.find(routeKey);
        if (itf == m_items.end())
            return;

        FluNavigationItem* item = itf->second;
        if (!item->m_parentRouteKey.isEmpty())
        {
            FluNavigationTreeWidget* treeWidget = (FluNavigationTreeWidget*)(__widget(item->m_parentRouteKey));
            treeWidget->removeChild(item->m_widget);
        }

        if (item->m_widget->metaObject()->className() == "FluNavigationTreeWidgetBase")
        {
            QList<FluNavigationWidget*> widgetList = item->m_widget->findChildren<FluNavigationWidget*>(Qt::FindChildrenRecursively);
            for (auto itList = widgetList.begin(); itList != widgetList.end(); itList++)
            {
                QString key = (*itList)->property("routeKey").toString();
                if (key.isEmpty())
                    continue;

                auto itf = m_items.find(key);
                if (itf != m_items.end())
                    m_items.erase(itf);

                (*itList)->deleteLater();
            }
        }

        item->m_widget->deleteLater();
    }

    void setMenuButtonVisible(bool bVisible)
    {
        m_bMenuButtonVisible = bVisible;
        if (m_menuButton != nullptr)
            m_menuButton->setVisible(bVisible);
    }

    void setReturnButtonVisible(bool bVisible)
    {
        m_bReturnButtonVisible = bVisible;
        if (m_returnButton != nullptr)
            m_returnButton->setVisible(bVisible);
    }

    void setCollapsible(bool bOn)
    {
        m_bCollapsible = bOn;
        if (!bOn && m_displayMode != FluNavigationDisplayMode::EXPAND)
            expand(false);
    }

    void setExpandWidth(int width)
    {
        if (width <= 42)
        {
            return;
        }

        m_expandWidth = width;
    }

    void expand(bool bUseAni = true)
    {
        _setWidgetCompacted(false);
        m_expandAni->setProperty("expand", true);
        m_menuButton->setToolTip("Close Navigation");  // 关闭导航栏
        // determine the display mode according to the width of window
        // https://learn.microsoft.com/en-us/windows/apps/design/controls/navigationview#default
        // int nExpandWidth = 1007 + m_expandWidth - 322;
        // if (window()->width() > nExpandWidth && !m_bMinimalEnabled && !m_bCollapsible)
        //{
        //	m_displayMode = FluNavigationDisplayMode::EXPAND;
        //}
        // else
        //{
        //	setProperty("menu", true);
        //	//setStyle(QApplication::style());
        //	m_displayMode = FluNavigationDisplayMode::MENU;
        //}

        // setExpandWidth(nExpandWidth);
        m_displayMode = FluNavigationDisplayMode::EXPAND;
        setFixedWidth(312);
    }

     // 折叠
    void collapse()
    {
        if (m_expandAni->state() == QPropertyAnimation::Running)
            return;

        for (auto itMap = m_items.begin(); itMap != m_items.end(); itMap++)
        {
            FluNavigationWidget* tmpWidget = itMap->second->m_widget;
            if (tmpWidget->metaObject()->className() == "FluNavigationTreeWidgetBase" && tmpWidget->isRoot())
            {
                FluNavigationTreeWidgetBase* treeWidgetBase = (FluNavigationTreeWidgetBase*)(tmpWidget);
                if (treeWidgetBase != nullptr)
                {
                    treeWidgetBase->setExpanded(false);
                }
            }
        }

        m_expandAni->setStartValue(QRect(pos(), QSize(width(), height())));
        m_expandAni->setEndValue(QRect(pos(), QSize(48, height())));
        m_expandAni->setProperty("expand", false);
        m_expandAni->start();

        m_menuButton->setToolTip("打开导航栏");// 打开导航栏
    }

    void toggle()
    {
        if (m_displayMode == FluNavigationDisplayMode::COMPACT || m_displayMode == FluNavigationDisplayMode::MINIMAL)
            expand();
        else
            collapse();
    }

     void setCurrentItem(QString routeKey)
    {
        if (routeKey.isEmpty())
            return;

        auto itf = m_items.find(routeKey);
        if (itf == m_items.end())
            return;

        for (auto itMap = m_items.begin(); itMap != m_items.end(); itMap++)
        {
            itMap->second->m_widget->setSelected(itMap->first == routeKey);
        }
    }

    void _onWidgetClicked()
    {
        FluNavigationWidget* widget = dynamic_cast<FluNavigationWidget*>(sender());
        if (widget->getSelectable() == false)
            return;

        QString routeKey = widget->property("routeKey").toString();
        setCurrentItem(routeKey);

        if (widget != m_menuButton && m_displayMode == FluNavigationDisplayMode::MENU && !widget->isLeaf())
        {
            collapse();
        }
    }

    void _onExpandAniFinished()
    {
    }

    void _setWidgetCompacted(bool bCompacted)
    {
        QList<FluNavigationWidget*> widgets = findChildren<FluNavigationWidget*>();
        for (auto itList = widgets.begin(); itList != widgets.end(); itList++)
        {
            (*itList)->setCompacted(bCompacted);
        }
    }

    int layoutMinHeight()
    {
        int topH = m_vTopLayout->minimumSize().height();
        int bottomH = m_vBottomLayout->minimumSize().height();
        int separatorH = 0;
        auto widgetList = findChildren<FluNavigationSeparator*>();
        for (auto itList = widgetList.begin(); itList != widgetList.end(); itList++)
        {
            separatorH += (*itList)->width();
        }

        int spacingH = 0;
        spacingH += m_vTopLayout->count() * m_vTopLayout->spacing();
        spacingH += m_vBottomLayout->count() * m_vBottomLayout->spacing();
        return 36 + topH + bottomH + separatorH + spacingH;
    }

    FluNavigationDisplayMode getDisplayMode()
    {
        return m_displayMode;
    }

    void setDisplayMode(FluNavigationDisplayMode displayMode)
    {
        m_displayMode = displayMode;
    }

  protected:
    void resizeEvent(QResizeEvent *event)
    {
        if (event->oldSize().height() == height())
            return;

        int topH = m_vTopLayout->minimumSize().height();
        int bottomH = m_vBottomLayout->minimumSize().height();

        int midH = height() - topH - bottomH - 20;
        m_scrollArea->setFixedHeight(qMax(midH, 36));
    }

    bool eventFilter(QObject *obj, QEvent *event)
    {
        if (obj != window() || !m_bCollapsible)
            return QFrame::eventFilter(obj, event);

        if (event->type() == QEvent::MouseButtonRelease)
        {
            QMouseEvent* mEvent = (QMouseEvent*)(event);
            if (!geometry().contains(mEvent->pos()) && m_displayMode == FluNavigationDisplayMode::MENU)
            {
                collapse();
            }
        }
        else if (event->type() == QEvent::Resize)
        {
            QResizeEvent* rEvent = (QResizeEvent*)(event);
            int nTmpWidth = rEvent->size().width();
            if (nTmpWidth < 1008 && m_displayMode == FluNavigationDisplayMode::EXPAND)
            {
                collapse();
            }
            else if (nTmpWidth >= 1008 && m_displayMode == FluNavigationDisplayMode::COMPACT && !m_bMenuButtonVisible)
            {
                expand();
            }
        }

        return QFrame::eventFilter(obj, event);
    }

  private:
    FluNavigationDisplayMode m_displayMode;
    FluNavigationHistory* m_history;
    FluNavigationItemLayout* m_vBottomLayout;
    FluNavigationItemLayout* m_vLayout;
    FluNavigationItemLayout* m_vScrollLayout;
    FluNavigationItemLayout* m_vTopLayout;
    FluNavigationToolButton* m_menuButton;
    FluNavigationToolButton* m_returnButton;
    std::map<QString, FluNavigationItem*> m_items;
    QPropertyAnimation* m_expandAni;
    QScrollArea* m_scrollArea;
    QWidget* m_parent;
    QWidget* m_scrollWidget;

    bool m_bCollapsible;
    bool m_bMenuButtonVisible;
    bool m_bMinimalEnabled;
    bool m_bReturnButtonVisible;
    int m_expandWidth;
};
