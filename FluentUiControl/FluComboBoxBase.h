#pragma once

#include <QObject>
#include <list>
#include "FluComboItem.h"

using namespace std;

class FluComboBoxBase : public QObject
{
    Q_OBJECT
  public:
  protected:
    bool m_bHover;
    bool m_bPressed;

    int m_currentIndex = -1;
    int m_maxVisibleItems = -1;
    list<FluComboItem> m_items;
    // drop menu mark it!
};
