#pragma once

#include <QTableWidget>
#include <QShowEvent>
#include <QHeaderView>
#include "FluTableView.h"
#include "FluTableItemDelegate.h"
#include "FluSmoothScrollDelegate.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"

class FluTableWidget : public QTableWidget
{
    Q_OBJECT
    Q_PROPERTY(bool selectRightClickedRow READ getSelectRightClickedRow WRITE setSelectRightClickedRow)
  public:
    FluTableWidget(QWidget *parent = nullptr) : QTableWidget(parent)
    {
        m_tableItemDelegate = new FluTableItemDelegate(this);
        m_scrollDelegate = new FluSmoothScrollDelegate(this);
        m_bSelectRightClickedRow = false;

        setShowGrid(false);
        setMouseTracking(true);
        setItemDelegate(m_tableItemDelegate);
        // setSelectionBehavior()

        QString qss = FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluTableTableWiget.qss");
        setStyleSheet(qss);

        connect(this, &FluTableWidget::entered, [=](const QModelIndex &index) { setHoverRow(index.row()); });
        connect(this, &FluTableWidget::pressed, [=](const QModelIndex &index) { setPressedRow(index.row()); });
        connect(verticalHeader(), &QHeaderView::sectionClicked, [=](int nRow) { selectRow(nRow); });
    }

    void setHoverRow(int row)
    {
        m_tableItemDelegate->setHoverRow(row);
        viewport()->update();
    }

    void setPressedRow(int row)
    {
        m_tableItemDelegate->setPressedRow(row);
        viewport()->update();
    }

    bool getSelectRightClickedRow()
    {
        return m_bSelectRightClickedRow;
    }

    void setSelectRightClickedRow(bool bSelected)
    {
        m_bSelectRightClickedRow = bSelected;
    }

    void setSelectedRows(const QList<QModelIndex> &indexs)
    {
        m_tableItemDelegate->setSelectedRows(indexs);
        viewport()->update();
    }

    void setItemDelegate(FluTableItemDelegate *delegate)
    {
        QTableView::setItemDelegate(delegate);
        m_tableItemDelegate = delegate;
    }

    void selectAll()
    {
        QTableView::selectAll();
        updateSelectedRows();
    }

    void selectRow(int row)
    {
        QTableView::selectRow(row);
        updateSelectedRows();
    }

    void setCurrentIndex(const QModelIndex &index)
    {
        QTableView::setCurrentIndex(index);
        updateSelectedRows();
    }

    void updateSelectedRows()
    {
        setSelectedRows(selectedIndexes());
    }

    void setCurrentCell(int row, int column, QItemSelectionModel::SelectionFlags command)
    {
        QTableWidget::setCurrentCell(row, column, command);
        updateSelectedRows();
    }

    void setCurrentItem(QTableWidgetItem *item)
    {
        QTableWidget::setCurrentItem(item);
        updateSelectedRows();
    }

    void setCurrentItem(QTableWidgetItem *item, QItemSelectionModel::SelectionFlags command)
    {
        QTableWidget::setCurrentItem(item, command);
        updateSelectedRows();
    }

    void setBorderVisible(bool bVisible)
    {
        setProperty("isBorderVisible", bVisible);
    }

    void setBorderRadius(int radius)
    {
        // QString qss = QString("QTableView{border-radius:%1px}").arg(radius);
        // setStyleSheet(qss);
        setProperty("border-radius", radius);
    }

  protected:
    void showEvent(QShowEvent *event)
    {
        QTableView::showEvent(event);
        resizeRowsToContents();
    }

    void leaveEvent(QEvent *event)
    {
        QTableView::leaveEvent(event);
        setHoverRow(-1);
    }

    void resizeEvent(QResizeEvent *event)
    {
        QTableView::resizeEvent(event);
        viewport()->update();
    }

    void keyPressEvent(QKeyEvent *event)
    {
        QTableView::keyPressEvent(event);
        viewport()->update();
    }

    void mousePressEvent(QMouseEvent *event)
    {
        if (event->button() == Qt::LeftButton || m_bSelectRightClickedRow)
            return QTableView::mousePressEvent(event);

        QModelIndex modelIndex = indexAt(event->pos());
        if (modelIndex.isValid())
            setPressedRow(modelIndex.row());
    }

    void mouseReleaseEvent(QMouseEvent *event)
    {
        QTableView::mouseReleaseEvent(event);
        updateSelectedRows();
        QModelIndex modelIndex = indexAt(event->pos());
        int row = modelIndex.row();
        if (row < 0 || event->button() == Qt::RightButton)
        {
            setPressedRow(-1);
        }
    }

  private:
    FluSmoothScrollDelegate *m_scrollDelegate;
    FluTableItemDelegate *m_tableItemDelegate;
    bool m_bSelectRightClickedRow;
};
