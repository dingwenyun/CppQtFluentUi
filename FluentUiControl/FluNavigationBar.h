#pragma once

#include <QWidget>
#include <QScrollArea>
#include <QVBoxLayout>
#include "FluNavigationWidget.h"

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
