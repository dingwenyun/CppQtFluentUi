#pragma once

#include "FluUiMessBox.h"
#include <FramelessHelper/Widgets/FramelessDialog>

class FluDialog : public FluUiMessBox, public FRAMELESSHELPER_PREPEND_NAMESPACE(FramelessDialog)
{
  public:
    FluDialog(QString title, QString content, QWidget* parent) : FramelessDialog(parent)
    {
        setFixedSize(240, 160);
        setupUi(title, content, this);
    }
};
