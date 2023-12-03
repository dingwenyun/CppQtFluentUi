#pragma once

#include "FluDef.h"
#include "FluBannerWidget.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include <QWidget>
#include "FluLinkCardView.h"
#include "FluSampleCardView.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include "FluScrollArea.h"

class FluHomeInterface : public FluScrollArea
{
    Q_OBJECT
  public:
    FluHomeInterface(QWidget* parent = nullptr);

    void __initWidget();

    void __loadSamples();

  protected:
    void paintEvent(QPaintEvent* event) override;

  private:
    FluBannerWidget* m_bannerWidget;
    QWidget* m_view;
    QVBoxLayout* m_vLayout;
    FluSampleCardView* m_basicInputView;
    FluSampleCardView* m_dateTimeView;
};
