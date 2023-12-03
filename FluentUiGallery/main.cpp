#include <QApplication>
#include <QWidget>
#include "../FluentUiControl/FluSampleCard.h"
#include "../FluentUiUtils/FluLogUtils.h"
#include "../FluentUiControl/FluGalleryWindow.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    FluLogUtils::init();
    LogDebug << "called!";

    FluGalleryWindow w;
    w.show();

    return app.exec();
}