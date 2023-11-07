#pragma once

#include "FluMenuAnimationManager.h"
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "FluRoundMenu.h"
#include <QScreen>
#include <QApplication>

class FluFadeInDropDownMenuAnimationManager : public FluMenuAnimationManager
{
  public:
    FluFadeInDropDownMenuAnimationManager(FluRoundMenu* menu) : FluMenuAnimationManager(menu)
    {
        m_opacityAni = new QPropertyAnimation(menu, "windowOpacity", this);
        m_aniGroup = new QParallelAnimationGroup(this);
        m_aniGroup->addAnimation(m_ani);
        m_aniGroup->addAnimation(m_opacityAni);
    }

  public:
    void exec(QPoint pos) override
    {
        QPoint endPos = _endPosition(pos);
        m_opacityAni->setStartValue(0);
        m_opacityAni->setEndValue(1);
        m_opacityAni->setDuration(150);
        m_opacityAni->setEasingCurve(QEasingCurve::OutQuad);

        m_ani->setStartValue(endPos - QPoint(0, 8));
        m_ani->setEndValue(endPos);
        m_ani->setDuration(150);
        m_ani->setEasingCurve(QEasingCurve::OutQuad);
        m_aniGroup->start();
    }

    QSize availableViewSize(QPoint pos) override
    {
        QRect screenRect = QApplication::screenAt(QCursor::pos())->availableGeometry();

        int nW = screenRect.width() - 100;
        int nH = qMax(screenRect.bottom() - pos.y() - 10, 1);
        return QSize(nW, nH);
    }

  private:
    QPropertyAnimation* m_opacityAni;
    QParallelAnimationGroup* m_aniGroup;
};
