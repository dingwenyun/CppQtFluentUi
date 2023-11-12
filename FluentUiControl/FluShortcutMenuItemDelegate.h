#pragma once

#include "FluMenuITemDelegate.h"
#include "../FluentUiUtils/FluentUiThemeUtils.h"
#include "../FluentUiUtils/FluentUiFontUtils.h"
#include <QFontMetrics>
#include <QStyleOptionViewItem>

class FluShortcutMenuItemDelegate : public FluMenuItemDelegate
{
    Q_OBJECT
  public:
    FluShortcutMenuItemDelegate(QObject *parent = nullptr) : FluMenuItemDelegate(parent)
    {
    }

  public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};
