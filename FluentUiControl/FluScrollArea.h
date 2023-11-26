#pragma once

#include <QScrollArea>

class FluScrollArea : public QScrollArea
{
  public:
    FluScrollArea(QWidget* parent = nullptr) : QScrollArea(parent)
    {
        
    }

  private:
    QScrollArea* m_widget;
};
