#pragma once

#include "FluMenuItemDelegate.h"

class FluIndicatorMenuItemDelegate : public FluMenuItemDelegate
{
    Q_OBJECT
  public:
    FluIndicatorMenuItemDelegate(QObject *parent = nullptr) : FluMenuItemDelegate(parent)
    {
    }

  public:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};
