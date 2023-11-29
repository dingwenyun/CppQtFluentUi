#include "FluFrameLessWidget.h"
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

FluFrameLessWidget::FluFrameLessWidget(QWidget *parent) : FramelessWidget(parent)
{
    initialize();
    connect(FramelessManager::instance(), &FramelessManager::systemThemeChanged, this, &FluFrameLessWidget::updateStyleSheet);
}

FluFrameLessWidget::~FluFrameLessWidget() = default;

void FluFrameLessWidget::closeEvent(QCloseEvent *event)
{
    FramelessWidget::closeEvent(event);
}

void FluFrameLessWidget::initialize()
{
    setWindowTitle(tr("FramelessHelper demo application - QWidget"));
    setWindowIcon(QFileIconProvider().icon(QFileIconProvider::Computer));
    setAttribute(Qt::WidgetAttribute::WA_StyledBackground);

    resize(800, 600);
    m_titleBar = new StandardTitleBar(this);
    m_titleBar->setWindowIconVisible(true);
    // m_centerWidget = new QWidget(this);
    m_contentLayout = new QHBoxLayout;
    m_contentLayout->setContentsMargins(0, 0, 0, 0);
    m_contentLayout->setSpacing(0);

    const auto mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(0);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->addWidget(m_titleBar, Qt::AlignTop);
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

void FluFrameLessWidget::updateStyleSheet()
{
    //  m_contentWidget->setStyleSheet("background-color:pink;");
    update();
}

void FluFrameLessWidget::waitReady()
{
    FramelessWidgetsHelper *helper = FramelessWidgetsHelper::get(this);
    helper->waitForReady();
    helper->moveWindowToDesktopCenter();
}
