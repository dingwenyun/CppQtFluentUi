#include "FluIndicatorMenuItemDelegate.h"
#include <QPainter>
#include <QModelIndex>
#include <QStyleOptionViewItem>

void FluIndicatorMenuItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    FluMenuItemDelegate::paint(painter, option, index);
    if (!option.state & QStyle::State_Selected)
        return;

    painter->save();

    painter->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform | QPainter::TextAntialiasing);
    painter->setPen(Qt::NoPen);

    // theme color;
    QBrush brush;
    QColor color = QColor(0, 159, 170);
    brush.setColor(color);

    painter->setBrush(brush);
    painter->drawRoundedRect(6, 11 + option.rect.y(), 3, 15, 1.5, 1.5);

    painter->restore();
}
