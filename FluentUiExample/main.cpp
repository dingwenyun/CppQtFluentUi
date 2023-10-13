#include <QApplication>
#include <QWidget>
#include "../FluentUiControl/FluMainWidget.h"
#include "../FluentUiControl/FluSampleCard.h"
#include "../FluentUiUtils/FluentUiLogUtils.h"

#include <FramelessHelper/Widgets/framelesswidget.h>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    FluentUiLogUtils::init();
    LogDebug << "called!";

    FluMainWidget w;
    w.show();

    return app.exec();
}