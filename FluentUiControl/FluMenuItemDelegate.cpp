#include "FluMenuITemDelegate.h"

bool FluMenuItemDelegate::_isSeparator(QModelIndex index) const
{
    return index.model()->data(index, Qt::DecorationRole) == "seperator";
}

void FluMenuItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (!_isSeparator(index))
        return QStyledItemDelegate::paint(painter, option, index);

    painter->save();
    int c = 0;
    if (FluThemeUtils::getInstance()->getThemeMode() != FluThemeMode::Dark)
        c = 0;
    else
        c = 255;

    QPen pen = QPen(QColor(c, c, c, 25), 1);
    pen.setCosmetic(true);
    painter->setPen(pen);

    QRect rect = option.rect;
    painter->drawLine(0, rect.y() + 4, rect.width() + 12, rect.y() + 4);
    painter->restore();
}
