#pragma once

#include "FluNavigationPushButton.h"

class FluNavigationToolButton : public FluNavigationPushButton
{
    Q_OBJECT
  public:
    FluNavigationToolButton(QPixmap icon, QWidget* parent = nullptr) : FluNavigationPushButton(icon, "", false, parent)
    {
        // setFixedSize(40, 40);
    }

    // 设置指定大小
    void setCompacted(bool bCompacted)
    {
        setFixedSize(40, 36);
    }
};
