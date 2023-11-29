#pragma once

#include "FluDef.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "FluFrameLessWidget.h"
#include "FluNavigationInterface.h"
#include <QWidget>
#include <QStackedLayout>

class FluMainWidget : public FluFrameLessWidget
{
    Q_OBJECT

  public:
    FluMainWidget(QWidget* parent = nullptr);

    void initialize();

  protected:
  private:
    // 水平布局
    QHBoxLayout* m_hLayout;
    FluNavigationInterface* m_navigationInterface;
    QStackedLayout* m_stackLayout;
};
