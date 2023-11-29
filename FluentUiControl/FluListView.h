#pragma once

#include <QListView>

class FluListView : public QListView
{
  public:
    FluListView(QWidget *parent = nullptr) : QListView(parent)
    {
    }

    void setHoverRow(int row)
    {
    }

    void setPressedRow(int row)
    {
    }

    void setPressedRows(const QList<QModelIndex> &indexs)
    {
    }

    void setItemDelegate(QAbstractItemDelegate *delegate)
    {
    }

    void clearSelection()
    {
        QListView::clearSelection();
    }

    void setCurrentIndex(const QModelIndex &index)
    {
        QListView::setCurrentIndex(index);
    }

    void updateSelectedRows()
    {
    }

  protected:
    void leaveEvent(QEvent *event)
    {
        QListView::leaveEvent(event);
    }

    void resizeEvent(QResizeEvent *e)
    {
        QListView::resizeEvent(e);
    }

    void keyPressEvent(QKeyEvent *event)
    {
        QListView::keyPressEvent(event);
    }

    void mousePressEvent(QMouseEvent *event)
    {
    }

    void mouseReleaseEvent(QMouseEvent *e)
    {
    }

  private:
};
