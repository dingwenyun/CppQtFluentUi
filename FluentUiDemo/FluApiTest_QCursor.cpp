#include "FluApiTest_QCursor.h"
#include <QApplication>
#include <QCursor>


FluApiTest_QCursor::FluApiTest_QCursor(QWidget* parent /*= nullptr*/) : QWidget(parent)
{

}

void FluApiTest_QCursor::mousePressEvent(QMouseEvent* event)
{
	LogDebug << QCursor::pos();
	QScreen *screen = QApplication::screenAt(QCursor::pos()); // 获取到在哪个屏幕
	LogDebug << screen->availableGeometry();  // 打印屏幕信息
}

//void ApiTest_QCursor::example()
//{
//	LogDebug << QCursor::pos();
//}
