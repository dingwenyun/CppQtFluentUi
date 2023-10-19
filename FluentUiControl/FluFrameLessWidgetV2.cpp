#include "FluFrameLessWidgetV2.h"
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

FRAMELESSHELPER_USE_NAMESPACE

using namespace Global;

FRAMELESSHELPER_STRING_CONSTANT(Geometry)
FRAMELESSHELPER_STRING_CONSTANT(DevicePixelRatio)

FluFrameLessWidgetV2::FluFrameLessWidgetV2(QWidget *parent) : FramelessWidget(parent)
{
    initialize();
    connect(FramelessManager::instance(), &FramelessManager::systemThemeChanged, this, &FluFrameLessWidgetV2::updateStyleSheet);
}

FluFrameLessWidgetV2::~FluFrameLessWidgetV2() = default;

void FluFrameLessWidgetV2::closeEvent(QCloseEvent *event)
{
    FramelessWidget::closeEvent(event);
}

void FluFrameLessWidgetV2::initialize()
{
    setWindowTitle(tr("FramelessHelper demo application - QWidget"));
    setWindowIcon(QFileIconProvider().icon(QFileIconProvider::Computer));
    setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    resize(800, 600);
    m_titleBar = new StandardTitleBar(this);
    m_titleBar->setWindowIconVisible(true);
    m_centerWidget = new QWidget(this);
    const auto contentLayout = new QHBoxLayout;
    contentLayout->setContentsMargins(0, 0, 0, 0);
    contentLayout->setSpacing(0);
    contentLayout->addWidget(m_centerWidget);

    const auto mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(m_titleBar);
    mainLayout->addLayout(contentLayout);
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

void FluFrameLessWidgetV2::updateStyleSheet()
{
  //  m_contentWidget->setStyleSheet("background-color:pink;");
    update();
}

void FluFrameLessWidgetV2::waitReady()
{
    FramelessWidgetsHelper *helper = FramelessWidgetsHelper::get(this);
    helper->waitForReady();
    helper->moveWindowToDesktopCenter();
}
