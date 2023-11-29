#include "FluShortcutMenuItemDelegate.h"

void FluShortcutMenuItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    FluMenuItemDelegate::paint(painter, option, index);
    if (_isSeparator(index))
        return;

    QAction *action = index.data(Qt::UserRole).value<QAction *>();
    if (action == nullptr || action->shortcut().isEmpty())
        return;

    painter->save();
    if (!option.state & QStyle::State_Enabled)
    {
        if (FluThemeUtils::getInstance()->getThemeMode() == FluThemeMode::Dark)
            painter->setOpacity(0.5);
        else
            painter->setOpacity(0.6);
    }

    QFont font = FluFontUtils::getFont(12);
    painter->setFont(font);

    QColor penColor;
    if (FluThemeUtils::getInstance()->getThemeMode() == FluThemeMode::Dark)
    {
        penColor = QColor(255, 255, 255, 200);
    }
    else
    {
        penColor = QColor(0, 0, 0, 153);
    }

    QFontMetrics fm = QFontMetrics(font);
    QString shortcut = action->shortcut().toString(QKeySequence::NativeText);
    int sw = fm.horizontalAdvance(shortcut);
    painter->translate(option.rect.width() - sw - 20, 0);

    QRect rect = QRect(0, option.rect.y(), sw, option.rect.height());
    painter->drawText(rect, Qt::AlignLeft | Qt::AlignVCenter, shortcut);
    painter->restore();
}
