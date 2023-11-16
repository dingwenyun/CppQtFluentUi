#include "FluIndicatorMenuItemDelegate.h"
#include <QPainter>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include "../FluentUiUtils/FluentUiLogUtils.h"

void FluIndicatorMenuItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);
    if (!(option.state & QStyle::State_Selected))
    {
        // LogDebug << "row:" << index.row() << "not selected!";
        return;
    }
    // LogDebug << "row:" << index.row() << "selected!";

    painter->save();

    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);
    painter->setPen(Qt::NoPen);

    // theme color;
    QColor color = QColor(0, 159, 170);
    QBrush brush(color);  // not use brush.setColor
                          // can't vaild

    painter->setBrush(brush);
    painter->drawRoundedRect(6, 11 + option.rect.y(), 3, 15, 1.5, 1.5);

    painter->restore();
}
