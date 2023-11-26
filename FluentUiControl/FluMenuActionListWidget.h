#pragma once

#include <QListWidget>
#include "FluMenuAnimationType.h"
#include "FluShortcutMenuItemDelegate.h"
#include "FluMenuAnimationManager.h"
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"
#include "../FluentUiUtils/FluentUiLogUtils.h"
#include <QEvent>

class FluMenuActionListWidget : public QListWidget
{
    Q_OBJECT
  public:
    FluMenuActionListWidget(QWidget* parent = nullptr) : QListWidget(parent)
    {
        m_itemHeight = 28;
        m_maxVisibleItem = -1;

        setViewportMargins(0, 6, 0, 6);
        setTextElideMode(Qt::ElideNone);
        setDragEnabled(false);
        setMouseTracking(true);
        setIconSize(QSize(14, 14));
        setItemDelegate(new FluShortcutMenuItemDelegate(this));

        // setStyleSheet("FluMenuActionListWidget{font: 14px \"Segoe UI \", \"Microsoft YaHei\", \"PingFang SC\"}");
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluMenuActionListWidget.qss");
        setStyleSheet(qss);
    }

  public:
    void insertItem(int row, QListWidgetItem* item)
    {
        QListWidget::insertItem(row, item);
        adjustSize();
    }

    void addItem(QListWidgetItem* item)
    {
        QListWidget::addItem(item);
        adjustSize();
    }

    QListWidgetItem* takeItem(int row)
    {
        QListWidgetItem* item = QListWidget::takeItem(row);
        adjustSize();
        return item;
    }

    void adjustSize(QPoint pos = QPoint(), FluMenuAnimationType aniType = FluMenuAnimationType::NONE)
    {
        QSize wndSize = QSize(0, 0);
        for (int i = 0; i < count(); i++)
        {
            QSize tmpSizeHint = item(i)->sizeHint();
            wndSize.setWidth(qMax(tmpSizeHint.width(), wndSize.width()));
            wndSize.setHeight(tmpSizeHint.height() + wndSize.height());
        }

        viewport()->adjustSize();

        QMargins margins = viewportMargins();
        wndSize += QSize(margins.left() + margins.right() + 2, margins.top() + margins.bottom() + 3);
        if (m_maxVisibleItem > 0)
        {
            int nH = qMin(wndSize.height(), m_maxVisibleItem * m_itemHeight + margins.top() + margins.bottom() + 3);
            wndSize.setHeight(nH);
        }

        // LogDebug << "wndSize:" << wndSize << "itemCount:" << count();
        setFixedSize(wndSize);
        updateGeometries();
    }

    void setItemHeight(int nHeight)
    {
        if (nHeight == m_itemHeight)
            return;

        for (int i = 0; i < count(); i++)
        {
            QListWidgetItem* pItem = item(i);
            QWidget* pWidget = itemWidget(pItem);
            if (pWidget == nullptr)
                pItem->setSizeHint(QSize(pItem->sizeHint().width(), nHeight));
        }

        m_itemHeight = nHeight;
        adjustSize();
    }

    void setMaxVisibleItems(int nNum)
    {
        m_maxVisibleItem = nNum;
        adjustSize();
    }

    int getMaxVisibleItems()
    {
        return m_maxVisibleItem;
    }

    int heightForAnimation(QPoint pos, FluMenuAnimationType aniType)
    {
        int nH = itemsHeight();
        return nH;
    }

    int itemsHeight()
    {
        int nVisibleItemCount = count();
        if (m_maxVisibleItem > 0 && m_maxVisibleItem < count())
            nVisibleItemCount = m_maxVisibleItem;

        int nH = 0;
        for (int i = 0; i < count(); i++)
        {
            nH += item(i)->sizeHint().height();
        }

        nH += viewportMargins().top() + viewportMargins().bottom();
        return nH;
    }

    // void __event(QEvent* e)
    //{
    //    QListWidget::event(e);
    //}

    void hockEvent(QEvent* event)
    {
        QListWidget::event(event);
    }

  private:
    int m_itemHeight;
    int m_maxVisibleItem;
};
