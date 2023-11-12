#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include "../FluentUiUtils/FluentUiThemeUtils.h"
#include <QStyleOptionViewItem>
#include <QModelIndex>

class FluMenuItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
  public:
    FluMenuItemDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent)
    {
    }

  public:
    bool _isSeparator(QModelIndex index) const;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    // void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index);
};
