#pragma once

#include "FluAnimationBase.h"
#include <QWidget>
#include <QPropertyAnimation>

class FluTranslateYAnimation : public FluAnimationBase
{
    Q_OBJECT
    Q_PROPERTY(float y READ getY WRITE setY)
  public:
    FluTranslateYAnimation(QWidget* parent, int nOffset = 2) : FluAnimationBase((QObject*)parent)
    {
        m_Y = 0;
        m_maxOffset = nOffset;
        m_ani = new QPropertyAnimation(this, "y", this);
    }

  public:
    void _onPress(QMouseEvent* e)
    {
        m_ani->setEndValue(m_maxOffset);
        m_ani->setEasingCurve(QEasingCurve::OutQuad);
        m_ani->setDuration(150);
        m_ani->start();
    }

    void _onRelease(QMouseEvent* e)
    {
        m_ani->setEndValue(0);
        m_ani->setDuration(500);
        m_ani->setEasingCurve(QEasingCurve::OutElastic);
        m_ani->start();
    }

    void setY(float y)
    {
        m_Y = y;
        QWidget* parentWidget = (QWidget*)parent();
        parentWidget->update();
        emit valueChanged(y);
    }

    float getY()
    {
        return m_Y;
    }

  signals:
    void valueChanged(int value);

  private:
    int m_Y;
    int m_maxOffset;
    QPropertyAnimation* m_ani;
};
