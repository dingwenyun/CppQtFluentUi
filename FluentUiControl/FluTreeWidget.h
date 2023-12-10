#pragma once

#include <QTreeWidget>
#include "FluSmoothScrollDelegate.h"
#include <QHeaderView>
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include "FluTreeItemDelegate.h"

class FluTreeWidget : public QTreeWidget
{
    Q_OBJECT
  public:
    FluTreeWidget(QWidget* parent) : QTreeWidget(parent)
    {
        m_srollDelegate = new FluSmoothScrollDelegate(this);
        m_delegate = new FluTreeItemDelegate(this);
        setItemDelegate(m_delegate);

        header()->setHighlightSections(false);
        header()->setDefaultAlignment(Qt::AlignCenter);

        setIconSize(QSize(16, 16));
        QString qss = FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluTreeWidget.qss");
        setStyleSheet(qss);
    }

  private:
    FluSmoothScrollDelegate* m_srollDelegate;
    FluTreeItemDelegate* m_delegate;
};
