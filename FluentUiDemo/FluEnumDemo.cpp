#include "FluEnumDemo.h"
#include "../FluentUiUtils/FluLogUtils.h"
using namespace EnumDemoNameSpace;

FluEnumDemo::FluEnumDemo(QWidget* parent /*= nullptr*/) : QWidget(parent)
{
    LogDebug << "E1:" << EnumDemo::E1 << ", E2:" << EnumDemo::E2 << ", E3:" << EnumDemo::E3;
}
