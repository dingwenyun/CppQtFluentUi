#include <QApplication>
#include <QWidget>
#include "../FluentUiControl/FluMainWidget.h"
#include "../FluentUiControl/FluSampleCard.h"
#include "../FluentUiUtils/FluLogUtils.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    FluLogUtils::init();
    LogDebug << "called!";

    FluMainWidget w;
    w.show();

    return app.exec();
}