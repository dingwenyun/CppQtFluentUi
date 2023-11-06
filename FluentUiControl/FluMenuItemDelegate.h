#pragma once

#include <QStyledItemDelegate>
#include <QPainter>
#include "../FluentUiUtils/FluentUiThemeUtils.h"
#include <QStyleOptionViewItem>
#include <QModelIndex>

class FluMenuItemDelegate : public QStyledItemDelegate
{
  public:
    FluMenuItemDelegate(QWidget *parent) : QStyledItemDelegate(parent)
    {
    }

  public:
    bool _isSeparator(QModelIndex index);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index);
};
