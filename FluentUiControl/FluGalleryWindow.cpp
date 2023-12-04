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
    m_basicInputInterface = new FluBasicInputInterface(this);
    m_dateTimeInterface = new FluDateTimeInterface(this);
    m_dialogInterface = new FluDialogInterface(this);
    m_layoutInterface = new FluLayoutInterface(this);
    m_settingInterface = new FluSettingInterface(this);
    
    initNavigation();
}

void FluGalleryWindow::initNavigation()
{
    addSubInterface(m_homeInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Home), "主页");
    addSubInterface(m_iconInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::EmojiTabSymbols), "图标");

    m_navigationInterface->addSeparator();

    addSubInterface(m_basicInputInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::CheckboxComposite), "基本输入");
    addSubInterface(m_dateTimeInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Calendar), "日期与时间");
    addSubInterface(m_dialogInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Message), "对话框与弹出窗口");
    addSubInterface(m_layoutInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::PPSFourPortrait), "布局");

    m_navigationInterface->addWidget("avatar", new FluNavigationAvatarWidget("mowangshuying", QPixmap("../res/mowangshuying.png")), nullptr, FluNavigationItemPosition::BOTTOM);
    addSubInterface(m_settingInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Settings), "设置", FluNavigationItemPosition::BOTTOM);
}
