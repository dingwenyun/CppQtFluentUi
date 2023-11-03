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
#include "FluRoundMenu.h"

class FluMenuAnimationManager : public QObject
{
  public:
    FluMenuAnimationManager(FluRoundMenu* menu);

  public:
    QSize availableViewSize(QPoint pos);

    QPoint _endPosition(QPoint pos);

    QSize _menuSize();

    virtual void exec(QPoint pos);

    void _register(FluMenuAnimationType type, FluMenuAnimationManager* manager);

    FluRoundMenu* make(FluMenuAnimationType type);

  public slots:
    virtual void _onValueChanged()
    {//pass
    }

    virtual void _updateMenuViewport();
  private:
    FluRoundMenu* m_menu;
    QPropertyAnimation* m_ani;
    std::map<FluMenuAnimationType, FluMenuAnimationManager*> m_managers;
};
