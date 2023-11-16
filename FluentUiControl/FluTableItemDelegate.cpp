#include <QStyledItemDelegate>
#include <QTableView>
#include <QSet>
#include "FluLineEdit.h"

class FluTableItemDelegate : public QStyledItemDelegate
{
  public:
    FluTableItemDelegate(QTableView* parent = nullptr) : QStyledItemDelegate(parent)
    {
        m_margin = 2;
        m_hoverRow = -1;
        m_pressRow = -1;
    }

    void setHoverRow(int row)
    {
        m_hoverRow = row;
    }

    void setPressedRow(int row)
    {
        m_pressRow = row;
    }

    void setSelectedRows(QList<QModelIndex*> indexes)
    {
        m_selectedRows.clear();
        for (auto index : indexes)
        {
            m_selectedRows.insert(index->row());
            if (index->row() == m_pressRow)
                m_pressRow = -1;
        }
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QSize tmpSize = QStyledItemDelegate::sizeHint(option, index);
        tmpSize = tmpSize.grownBy( QMargins(0, m_margin, 0, m_margin));
        return tmpSize;
    }

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)
    {

    }

 protected:
   int m_margin;
   int m_hoverRow;
   int m_pressRow;
   QSet<int> m_selectedRows;
};