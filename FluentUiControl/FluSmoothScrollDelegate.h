#pragma once

#include <QObject>
#include <QAbstractScrollArea>
#include "FluSmoothScrollBar.h"
#include <QListView>

class FluSmoothScrollDelegate : public QObject
{
	Q_OBJECT
  public:
        FluSmoothScrollDelegate(QAbstractScrollArea* parent = nullptr, bool bUseAni = false) : QObject(parent)
        {
            m_bUseAni = bUseAni;
            m_parentScrollArea = parent;
            m_vScrollBar = new FluSmoothScrollBar(Qt::Vertical, parent);
            m_hScrollBar = new FluSmoothScrollBar(Qt::Horizontal, parent);

            QAbstractItemView* itemViewInst = qobject_cast<QAbstractItemView*>(parent);
            if (itemViewInst != nullptr)
            {
                itemViewInst->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
                itemViewInst->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
            }

            m_parentScrollArea->viewport()->installEventFilter(this);
        }

    void setVerticalScrollBarPolicy(Qt::ScrollBarPolicy policy)
    {
        m_parentScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_vScrollBar->setForceHidden(policy == Qt::ScrollBarAlwaysOff);
    }

    void setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy policy)
    {
        m_parentScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        m_hScrollBar->setForceHidden(policy == Qt::ScrollBarAlwaysOff);
    }

    FluSmoothScrollBar* getVScrollBar()
    {
        return m_vScrollBar;
    }

    FluSmoothScrollBar* getHScrollBar()
    {
        return m_hScrollBar;
    }

    protected:
      bool eventFilter(QObject *watched, QEvent *event)
      {
          if (event->type() == QEvent::Wheel)
          {
              QWheelEvent* wheelEvent = (QWheelEvent*)(event);
              if (wheelEvent->angleDelta().y() != 0)
              {
                  m_vScrollBar->scrollValue(-wheelEvent->angleDelta().y());
              }
              else
              {
                  m_hScrollBar->scrollValue(-wheelEvent->angleDelta().x());
              }
              event->setAccepted(true);
              return true;
          }

          return QObject::eventFilter(watched, event);
      }

  private:
    bool m_bUseAni;
    QAbstractScrollArea* m_parentScrollArea;
    FluSmoothScrollBar* m_vScrollBar;
    FluSmoothScrollBar* m_hScrollBar;
};
