#pragma once

#include "FluDef.h"
#include "FluBannerWidget.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include "FluLinkCardView.h"
#include "FluSampleCardView.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"

class FluHomeInterface : public QScrollArea
{
    Q_OBJECT

  public:
    FluSetPropertyP(QWidget, view);
    FluSetPropertyP(QVBoxLayout, vLayout);
    FluSetPropertyP(FluBannerWidget, bannerWidget);
    FluSetPropertyP(FluSampleCardView, basicCardView);

  public:
    FluHomeInterface(QWidget* parent = nullptr);

  protected:
    void paintEvent(QPaintEvent* event) override;
};
