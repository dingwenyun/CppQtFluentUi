#pragma once

#include <QToolButton>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QPainter>
#include "../FluentUiUtils/FluentUiIconUtils.h"
#include<QAbstractScrollArea>
#include "FluScrollBarGroove.h"
#include "FluScrollBarHandle.h"
#include <QTimer>
#include <QScrollBar>
#include <QApplication>

class FluScrollBar : public QWidget
{
    Q_OBJECT
  public:
    FluScrollBar(Qt::Orientation orient, QAbstractScrollArea* parent = nullptr) : QWidget(parent)
    {
        m_parentSrollArea = parent;
        m_groove = new FluScrollBarGroove(orient, this);
        m_handle = new FluScrollBarHandle(orient, this);
        m_timer = new QTimer(this);


        m_orientation = orient;
        m_nSingleStep = 1;
        m_nPageStep = 50;
        m_nPadding =  14;

        m_minimum = 0;
        m_maximum = 0;
        m_value = 0;

        m_bPressed = false;
        m_bEnter = false;
        m_bExpanded = false;

        m_pressedPos = QPoint(0, 0);
        m_bForceHidden = false;

        if (orient == Qt::Vertical)
        {
            m_partnerBar = parent->verticalScrollBar();
            parent->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        }
        else
        {
            m_partnerBar = parent->horizontalScrollBar();
            parent->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        }

        __initWidget();
    }

    void __initWidget()
    {
        connect(m_groove->getUpButton(), &FluArrowButton::clicked, this, &FluScrollBar::onPageUp);
        connect(m_groove->getDownButton(), &FluArrowButton::clicked, this, &FluScrollBar::onPageDown);

        connect(m_groove->getOpcityAni(), &QPropertyAnimation::valueChanged, this, &FluScrollBar::onOpacityAniValueChanged);

        connect(m_partnerBar, &QScrollBar::rangeChanged, [=](int nMin, int nMax) { setRange(nMin, nMax); });
        connect(m_partnerBar, &QScrollBar::valueChanged, this, &FluScrollBar::onValueChanged);
        connect(this, &FluScrollBar::valueChanged, m_partnerBar, &QScrollBar::setValue);

        QAbstractScrollArea* parentSrollArea = (QAbstractScrollArea*)(parent());
        parentSrollArea->installEventFilter(this);
        setRange(m_partnerBar->minimum(), m_partnerBar->maximum());
        
        bool bVisible = m_maximum > 0 && !m_bForceHidden;
        setVisible(bVisible);

        adjustPos(m_parentSrollArea->size());
    }

    int getMinimum()
    {
        return m_minimum;
    }

    void setMinimum(int min)
    {
        if (min == m_minimum)
            return;

        m_minimum = min;
        emit rangeChanged(min, m_maximum);
    }

    int getMaximum()
    {
        return m_maximum;
    }


    void setMaximum(int max)
    {
        if (max == m_maximum)
            return;

        m_maximum = max;
        emit rangeChanged(m_minimum, max);
    }

    Qt::Orientation getOrientation()
    {
        return m_orientation;
    }

    void setOrientation(Qt::Orientation orientation)
    {
        m_orientation = orientation;
    }

    int getPageStep()
    {
        return m_nPageStep;
    }

    void setPageStep(int nStep)
    {
        if (nStep >= 1)
        {
            m_nPageStep = nStep;
        }
    }

    int getSigleStep()
    {
        return m_nSingleStep;
    }

    void setSingleStep(int nStep)
    {
        if (nStep >= 1)
        {
            m_nSingleStep = nStep;
        }
    }

    bool getSliderDown()
    {
        return m_bPressed;
    }

    void setSliderDown(bool bDown)
    {
        m_bPressed = true;
        if (bDown)
            emit sliderPerssed();
        else
            emit sliderReleased();
    }

    int getValue()
    {
        return m_value;
    }

    void setValue(int value)
    {
        m_value = value;
    }

    void setRange(int nMin, int nMax)
    {
        if ((nMin > nMax) || (nMax == m_maximum && nMin == m_minimum))
            return;

        setMinimum(nMin);
        setMaximum(nMax);

        adjustHandleSize();
        adjustHandlePos();
        setVisible(nMax > 0 && !m_bForceHidden);

        emit rangeChanged(nMin, nMax);
    }

    void setForceHidden(bool bHidden)
    {
        m_bForceHidden = bHidden;
        bool bVisible = m_maximum > 0 && !bHidden;
        setVisible(bVisible);
    }

    int getSlideLength()
    {
    }

    void adjustPos(QSize size)
    {
        if (m_orientation == Qt::Vertical)
        {
            resize(12, size.height() - 2);
            move(size.width() - 13, 1);
        }
        else
        {
            resize(size.width() - 2, 12);
            move(1, size.height() - 13);
        }
    }

    void adjustHandleSize() 
    {
                //: p = self.parent() ;
        if (m_orientation == Qt::Vertical)
        {
           
        }
        else
        {
        }
    }

    void adjustHandlePos()
    {
    }

    int getGrooveLength()
    {
    }


  signals:
    void rangeChanged(int nMin, int nMax);
    void valueChanged(int value);
    void sliderPerssed();
    void sliderReleased();
    void sliderMoved();
 public slots:
    void onPageUp()
   {
        //setValue(getValue() - pageStep());
   }

   void onPageDown()
   {
        //setValue(value() - pageStep());
   }

    void onValueChanged(const QVariant& value)
   {
   }

   void onOpacityAniValueChanged(const QVariant& value)
   {
   }

   void expand()
   {
       if (m_bExpanded || !m_bEnter)
           return;

       m_bExpanded = true;
       m_groove->fadeIn();
   }

   void collapse()
   {
       if (!m_bExpanded || m_bEnter)
           return;

       m_bExpanded = false;
       m_groove->fadeOut();
   }

 protected:
   bool eventFilter(QObject *watched, QEvent *event)
   {
       if (watched != m_parentSrollArea)
           return QWidget::eventFilter(watched, event);

       if (event->type() == QEvent::Resize)
       {
           QResizeEvent* resizeEvent = (QResizeEvent*)event;
           adjustPos(resizeEvent->size());
       }

       return QWidget::eventFilter(watched, event);
   }
   
   void enterEvent(QEvent *event)
   {
       m_bEnter = true;
       m_timer->stop();
       m_timer->singleShot(200, this, &FluScrollBar::expand);
   }

   void leaveEvent(QEvent *event)
   {
       m_bEnter = false;
       m_timer->stop();
       m_timer->singleShot(200, this, &FluScrollBar::collapse);
   }

   void resizeEvent(QResizeEvent* e)
   {
       m_groove->resize(size());
   }

   void mousePressEvent(QMouseEvent* e)
   {
       QWidget::mousePressEvent(e);
       m_bPressed = true;
       m_pressedPos = e->pos();

   }

   void mouseReleaseEvent(QMouseEvent *event)
   {
       QWidget::mouseReleaseEvent(event);
       m_bPressed = false;
       emit sliderReleased();
   }

   void mouseMoveEvent(QMouseEvent *event)
   {
       int nDv = 0;
       if (m_orientation == Qt::Vertical)
       {
           nDv = event->pos().y() - m_pressedPos.y();
       }
       else
       {
           nDv = event->pos().x() - m_pressedPos.x();
       }

       nDv = nDv / qMax(getSlideLength(), 1) * (m_maximum - m_minimum);
       FluScrollBar::setValue(getValue() + nDv);

       m_pressedPos = event->pos();
       emit sliderMoved();
   }

   void wheelEvent(QWheelEvent *event)
   {
       QApplication::sendEvent(m_parentSrollArea->viewport(), event);
   }
 private:
   QAbstractScrollArea* m_parentSrollArea;
   FluScrollBarGroove* m_groove;
   FluScrollBarHandle* m_handle;
   QScrollBar* m_partnerBar;
   
   
   Qt::Orientation m_orientation;
   
   int m_nSingleStep;
   int m_nPageStep;
   int m_nPadding;
   int m_minimum;
   int m_maximum;
   int m_value;

   bool m_bPressed;
   bool m_bEnter;
   bool m_bExpanded;
   bool m_bForceHidden;

   QPoint m_pressedPos;

   QTimer* m_timer;
};
