#pragma once

#include "FluDef.h"
#include "FluNavigationPanel.h"
#include "../FluentUiUtils/FluentUiLogUtils.h"
#include <QFunctionPointer>
#include <QFrame>
#include <QStyleOption>
#include <QHBoxLayout>

class FluNavigationInterface : public QWidget
{
    Q_OBJECT
  public:
    FluNavigationInterface(QWidget* parent = nullptr, bool bShowMenuButton = true, bool bShowReturnButton = false, bool bCollapsible = true);
  signals:
    void displayModeChanged(FluNavigationDisplayMode displayMode);

  public:
    FluNavigationTreeWidget* addItem(QString routeKey,
                                     QPixmap icon,
                                     QString text,
                                     FluNavigationWidgetClickedCallBack onClick = nullptr,
                                     bool bSelectable = true,
                                     FluNavigationItemPosition position = FluNavigationItemPosition::TOP,
                                     QString toolTip = "",
                                     QString parentRouteKey = "");

  public:
    void addWidget(QString routeKey, FluNavigationWidget* widget, FluNavigationWidgetClickedCallBack onClick, FluNavigationItemPosition position = FluNavigationItemPosition::TOP, QString tooltip = "", QString parentRouteKey = "");

    FluNavigationTreeWidget* insertItem(int nIndex,
                                        QString routeKey,
                                        QPixmap icon,
                                        QString text,
                                        FluNavigationWidgetClickedCallBack onClick = nullptr,
                                        bool bSelectable = true,
                                        FluNavigationItemPosition position = FluNavigationItemPosition::TOP,
                                        QString toolTip = "",
                                        QString parentRouteKey = "")
    {
        FluNavigationTreeWidget* treeWidget = m_panel->insertItem(nIndex, routeKey, icon, text, onClick, bSelectable, position, toolTip, parentRouteKey);
       // if (treeWidget != nullptr)
           // treeWidget->setMinimumHeight(m_panel->layoutMinHeight());
        return treeWidget;
    }

    void insertWidget(int nIndex,
                      QString routeKey,
                      FluNavigationWidget* widget,
                      FluNavigationWidgetClickedCallBack onClick = nullptr,
                      FluNavigationItemPosition position = FluNavigationItemPosition::TOP,
                      QString toolTip = "",
                      QString parentRouteKey = "");

    void addSeparator(FluNavigationItemPosition position = FluNavigationItemPosition::TOP);

    void insertSeparator(int nIndex, FluNavigationItemPosition position = FluNavigationItemPosition::TOP)
    {
        m_panel->insertSeparator(nIndex, position);
       //setMinimumHeight(m_panel->layoutMinHeight());
    }

    void removeWidget(QString routeKey)
    {
        m_panel->removeWidget(routeKey);
    }

    void setCurrentItem(QString name)
    {
        m_panel->setCurrentItem(name);
    }

    void setExpandWidth(int width)
    {
        m_panel->setExpandWidth(width);
    }

    void setMenuButtonVisible(bool bVisible)
    {
        m_panel->setMenuButtonVisible(bVisible);
    }

    void setCollapsible(bool bCollapsible)
    {
    }

    FluNavigationWidget* __widget(QString routeKey)
    {
        return m_panel->__widget(routeKey);
    }

  protected:
    bool eventFilter(QObject* obj, QEvent* event)
    {
        if (obj != m_panel && event->type() != QEvent::Resize)
            return eventFilter(obj, event);

        if (m_panel->getDisplayMode() != FluNavigationDisplayMode::MENU)
        {
           // QResizeEvent* rEvent = (QResizeEvent*)(event);
            //if (rEvent->oldSize().width() != rEvent->size().width())
           //     setFixedWidth(rEvent->size().width());
        }

        return QWidget::eventFilter(obj, event);
    }

    void resizeEvent(QResizeEvent* event)
    {
        LogDebug << "w:" << width() << ",h:" << height() << "; panel w:" << m_panel->width() << ",panel h:" << m_panel->height();
        m_panel->setFixedHeight(height());
    }

    ///*void paintEvent(QPaintEvent* event)
    //{
    //	QStyleOption opt;
    //	opt.initFrom(this);
    //	QPainter painter(this);
    //	style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);
    //}*/
  private:
    FluNavigationPanel* m_panel;
    QVBoxLayout* m_vLayout;
};
