#pragma once

#include <QStyledItemDelegate>
#include <QTableView>
#include <QStyleOptionViewItem>
#include <QModelIndex>
#include <QFont>
#include <QBrush>
#include <QTableView>
#include <QScrollBar>
#include "FluLineEdit.h"
#include "../FluentUiUtils/FluThemeUtils.h"
#include "../FluentUiUtils/FluThemeUtils.h"

class FluTableItemDelegate : public QStyledItemDelegate
{
  public:
    FluTableItemDelegate(QTableView *parent) : QStyledItemDelegate(parent)
    {
        m_margin = 2;
        m_hoverRow = -1;
        m_pressRow = -1;
        m_tableView = parent;
    }

    void setHoverRow(int row)
    {
        m_hoverRow = row;
    }

    void setPressedRow(int row)
    {
        m_pressRow = row;
    }

    void setSelectedRows(const QList<QModelIndex> &indexs)
    {
        m_selectedRows.clear();
        for (auto index : indexs)
        {
            m_selectedRows.insert(index.row());
            if (index.row() == m_pressRow)
                m_pressRow = -1;
        }
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QSize tmpSize = QStyledItemDelegate::sizeHint(option, index);
        tmpSize = tmpSize.grownBy(QMargins(0, m_margin, 0, m_margin));
        return tmpSize;
    }

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        FluLineEdit *lineEdit = new FluLineEdit(parent);
        lineEdit->setProperty("transparent", false);
        lineEdit->setStyle(QApplication::style());
        lineEdit->setText(option.text);
        lineEdit->setClearButtonEnabled(true);
        return lineEdit;
    }

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QRect tmpRect = option.rect;
        int nX = qMax(8, tmpRect.x());
        int nY = tmpRect.y() + (tmpRect.height() - editor->height()) / 2;
        int nW = tmpRect.width();
        if (index.column() == 0)
            nW = nW - 8;

        int nH = tmpRect.height();
        editor->setGeometry(nX, nY, nW, nH);

        //   int nTmpW = editor->width();
        //   int nTmpH = editor->height();
    }

    void initStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const
    {
        QStyledItemDelegate::initStyleOption(option, index);
        option->font = index.data(Qt::FontRole).value<QFont>();

        QColor textColor;
        if (FluThemeUtils::getInstance()->getThemeMode() == FluThemeMode::Dark)
        {
            textColor = Qt::white;
        }
        else
        {
            textColor = Qt::black;
        }

        option->palette.setColor(QPalette::Text, textColor);
        option->palette.setColor(QPalette::HighlightedText, textColor);
    }

    void drawBackground(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        int nR = 5;
        if (index.column() == 0)
        {
            QRect rect = option.rect.adjusted(4, 0, 6, 0);
            painter->drawRoundedRect(rect, nR, nR);
        }
        else if (index.column() == (index.model()->columnCount(index.parent()) - 1))
        {
            QRect rect = option.rect.adjusted(-6, 0, -4, 0);
            painter->drawRoundedRect(rect, nR, nR);
        }
        else
        {
            QRect rect = option.rect.adjusted(-1, 0, 1, 0);
            painter->drawRect(rect);
        }
    }

  protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QStyledItemDelegate::paint(painter, option, index);
        // QTableView *tableView = (QTableView *)(parent());

        painter->save();
        painter->setPen(Qt::NoPen);
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setClipping(true);
        painter->setClipRect(option.rect);

        // option.rect.adjust(0, m_margin, 0, -m_margin);
        bool bHover = (m_hoverRow == index.row());
        bool bPressed = (m_pressRow == index.row());
        bool bAlternate = index.row() % 2 == 0;

        int c = 255;
        int alpha = 0;
        bool bDarkTheme = FluThemeUtils::getInstance()->getThemeMode() == FluThemeMode::Dark;
        if (bDarkTheme)
        {
            c = 255;
        }
        else
        {
            c = 0;
        }

        auto itf = m_selectedRows.find(index.row());
        if (itf == m_selectedRows.end())
        {
            if (bPressed)
            {
                if (bDarkTheme)
                    alpha = 9;
                else
                    alpha = 6;
            }
            else if (bHover)
            {
                alpha = 12;
            }
            else if (bAlternate)
            {
                alpha = 5;
            }
            else
            {
                alpha = 0;
            }
        }
        else
        {
            if (bPressed)
            {
                if (bDarkTheme)
                {
                    alpha = 15;
                }
                else
                {
                    alpha = 9;
                }
            }
            else if (bHover)
            {
                alpha = 25;
            }
            else if (bAlternate)
            {
                alpha = 17;
            }
            else
            {
                alpha = 0;
            }
        }

        painter->setBrush(QColor(c, c, c, alpha));
        drawBackground(painter, option, index);

        painter->restore();
    }

  protected:
    int m_margin;
    int m_hoverRow;
    int m_pressRow;
    QTableView *m_tableView;
    QSet<int> m_selectedRows;
};
