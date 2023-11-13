#include <QApplication>
#include <QWidget>
#include "FluButtonDemo.h"
#include "../FluentUiControl/FluCenterLabelWidget.h"
#include "../FluentUiUtils/FluentUiLogUtils.h"
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"
#include "FluApiTest_QCursor.h"
#include "FluToolTipDemo.h"
#include "../FluentUiControl/FluNavigationPanel.h"
#include "../FluentUiControl/FluNavigationInterface.h"
#include <FramelessHelper/Widgets/FramelessWidget.h>
#include "FluNavigationDemo.h"
#include "../FluentUiControl/FluFrameLessWidgetV2.h"
//#include "FramelessWidgetsHelperDemo.h"
#include "../FluentUiControl/FluDialog.h"
#include "FluSliderDemo.h"
#include "FluLabelDemo.h"
#include "FluAvatarWidgetDemo.h"
#include "FluMenuDemo.h"
#include "FluComboBoxDemo.h"

int main(int argc, char** argv)
{
    QApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
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

    // FluNavigationPanel panel;
    // panel.show();

    // FRAMELESSHELPER_NAMESPACE::FramelessWidget w;
    // w.show();

   //    FluWindowDemo demo;
   // demo.show();

    // FluWidgetDemo demo("demo widget");
    //demo.show();

    //FluNavigationInterface demo;
    //demo.show();

    // FluFrameLessWidgetV2 v2;
    // v2.show();

    // FluDialog dialog("a dialog example", "just a example", nullptr);
    // dialog.exec();

    // FluSliderDemo demo;
    // demo.show();

    // FluLabelDemo demo;
    // demo.show();

    //  FluAvatarWidgetDemo demo;
    //  demo.show();

    //FluMenuDemo demo;
    //demo.show();


    FluComboBoxDemo demo;
    demo.show();
    return app.exec();
}