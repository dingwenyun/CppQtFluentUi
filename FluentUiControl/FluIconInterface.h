#pragma once

#include "FluGalleryInterface.h"
#include "FluIconCardView.h"

class FluIconInterface : public FluGalleryInterface
{
  public:
    FluIconInterface(QWidget* parent = nullptr) : FluGalleryInterface("图标", "FluentUiUtils::FluIcon", parent)
    {
        setObjectName("iconInterface");
        m_iconCardView = new FluIconCardView(this);
        m_vBoxLayout->addWidget(m_iconCardView);
    }

  private:
    FluIconCardView* m_iconCardView;
};
