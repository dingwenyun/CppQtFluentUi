#pragma once

#include "FluMenuAnimationManager.h"
#include "FluRoundMenu.h"

#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QApplication>
#include <QScreen>
#include <QPoint>
#include <QSize>

class FluFadeInPullUpMenuAnimationManager : public FluMenuAnimationManager
{
  public:
    FluFadeInPullUpMenuAnimationManager(FluRoundMenu* menu);

  public:
    QPoint _endPosition(QPoint pos) override;

    void exec(QPoint pos) override;

    QSize availableViewSize(QPoint pos) override;

  private:
    QPropertyAnimation* m_opacityAni;
    QParallelAnimationGroup* m_aniGroup;
};
