#pragma once

#include <QListWidget>
#include "FluSmoothScrollDelegate.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include "FluListItemDelegate.h"

class FluListWidget : public QListWidget
{
	Q_OBJECT
    Q_PROPERTY(bool selectRightClickedRow READ getSelectRightClickedRow WRITE setSelectRightClickedRow)
  public:
    FluListWidget(QWidget* parent = nullptr) : QListWidget(parent)
    {
        // listItemDelegate
        m_delegate = new FluListItemDelegate(this);
        m_scrollDelegate = new FluSmoothScrollDelegate(this);
        m_bSelectRightClickedRow = false;

        setItemDelegate(m_delegate);
        setMouseTracking(true);

        
        QString qss = FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluListWidget.qss");
        setStyleSheet(qss);

        connect(this, &FluListWidget::entered, [=](const QModelIndex& index) { setHoverRow(index.row()); });
        connect(this, &FluListWidget::pressed, [=](const QModelIndex& index) { setPressedRow(index.row()); });
    }

    void setHoverRow(int row)
    {
        m_delegate->setHoverRow(row);
        viewport()->update();
    }

    void setPressedRow(int row)
    {
        m_delegate->setPressedRow(row);
        viewport()->update();
    }

    
    void setSelectedRows(QList<QModelIndex> indexs)
    {
        m_delegate->setSelectedRows(indexs);
        viewport()->update();
    }


    void setItemDelegate(FluListItemDelegate* delegate)
    {
        m_delegate = delegate;
        QListWidget::setItemDelegate(delegate);
    }

    void clearSelection()
    {
        QListWidget::clearSelection();
        updateSelectedRows();
    }

    void setCurrentIndex(const QModelIndex &index)
    {
        QListWidget::setCurrentIndex(index);
        updateSelectedRows();
    }
    

    void updateSelectedRows()
    {
        setSelectedRows(selectedIndexes());
    }

    bool getSelectRightClickedRow()
    {
        return m_bSelectRightClickedRow;
    }

    void setSelectRightClickedRow(bool bSelectRightClickedRow)
    {
        m_bSelectRightClickedRow = bSelectRightClickedRow;
    }

    void setCurrentItem(QListWidgetItem *item, QItemSelectionModel::SelectionFlags command)
    {
        setCurrentRow(row(item), command);
    }

    void setCurrentRow(int row, QItemSelectionModel::SelectionFlags command)
    {
        QListWidget::setCurrentRow(row, command);
        updateSelectedRows();
    }

    protected:
      void leaveEvent(QEvent *event)
      {
          QListWidget::leaveEvent(event);
          setHoverRow(-1);
      }

      void resizeEvent(QResizeEvent *e)
      {
          QListWidget::resizeEvent(e);
          viewport()->update();
      }

      void keyPressEvent(QKeyEvent *event)
      {
          QListWidget::keyPressEvent(event);
          updateSelectedRows();
      }

      void mousePressEvent(QMouseEvent *event)
      {
          if (event->button() == Qt::LeftButton || m_bSelectRightClickedRow)
              return QListWidget::mousePressEvent(event);

          QModelIndex modelIndex = indexAt(event->pos());
          if (modelIndex.isValid())
              setPressedRow(modelIndex.row());

          return QListWidget::mousePressEvent(event);
      }

      void mouseReleaseEvent(QMouseEvent *e)
      {
          QListWidget::mouseReleaseEvent(e);
          updateSelectedRows();
          if (indexAt(e->pos()).row() < 0 || e->button() == Qt::RightButton)
          {
              setPressedRow(-1);
          }
      }

    private:
        FluSmoothScrollDelegate* m_scrollDelegate;
        bool m_bSelectRightClickedRow;
        FluListItemDelegate* m_delegate;
};
