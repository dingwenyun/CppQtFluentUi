#pragma once

#include <QObject>
#include <QAbstractScrollArea>

class FluSmoothScrollDelegate : public QObject
{
	Q_OBJECT
  public:
    FluSmoothScrollDelegate(QAbstractScrollArea* parent = nullptr, bool bUseAni = false) 
        : QObject(parent)
    {
        m_bUseAni = bUseAni;
    }

  private:
    bool m_bUseAni;
};
