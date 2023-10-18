#include <QApplication>

#include "../FluentUiControl/FluFrameLessWidgetV2.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    FluFrameLessWidgetV2 demo;
    demo.show();

    return app.exec();
}