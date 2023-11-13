#pragma once

#include "FluRoundMenu.h"
#include <QWidget>
#include "FluIndicatorMenuItemDelegate.h"
#include "FluMenuActionListWidget.h"

class FluComboBoxMenu : public FluRoundMenu
{
    Q_OBJECT
  public:
    FluComboBoxMenu(QWidget* parent = nullptr) : FluRoundMenu("", nullptr)
    {
        FluMenuActionListWidget* listWidget = getView();
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        QWidget* viewPort = listWidget->viewport();
        viewPort->setContentsMargins(0, 2, 0, 6);
        listWidget->setViewport(viewPort);

        listWidget->setItemDelegate(nullptr);
        FluIndicatorMenuItemDelegate* delegate = new FluIndicatorMenuItemDelegate();
        listWidget->setItemDelegate(delegate);
        listWidget->setObjectName("comboListWidget");
        setItemHeight(33);
    }

    void exec(QPoint pos, bool bAni = true, FluMenuAnimationType aniType = FluMenuAnimationType::DROP_DOWN)
    {
        FluMenuActionListWidget* listWidget = getView();
        listWidget->adjustSize(pos, aniType);
        adjustSize();

        return FluRoundMenu::exec(pos, bAni, aniType);
    }
};
