#pragma once

#include <QObject>
#include <QEnterEvent>
#include <QMouseEvent>
#include <QEvent>

class FluAnimationBase : public QObject
{
    Q_OBJECT
  public:
    FluAnimationBase(QObject* parent = nullptr) : QObject(parent)
    {
        parent->installEventFilter(this);
    }

 public:
    virtual void _onHover(QEnterEvent* e)
    {
    }


    virtual void _onLeave(QEvent* e)
    {
    }

    virtual void _onPress(QMouseEvent* e)
    {
    }

    virtual void _onRelease(QMouseEvent* e)
    {
    }

  protected:
    bool eventFilter(QObject *watched, QEvent *event)
    {
        if (watched == parent())
        {
            if (event->type() == QEvent::MouseButtonPress)
            {
                _onPress((QMouseEvent*)event);
            }
            else if (event->type() == QEvent::MouseButtonRelease)
            {
                _onRelease((QMouseEvent*)event);
            }
            else if (event->type() == QEvent::Enter)
            {
                _onHover((QEnterEvent*)event);
            }
            else if (event->type() == QEvent::Leave)
            {
                _onLeave(event);
            }
        }

        return QObject::eventFilter(watched, event);
    }
};
