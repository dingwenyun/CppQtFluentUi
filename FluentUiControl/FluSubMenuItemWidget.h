#pragma once

#include <QWidget>
#include <QListWidgetItem>
#include <QPainter>
#include "../FluentUiUtils/FluentUiIconUtils.h"

class FluSubMenuItemWidget : public QWidget
{
  public:
    FluSubMenuItemWidget(QMenu* menu, QListWidgetItem* item, QWidget* parent = nullptr);
  signals:
   void showMenuSig(QListWidgetItem* item);

  protected:
    void enterEvent(QEnterEvent *event);

    void paintEvent(QPaintEvent *event);
  private:
    QMenu* m_menu;
    QListWidgetItem* m_item;
};
