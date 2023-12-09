#pragma once

#include <QStyledItemDelegate>
#include "../FluentUiUtils/FluFontUtils.h"
#include "../FluentUiUtils/FluThemeUtils.h"
#include <QStyleOptionViewItem>
#include <QListView>
#include <QPainter>
#include <QScrollBar>

class FluListItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
  public:
    FluListItemDelegate(QListView* parent) : QStyledItemDelegate(parent)
    {
        m_margin = 2;
        m_hoverRow = -1;
        m_pressedRow = -1;
    }

    void setHoverRow(int row)
    {
        m_hoverRow = row;
    }

    void setPressedRow(int row)
    {
        m_pressedRow = row;
    }

    void setSelectedRows(QList<QModelIndex> indexes)
    {
        m_selectedRows.clear();
        for (auto index : indexes)
        {
            m_selectedRows.insert(index.row());
            if (index.row() == m_pressedRow)
                m_pressedRow = -1;
        }
    }

    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QSize tmpSize = QStyledItemDelegate::sizeHint(option, index);
        tmpSize = tmpSize.grownBy(QMargins(0, m_margin, 0, m_margin));
        return tmpSize;
    }


    void initStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const
    {
        QStyledItemDelegate::initStyleOption(option, index);
        option->font = FluFontUtils::getFont(13);

        QColor textColor;
        if (FluThemeUtils::isDarkMode())
            textColor = Qt::white;
        else
            textColor = Qt::black;

        //QColor textBrush = index.data(Qt::ForegroundRole).value<QColor>();
        QVariant variant = index.data(Qt::ForegroundRole);
        if (!variant.isNull())
            textColor = variant.value<QColor>();

        option->palette.setColor(QPalette::Text, textColor);
        option->palette.setColor(QPalette::HighlightedText, textColor);
    }

    void drawBackground(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        painter->drawRoundedRect(option.rect, 5, 5);
    }

    void drawIndicator(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        int nY = option.rect.y();
        int nH = option.rect.height();
        int pH = 0;
        if (m_pressedRow == index.row())
            pH = 0.35 * nH;
        else
            pH = 0.257 * nH;

        painter->setBrush(FluThemeUtils::getThemeColor());
        painter->drawRoundedRect(0, pH + nY, 3, nH - 2 *pH, 1.5, 1.5);
    }

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QStyledItemDelegate::paint(painter, option, index);

        painter->save();
        painter->setPen(Qt::NoPen);
        painter->setRenderHint(QPainter::Antialiasing);
        painter->setClipping(true);
        painter->setClipRect(option.rect);

        // option.rect.adjust(0, m_margin, 0, -m_margin);
        bool bHover = (m_hoverRow == index.row());
        bool bPressed = (m_pressedRow == index.row());
        bool bAlternate = index.row() % 2 == 0;

        int c = 255;
        int alpha = 0;
        bool bDarkTheme = FluThemeUtils::isDarkMode();
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
          //  else if (bAlternate)
          //  {
          //      alpha = 5;
          //  }
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

            auto listView = (QListView *)(parent());
            if (index.column() == 0 && listView->horizontalScrollBar()->value() == 0)
                drawIndicator(painter, option, index);
        }

        painter->setBrush(QColor(c, c, c, alpha));
        drawBackground(painter, option, index);
        painter->restore();
    }

  private:
    int m_margin;
    int m_hoverRow;
    int m_pressedRow;
    QSet<int> m_selectedRows;
};
