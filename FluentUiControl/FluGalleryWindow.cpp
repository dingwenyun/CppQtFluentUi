#include "FluGalleryWindow.h"
#include "FluHomeInterface.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include "FluNavigationAvatarWidget.h"

FluGalleryWindow::FluGalleryWindow(QWidget* parent /*= nullptr*/) : FluFrameLessWindow(parent)
{
    setWindowTitle("GalleryWindow(CppQtFluentUi)");
    setWindowIcon(QIcon("../res/logo.png"));

    // m_titleBar->setStyleSheet("background-color:transparent");

    m_homeInterface = new FluHomeInterface(this);
    m_iconInterface = new FluIconInterface(this);
    m_settingInterface = new FluSettingInterface(this);
    initNavigation();
}

void FluGalleryWindow::initNavigation()
{
    addSubInterface(m_homeInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Home), "主页");
    addSubInterface(m_iconInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Favicon), "图标");

    m_navigationInterface->addWidget("avatar", new FluNavigationAvatarWidget("mowangshuying", QPixmap("../res/mowangshuying.png")), nullptr, FluNavigationItemPosition::BOTTOM);
    addSubInterface(m_settingInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Settings), "设置", FluNavigationItemPosition::BOTTOM);
}
