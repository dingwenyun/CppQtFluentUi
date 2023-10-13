#pragma once

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "FluNavigationWidget.h"
#include "FluNavigationPanel.h"
#include "FluNavigationBarPushButton.h"
#include <map>

class FluNavigationBar : public QWidget
{
  public:
    FluNavigationBar(QWidget* parent = nullptr) : QWidget(parent)
    {
        m_scrollArea = new QScrollArea(this);
        m_scrollAreaWidget = new QWidget();

        m_vBoxLayout = new QVBoxLayout(this);
        m_topLayout = new QVBoxLayout();
        m_bottomLayout = new QVBoxLayout();
        m_scrollLayout = new QVBoxLayout();

        // items

        __initWidget();
    }

    void __initWidget()
    {
        resize(48, height());
        setAttribute(Qt::WA_StyledBackground);
        window()->installEventFilter(this);

        m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        m_scrollArea->setWidget(m_scrollAreaWidget);
        m_scrollArea->setWidgetResizable(true);

        m_scrollAreaWidget->setObjectName("scrollWidget");
        // style sheet mark it!

        __initLayout();
    }

    void __initLayout()
    {
        m_vBoxLayout->setContentsMargins(0, 5, 0, 5);
        m_topLayout->setContentsMargins(4, 0, 4, 0);
        m_bottomLayout->setContentsMargins(4, 0, 4, 0);
        m_scrollLayout->setContentsMargins(4, 0, 4, 0);

        m_vBoxLayout->setSpacing(4);
        m_topLayout->setSpacing(4);
        m_bottomLayout->setSpacing(4);
        m_scrollLayout->setSpacing(4);

        m_vBoxLayout->addLayout(m_topLayout, 0);
        m_vBoxLayout->addWidget(m_scrollArea);
        m_vBoxLayout->addLayout(m_bottomLayout, 0);

        m_vBoxLayout->setAlignment(Qt::AlignTop);
        m_topLayout->setAlignment(Qt::AlignTop);
        m_scrollArea->setAlignment(Qt::AlignTop);
        m_bottomLayout->setAlignment(Qt::AlignBottom);
    }

    FluNavigationWidget* widget(const QString& routeKey)
    {
        auto itf = m_items.find(routeKey);
        if (itf == m_items.end())
            return nullptr;

        return itf->second;
    }

    void addItem(const QString& routeKey,
                 const QPixmap icon,
                 QString text,
                 FluNavigationWidgetClickedCallBack onClick = nullptr,
                 bool bSelectable = true,
                 QPixmap selectedIcon = QPixmap(),
                 FluNavigationItemPosition postion = FluNavigationItemPosition::TOP)
    {
        insertItem(-1, routeKey, icon, text, onClick, bSelectable, selectedIcon, postion);
    }

    void addWidget(QString routeKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack onClick = nullptr, FluNavigationItemPosition positon = FluNavigationItemPosition::TOP)
    {
        insertWidget(-1, routeKey, widget, onClick, positon);
    }

    FluNavigationBarPushButton* insertItem(int nIndex,
                                           QString routeKey,
                                           QPixmap icon,
                                           QString text,
                                           FluNavigationWidgetClickedCallBack onClick = nullptr,
                                           bool bSelectable = true,
                                           QPixmap selectedIcon = QPixmap(),
                                           FluNavigationItemPosition position = FluNavigationItemPosition::TOP)
    {
        auto itf = m_items.find(routeKey);
        if (itf != m_items.end())
            return;

        FluNavigationBarPushButton* btn = new FluNavigationBarPushButton(icon, text, bSelectable, selectedIcon, this);
        insertWidget(nIndex, routeKey, btn, onClick, position);
        return btn;
    }

    void insertWidget(int nIndex, QString routeKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack onClick = nullptr, FluNavigationItemPosition position = FluNavigationItemPosition::TOP)
    {
        auto itf = m_items.find(routeKey);
        if (itf != m_items.end())
            return;

        _registerWidget(routeKey, widget, onClick);
        _insertWidgetToLayout(nIndex, widget, position);
    }

    void _registerWidget(QString routeKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack onClick = nullptr)
    {
        connect(widget, &FluNavigationWidget::clicked, this, &FluNavigationBar::_onWidgetClicked);
        if (onClick != nullptr)
        {
            connect(widget, &FluNavigationWidget::clicked, [&](bool) { onClick(); });
        }

        widget->setProperty("routeKey", routeKey);
        m_items[routeKey] = widget;
    }

    void _insertWidgetToLayout(int nIndex, FluNavigationWidget* widget, FluNavigationItemPosition position = FluNavigationItemPosition::TOP)
    {
        switch (position)
        {
            case FluNavigationItemPosition::TOP:
            {
                widget->setParent(this);
                m_topLayout->insertWidget(nIndex, widget, 0, Qt::AlignTop | Qt::AlignHCenter);
                break;
            }
            case FluNavigationItemPosition::SCROLL:
            {
                widget->setParent(m_scrollAreaWidget);
                m_scrollLayout->insertWidget(nIndex, widget, 0, Qt::AlignTop | Qt::AlignHCenter);
                break;
            }
            case FluNavigationItemPosition::BOTTOM:
            {
                widget->setParent(this);
                m_bottomLayout->insertWidget(nIndex, widget, 0, Qt::AlignTop | Qt::AlignHCenter);
                break;
            }
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

        FluNavigationWidget* widget = itf->second;
        widget->deleteLater();
        // mark it!
    }

    void setCurrentItem(QString routeKey)
    {
        auto itf = m_items.find(routeKey);
        if (itf == m_items.end())
            return;

        for (auto elm : m_items)
        {
            if (elm.first == routeKey)
                elm.second->setSelected(true);
            else
                elm.second->setSelectable(false);
        }
    }

    void _onWidgetClicked()
    {
        FluNavigationWidget* widget = (FluNavigationWidget*)sender();
        if (widget->getSelectable())
            setCurrentItem(widget->property("routeKey").toString());
    }

  private:
    QScrollArea* m_scrollArea;
    QWidget* m_scrollAreaWidget;
    QVBoxLayout* m_vBoxLayout;
    QVBoxLayout* m_topLayout;
    QVBoxLayout* m_bottomLayout;
    QVBoxLayout* m_scrollLayout;
    std::map<QString, FluNavigationWidget*> m_items;
};
