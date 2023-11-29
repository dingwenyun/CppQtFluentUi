#pragma once

#include "../FluentUiControl/FluSmoothScrollArea.h"
#include "../FluentUiControl/FluPixmapLabel.h"

class FluScrollAreaDemo : public FluSmoothScrollArea
{
  public:
    FluScrollAreaDemo(QWidget* parent = nullptr) : FluSmoothScrollArea()
    {
        m_label = new FluPixmapLabel(this);
        m_label->setPixmap(QPixmap("../res/scrollareademo.jpg"));
        setScrollAnimation(Qt::Vertical, 400);
        setScrollAnimation(Qt::Horizontal, 400);
        horizontalScrollBar()->setValue(1900);
        setWidget(m_label);
        resize(1200, 800);

        setStyleSheet("QScrollArea {border: none;}");
    }

  private:
    FluPixmapLabel* m_label;
};
