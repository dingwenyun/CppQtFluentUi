#include <QApplication>
#include <QWidget>
#include "FluButtonDemo.h"
#include "../FluentUiControl/FluCenterLabelWidget.h"
#include "../FluentUiUtils/FluentUiLogUtils.h"
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"
#include "FluApiTest_QCursor.h"
#include "FluToolTipDemo.h"
#include "../FluentUiControl/FluNavigationPanel.h"
#include <FramelessHelper/Widgets/FramelessWidget.h>
#include "FluNavigationDemo.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    // QWidget widget;
    // widget.show();

    // ButtonDemo buttonDemo;
    // buttonDemo.show();

    FluentUiLogUtils::init();

    // FluCenterLabelWidget widget(nullptr, "TempText");
    // widget.show();

    // ApiTest_QCursor apiTest_Qcursor;
    // apiTest_Qcursor.show();

    // QString qss = FluentUiStyleSheetUitls::getQssByFileName("[{\"key\":\"key1\", \"value\":\"val1\"},{\"key\":\"key2\", \"value\":\"val2\"}]", "../StyleSheet/FluTest.qss");
    // FluToolTipDemo demo;
    // demo.show();

    //    FluPushButtonDemo demo;
    //    demo.show();

    //  FluNavigationPanel panel;
    //  panel.show();

    // FRAMELESSHELPER_NAMESPACE::FramelessWidget w;
    // w.show();

    FluWindowDemo demo;
    demo.show();

    //  FluWidgetDemo demo("demo widget");
    //  demo.show();

    return app.exec();
}