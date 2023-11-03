#pragma once

#include <QListWidget>
#include "FluShortcutMenuItemDelegate.h"

class FluMenuActionListWidget : public QListWidget
{
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

        setStyleSheet("FluMenuActionListWidget{font: 14px \"Segoe UI \", \"Microsoft YaHei\", \"PingFang SC\"}");

        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }

  public:
    void insertItem(int row, QListWidgetItem* item)
    {
        QListWidget::insertItem(row, item);
        adjustSize();
    }

    void addItem(QListWidgetItem *item)
    {
        QListWidget::addItem(item);
        adjustSize();
    }

    QListWidgetItem* takeItem(int row)
    {
        QListWidgetItem *item = QListWidget::takeItem(row);
        adjustSize();
        return item;
    }

    void adjustSize()
    {
        QSize size = QSize(0, 0);
        for (int i = 0; i < count(); i++)
        {
            QSize tmpSizeHint = item(i)->sizeHint();
            tmpSizeHint.setWidth(qMax(tmpSizeHint.width(), size.width()));
            tmpSizeHint.setHeight(tmpSizeHint.height() + size.height());
        }


    }
  private:
    int m_itemHeight;
    int m_maxVisibleItem;
};
