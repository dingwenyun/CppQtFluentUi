#include "FluFrameLessWindow.h"
#include <QtCore/qdatetime.h>
#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
#include <QtGui/qshortcut.h>
#else
#include <QtWidgets/qshortcut.h>
#endif
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qfileiconprovider.h>
#include <FramelessHelper/Core/framelessmanager.h>
#include <FramelessHelper/Widgets/framelesswidgetshelper.h>
#include <FramelessHelper/Widgets/standardtitlebar.h>
#include <FramelessHelper/Widgets/standardsystembutton.h>

#include <QPainter>
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include "../FluentUiUtils/FluLogUtils.h"

FRAMELESSHELPER_USE_NAMESPACE

using namespace Global;

FRAMELESSHELPER_STRING_CONSTANT(Geometry)
FRAMELESSHELPER_STRING_CONSTANT(DevicePixelRatio)

FluFrameLessWindow::FluFrameLessWindow(QWidget *parent /*= nullptr*/) : FramelessWidget(parent)
{
    initialize();
    connect(FramelessManager::instance(), &FramelessManager::systemThemeChanged, this, &FluFrameLessWindow::updateStyleSheet);
    connect(m_navigationInterface, &FluNavigationInterface::displayModeChanged, m_titleBar, &StandardTitleBar::raise);
}

FluFrameLessWindow::~FluFrameLessWindow()
{
}

void FluFrameLessWindow::initialize()
{
    setWindowTitle(tr("FluFrameLessWindow"));
    setWindowIcon(QFileIconProvider().icon(QFileIconProvider::Computer));
    setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    resize(800, 600);
    m_titleBar = new StandardTitleBar(this);
    m_titleBar->setWindowIconVisible(true);
    //  m_titleBar->setObjectName("titleBar");
    m_titleBar->setStyleSheet("background-color: transparent;");
    m_titleBar->chromePalette()->setTitleBarActiveBackgroundColor(Qt::transparent);
    m_titleBar->chromePalette()->setTitleBarInactiveBackgroundColor(Qt::transparent);
    m_titleBar->raise();

    m_contentLayout = new QVBoxLayout;
    m_contentLayout->setContentsMargins(0, 48, 0, 0);
    m_contentLayout->setSpacing(0);

    m_stackedWidget = new QStackedWidget(this);
    m_contentLayout->addWidget(m_stackedWidget);

    const auto mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    m_navigationInterface = new FluNavigationInterface(this, true, true, true);
    mainLayout->addWidget(m_navigationInterface);

    mainLayout->addLayout(m_contentLayout, 1);
    setLayout(mainLayout);
    updateStyleSheet();

    FramelessWidgetsHelper *helper = FramelessWidgetsHelper::get(this);
    helper->setTitleBarWidget(m_titleBar);
#ifndef Q_OS_MACOS
    helper->setSystemButton(m_titleBar->minimizeButton(), SystemButtonType::Minimize);
    helper->setSystemButton(m_titleBar->maximizeButton(), SystemButtonType::Maximize);
    helper->setSystemButton(m_titleBar->closeButton(), SystemButtonType::Close);
#endif  // Q_OS_MACOS
}

void FluFrameLessWindow::waitReady()
{
    FramelessWidgetsHelper *helper = FramelessWidgetsHelper::get(this);
    helper->waitForReady();
    helper->moveWindowToDesktopCenter();
}

FluNavigationTreeWidget *FluFrameLessWindow::addSubInterface(QWidget *interface, QPixmap icon, QString text, FluNavigationItemPosition position /*= FluNavigationItemPosition::TOP*/, QWidget *parentWidget /*= nullptr*/, bool bTransparent /*= false*/)
{
    // interface的对象名必须不为空，为空直接返回错误的指针
    if (interface->objectName().isEmpty())
    {
        LogErr << "interface objectname empty.";
        return nullptr;
    }

    if (parentWidget != nullptr && parentWidget->objectName().isEmpty())
    {
        LogErr << "parentWidget not nullptr but parentWidget objectname empty.";
        return nullptr;
    }

    interface->setProperty("isStackedTransparent", bTransparent);
    m_stackedWidget->addWidget(interface);

    QString routeKey = interface->objectName();
    QString parentRouteKey;
    if (parentWidget != nullptr)
        parentRouteKey = parentWidget->objectName();
    FluNavigationTreeWidget *treeWidget = m_navigationInterface->addItem(
        routeKey, icon, text, [=]() { m_stackedWidget->setCurrentWidget(interface); }, true, position, text, parentRouteKey);
    if (m_stackedWidget->count() == 1)
    {
        connect(m_stackedWidget, &QStackedWidget::currentChanged, this, &FluFrameLessWindow::onCurrentInterfaceChanged);
        m_navigationInterface->setCurrentItem(routeKey);
        // mark it!
    }

    return treeWidget;
}

void FluFrameLessWindow::closeEvent(QCloseEvent *event)
{
    FramelessWidget::closeEvent(event);
}

void FluFrameLessWindow::resizeEvent(QResizeEvent *event)
{
    FramelessWidget::resizeEvent(event);
    m_titleBar->move(48, 1);
    m_titleBar->resize(width() - 48, m_titleBar->height());
    m_titleBar->raise();
}

void FluFrameLessWindow::paintEvent(QPaintEvent *event)
{
    FramelessWidget::paintEvent(event);
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());
}

void FluFrameLessWindow::updateStyleSheet()
{
    // setStyleSheet("background-color:pink;");
    update();
}

void FluFrameLessWindow::onCurrentInterfaceChanged(int nIndex)
{
    QWidget *widget = m_stackedWidget->widget(nIndex);
    m_navigationInterface->setCurrentItem(widget->objectName());
}
