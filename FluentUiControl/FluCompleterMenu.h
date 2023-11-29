#pragma once

#include "FluRoundMenu.h"
#include <QLineEdit>
#include "FluIndicatorMenuItemDelegate.h"
#include "../FluentUiUtils/FluFontUtils.h"

class FluLineEdit;
class FluCompleterMenu : public FluRoundMenu
{
    Q_OBJECT
  public:
    FluCompleterMenu(FluLineEdit* lineEdit);

    bool setCompletion(QAbstractItemModel* model);

    void popup();

  signals:
    void activated(const QString& str);

  public slots:
    void _onItemSelected(const QString text);

  protected:
    bool eventFilter(QObject* watched, QEvent* event);

  private:
    QList<QString> m_items;
    FluLineEdit* m_lineEdit;
    FluIndicatorMenuItemDelegate* m_delegate;
};
