#pragma once

#include "FluScrollArea.h"
#include <QWidget>
#include "FluToolBar.h"
#include <QVBoxLayout>
#include "FluExampleCard.h"
#include <QScrollBar>
#include "../FluentUiUtils/FluStyleSheetUitls.h"

class FluGalleryInterface : public FluScrollArea
{
    Q_OBJECT
  public:
    FluGalleryInterface(QString title, QString subTitle, QWidget* parent = nullptr) : FluScrollArea(parent)
    {
        m_view = new QWidget(this);
        m_toolBar = new FluToolBar(title, subTitle, this);
        m_vBoxLayout = new QVBoxLayout(m_view);

        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setViewportMargins(0, m_toolBar->height(), 0, 0);
        setWidget(m_view);
        setWidgetResizable(true);

        m_vBoxLayout->setSpacing(30);
        m_vBoxLayout->setAlignment(Qt::AlignTop);
        m_vBoxLayout->setContentsMargins(36, 20, 36, 36);

        m_view->setObjectName("view");
        // stylesheet

        QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluGalleryInterface.qss");
        setStyleSheet(qss);
    }

    FluExampleCard* addExampleCard(QString title, QWidget* widget, QString sourcePath, int stretch = 0)
    {
        FluExampleCard* card = new FluExampleCard(title, widget, sourcePath, stretch, m_view);
        m_vBoxLayout->addWidget(card, 0, Qt::AlignTop);
        return card;
    }

    void srollToCard(int nIndex)
    {
        QWidget* widget = m_vBoxLayout->itemAt(nIndex)->widget();
        verticalScrollBar()->setValue(widget->y());
    }

  protected:
    void resizeEvent(QResizeEvent* event)
    {
        FluScrollArea::resizeEvent(event);
        m_toolBar->resize(width(), m_toolBar->height());
    }

  protected:
    QWidget* m_view;
    FluToolBar* m_toolBar;
    QVBoxLayout* m_vBoxLayout;
};
