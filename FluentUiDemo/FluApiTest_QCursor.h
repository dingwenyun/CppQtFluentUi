#pragma once

#include <QApplication>
#include "../FluentUiUtils/FluLogUtils.h"
#include <QWidget>
#include <QMouseEvent>

class FluApiTest_QCursor : public QWidget
{
  public:
    FluApiTest_QCursor(QWidget* parent = nullptr);

    void mousePressEvent(QMouseEvent* event);

    //	void example();
};
