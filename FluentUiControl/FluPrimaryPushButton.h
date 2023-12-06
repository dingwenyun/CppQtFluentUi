#pragma once

#include "FluPushButton.h"

class FluPrimaryPushButton : public FluPushButton
{
    Q_OBJECT
  public:
    FluPrimaryPushButton(QWidget* parent) : FluPushButton(parent)
    {
    }
    FluPrimaryPushButton(QString text, QWidget* parent = nullptr, QIcon icon = QIcon()) : FluPushButton(text, parent, icon)
    {
    }
};