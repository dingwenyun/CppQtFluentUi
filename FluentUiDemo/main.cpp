#include <QApplication>
#include <QWidget>
#include "FluButtonDemo.h"
#include "../FluentUiControl/FluCenterLabelWidget.h"
#include "../FluentUiUtils/FluLogUtils.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include "FluApiTest_QCursor.h"
#include "FluToolTipDemo.h"
#include "../FluentUiControl/FluNavigationPanel.h"
#include "../FluentUiControl/FluNavigationInterface.h"
#include <FramelessHelper/Widgets/FramelessWidget.h>
#include "FluNavigationDemo.h"
#include "../FluentUiControl/FluFrameLessWidget.h"
//#include "FramelessWidgetsHelperDemo.h"
#include "../FluentUiControl/FluDialog.h"
#include "FluSliderDemo.h"
#include "FluLabelDemo.h"
#include "FluAvatarWidgetDemo.h"
#include "FluMenuDemo.h"
#include "FluComboBoxDemo.h"
#include "FluLineEditDemo.h"
#include "FluTableWidgetDemo.h"
#include "FluApiTest_WheelEvent.h"
#include "FluScrollAreaDemo.h"
#include "FluColorDemo.h"
#include "../FluentUiControl/FluFrameLessWindow.h"
#include "FluEnumDemo.h"
#include "FluInfoBarDemo.h"

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

    FluLogUtils::init();
    LogDebug << "📢 Tips:";

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

    // FluWindowDemo demo;
    // demo.show();

    // FluWidgetDemo demo("demo widget");
    // demo.show();

    // FluNavigationInterface demo;
    // demo.show();

    // FluFrameLessWidget demo;
    // demo.show();

    // FluFrameLessWindow demo;
    // demo.show();

    // FluDialog dialog("a dialog example", "just a example", nullptr);
    // dialog.exec();

    // FluSliderDemo demo;
    // demo.show();

    // FluLabelDemo demo;
    // demo.show();

    //  FluAvatarWidgetDemo demo;
    //  demo.show();

    // FluMenuDemo demo;
    // demo.show();

    // FluComboBoxDemo demo;
    // demo.show();

    // FluLineEditDemo demo;
    // demo.show();

    //  FluTableWidgetDemo demo;
    //  demo.show();

    // FluApiTest_WheelEvent w;
    // w.show();

    // FluScrollAreaDemo demo;
    // demo.show();

    // FluColorDemo demo;
    // demo.show();

    // FluEnumDemo demo;
    // demo.show();

    FluInfoBarDemo demo;
    demo.show();

    return app.exec();
}