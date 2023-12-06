#pragma once

#include <QFrame>
#include <QHBoxLayout>
#include "../FluentUiUtils/FluStyleSheetUitls.h"

class FluFrame : public QFrame
{
    Q_OBJECT
  public:
    FluFrame(QWidget* parent = nullptr) : QFrame(parent)
    {
        m_hBoxLayout = new QHBoxLayout(this);
        m_hBoxLayout->setContentsMargins(0, 8, 0, 0);
        setObjectName("frame");

        QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluFrame.qss");
        setStyleSheet(qss);
    }

  protected:
    QHBoxLayout* m_hBoxLayout;
};
