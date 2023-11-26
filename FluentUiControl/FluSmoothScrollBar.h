#pragma once

#include "FluScrollBar.h"
#include <QPropertyAnimation>

class FluSmoothScrollBar : public FluScrollBar
{
    Q_OBJECT
  public:
    FluSmoothScrollBar(Qt::Orientation orient, QAbstractScrollArea* parent = nullptr) : FluScrollBar(orient, parent)
    {
        m_nDuration = 500;

        m_ani = new QPropertyAnimation(this, "val", nullptr);
        m_ani->setEasingCurve(QEasingCurve::OutCirc);
        m_ani->setDuration(m_nDuration);

        m_nValue = getValue();
    }

    void setValue(int nValue)
    {
        if (nValue == getValue())
            return;

        m_ani->stop();
        int nDV = qAbs(nValue - getValue());
        if (nDV < 50)
        {
            m_ani->setDuration(m_nDuration * nDV / 70);
        }
        else
        {
            m_ani->setDuration(m_nDuration);
        }

        m_ani->setStartValue(getValue());
        m_ani->setEndValue(nValue);
        LogDebug << "ani start value:" << getValue() << ", end value = " << nValue;
        m_ani->start();
    }

    void scrollValue(int nValue)
    {
        m_nValue += nValue;
        m_nValue = qMax(getMinimum(), m_nValue);
        m_nValue = qMin(getMaximum(), m_nValue);

        LogDebug << m_nValue << "=>" << m_nValue - nValue;
        setValue(m_nValue);
    }

    void srollTo(int nValue)
    {
        m_nValue = nValue;
        m_nValue = qMax(getMinimum(), m_nValue);
        m_nValue = qMin(getMaximum(), m_nValue);

        setValue(m_nValue);
    }

    void resetValue(int nValue)
    {
        m_nValue = nValue;
    }

    void setScrollAnimation(int nDuration, QEasingCurve easingCurve = QEasingCurve::OutCubic)
    {
        m_nDuration = nDuration;
        m_ani->setDuration(nDuration);
        m_ani->setEasingCurve(easingCurve);
    }
  protected:
    void mousePressEvent(QMouseEvent* e)
    {
          FluScrollBar::mousePressEvent(e);
          m_ani->stop();
          m_nValue = getValue();
    }

    void mouseMoveEvent(QMouseEvent *event)
    {
        FluScrollBar::mouseMoveEvent(event);
        m_ani->stop();
        m_nValue = getValue();
    }

  private:
    int m_nDuration;
    int m_nValue;
    QPropertyAnimation* m_ani;
};
