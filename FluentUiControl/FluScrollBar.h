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
#include "../FluentUiUtils/FluIconUtils.h"
#include "../FluentUiUtils/FluLogUtils.h"
#include <QAbstractScrollArea>
#include "FluScrollBarGroove.h"
#include "FluScrollBarHandle.h"
#include <QTimer>
#include <QScrollBar>
#include <QApplication>

class FluScrollBar : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int val READ getVal WRITE setVal)
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
        m_nPadding = 14;

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

        m_parentSrollArea->installEventFilter(this);
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
        // m_value = value;
        setVal(value);
    }

    int getVal()
    {
        return m_value;
    }

    void setVal(int value)
    {
        if (value == m_value)
            return;

        //  LogDebug << "value:" << value;
        value = qMax(m_minimum, qMin(value, m_maximum));
        m_value = value;
        emit valueChanged(value);
        adjustHandlePos();
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

    int getGrooveLength()
    {
        if (m_orientation == Qt::Vertical)
        {
            return height() - 2 * m_nPadding;
        }

        return width() - 2 * m_nPadding;
    }

    int getSlideLength()
    {
        //   LogDebug << "grooveLen:" << getGrooveLength() << ", handle height:" << m_handle->height();
        if (m_orientation == Qt::Vertical)
        {
            return getGrooveLength() - m_handle->height();
        }
        return getGrooveLength() - m_handle->width();
    }

    bool isSlideResion(const QPoint& pos) const
    {
        if (m_orientation == Qt::Vertical)
        {
            return pos.y() >= m_nPadding && pos.y() <= height() - m_nPadding;
        }

        return pos.x() >= m_nPadding && pos.x() <= width() - m_nPadding;
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
        if (m_orientation == Qt::Vertical)
        {
            int nTotal = m_maximum - m_minimum + m_parentSrollArea->height();
            int nH = 1.0 * getGrooveLength() * m_parentSrollArea->height() / qMax(nTotal, 1);
            m_handle->setFixedHeight(qMax(30, nH));
        }
        else
        {
            int nTotal = m_maximum - m_minimum + m_parentSrollArea->width();
            int nW = 1.0 * getGrooveLength() * m_parentSrollArea->width() / qMax(nTotal, 1);
            m_handle->setFixedWidth(qMax(30, nW));
        }
    }

    void adjustHandlePos()
    {
        int nTotal = qMax(m_maximum - m_minimum, 1);
        int nDelta = getValue() * 1.0 / nTotal * getSlideLength();

        //  LogDebug << "value:" << getValue() << "; slide length:" << getSlideLength();
        if (m_orientation == Qt::Vertical)
        {
            int nX = width() - m_handle->width() - 3;
            m_handle->move(nX, m_nPadding + nDelta);
        }
        else
        {
            int nY = height() - m_handle->height() - 3;
            m_handle->move(m_nPadding + nDelta, nY);
        }
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
        // setValue(getValue() - pageStep());
        setValue(getValue() - getPageStep());
    }

    void onPageDown()
    {
        // setValue(value() - pageStep());
        setValue(getValue() + getPageStep());
    }

    void onValueChanged(const QVariant& value)
    {
        //LogDebug << "value:" << value.toInt();
        setVal(value.toInt());
    }

    void onOpacityAniValueChanged(const QVariant& value)
    {
        qreal opacity = m_groove->getOpacityEffect()->opacity();
        if (m_orientation == Qt::Vertical)
        {
            m_handle->setFixedWidth(3 + opacity * 3);
        }
        else
        {
            m_handle->setFixedHeight(3 + opacity * 3);
        }
        adjustHandlePos();
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
    bool eventFilter(QObject* watched, QEvent* event)
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

    void enterEvent(QEnterEvent* event)
    {
        m_bEnter = true;
        m_timer->stop();
        m_timer->singleShot(200, this, &FluScrollBar::expand);
    }

    void leaveEvent(QEvent* event)
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

        if (childAt(e->pos()) == m_handle || !isSlideResion(e->pos()))
            return;

        int nValue = 0;
        if (m_orientation == Qt::Vertical)
        {
            if (e->pos().y() > m_handle->geometry().bottom())
            {
                nValue = e->pos().y() - m_handle->height() - m_nPadding;
            }
            else
            {
                nValue = e->pos().y() - m_nPadding;
            }
        }
        else
        {
            if (e->pos().x() > m_handle->geometry().right())
            {
                nValue = e->pos().x() - m_handle->width() - m_nPadding;
            }
            else
            {
                nValue = e->pos().x() - m_nPadding;
            }
        }

        setValue(1.0 * nValue / qMax(getSlideLength(), 1) * m_maximum);
        emit sliderPerssed();
    }

    void mouseReleaseEvent(QMouseEvent* event)
    {
        QWidget::mouseReleaseEvent(event);
        m_bPressed = false;
        emit sliderReleased();
    }

    void mouseMoveEvent(QMouseEvent* event)
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

        nDv = 1.0 * nDv / qMax(getSlideLength(), 1) * (m_maximum - m_minimum);
        FluScrollBar::setValue(getValue() + nDv);

        m_pressedPos = event->pos();
        emit sliderMoved();
    }

    void wheelEvent(QWheelEvent* event)
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
