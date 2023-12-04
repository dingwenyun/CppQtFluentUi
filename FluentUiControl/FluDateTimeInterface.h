#pragma once

#include "FluGalleryInterface.h"

class FluDateTimeInterface : public FluGalleryInterface
{
  public:
    FluDateTimeInterface(QWidget* parent = nullptr) : FluGalleryInterface("日期与时间", "FluentUiControl::TimePicker", parent)
    {
        setObjectName("dateTimeInterface");
    }
};
