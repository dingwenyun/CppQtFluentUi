#pragma once

#include <QStyledItemDelegate>
#include <QTreeView>
#include "../FluentUiUtils/FluFontUtils.h"
#include "../FluentUiUtils/FluThemeUtils.h"
#include <QPainter>
#include <QStyleOptionViewItem>
#include <QScrollBar>

class FluTreeItemDelegate : public QStyledItemDelegate
{
	Q_OBJECT
  public:
    FluTreeItemDelegate(QTreeView* parent) : QStyledItemDelegate(parent)
    {
    }

    void initStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const
    {
        QStyledItemDelegate::initStyleOption(option, index);

        auto fontRole = index.data(Qt::FontRole);
        if (fontRole.isValid())
            option->font = fontRole.value<QFont>();
        else
            option->font = FluFontUtils::getFont(13);

        QColor textColor;
        if (FluThemeUtils::isDarkMode())
            textColor = Qt::white;
        else
            textColor = Qt::black;

        auto goregroundRole = index.data(Qt::ForegroundRole);
        if (goregroundRole.isValid())
            textColor = goregroundRole.value<QColor>();

        option->palette.setColor(QPalette::Text, textColor);
        option->palette.setColor(QPalette::HighlightedText, textColor);

    }

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QStyledItemDelegate::paint(painter, option, index);
        auto treeView = (QTreeView *)parent();

        painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

        bool bSelected = option.state & QStyle::State_Selected || option.state & QStyle::State_MouseOver;
        if (!bSelected)
            return;

        painter->save();
        painter->setPen(Qt::NoPen);

        QColor bgColor;
        if (FluThemeUtils::isDarkMode())
        {
            bgColor = QColor(255, 255, 255, 9);
        }
        else
        {
            bgColor = QColor(0, 0, 0, 9);
        }
        painter->setBrush(bgColor);
        painter->drawRoundedRect(4, option.rect.y() + 2, treeView->width() - 8, option.rect.height() - 4, 4, 4); 
        if (option.state & QStyle::State_Selected && treeView->horizontalScrollBar()->value() == 0)
        {
            painter->setBrush(FluThemeUtils::getThemeColor());
            painter->drawRoundedRect(4, 9 + option.rect.y(), 3, option.rect.height() - 4 - 13, 1.5, 1.5); 
        }

        painter->restore();
    }

};
