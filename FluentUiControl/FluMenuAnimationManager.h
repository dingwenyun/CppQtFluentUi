#pragma once
#include <QtCore>
#include <QObject>
#include <QPropertyAnimation>
#include <QApplication>
#include <QScreen>
#include <QHoverEvent>
#include <QtMinMax>

#include "FluMenuActionListWidget.h"
#include "FluMenuAnimationType.h"

class FluRoundMenu;
class FluMenuAnimationManager : public QObject
{
  public:
    FluMenuAnimationManager(FluRoundMenu* menu);

  public:
    virtual QSize availableViewSize(QPoint pos);

    virtual QPoint _endPosition(QPoint pos);

    QSize _menuSize();

    virtual void exec(QPoint pos);

    static void registerManager(FluMenuAnimationType type, FluMenuAnimationManager* manager);

    static FluMenuAnimationManager* make(FluRoundMenu* roundMenu, FluMenuAnimationType type);

  public slots:
    virtual void _onValueChanged()
    {  // pass
    }

    virtual void _updateMenuViewport();

  protected:
    FluRoundMenu* m_menu;
    QPropertyAnimation* m_ani;
    static std::map<FluMenuAnimationType, FluMenuAnimationManager*> m_managers;
};
