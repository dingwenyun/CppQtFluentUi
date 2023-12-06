#pragma once

#include "FluFrame.h"
#include "FluListView.h"

class FluListFrame : public FluFrame
{
  public:
    FluListFrame(QWidget* parent = nullptr) : FluFrame(parent)
    {
        // m_listWidget = new FluListWidget(this);
        // addWidget(m_listWidget)
        // ...
    }

  protected:
    // mark it! wait for do it!
    // FluListWidget* m_listWidget;
};
