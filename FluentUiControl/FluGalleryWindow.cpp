#include "FluGalleryWindow.h"
#include "FluHomeInterface.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include "FluNavigationAvatarWidget.h"
#include "FluMessageBox.h"

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
    m_materialInterface = new FluMaterialInterface(this);
    m_menuInterface = new FluMenuInterface(this);
    m_navigationViewInterface = new FluNavigationViewInterface(this);
    m_scrollInterface = new FluScrollInterface(this);
    m_statusInfoInterface = new FluStatusInfoInterface(this);
    m_textInfterface = new FluTextInterface(this);
    m_viewInterface = new FluViewInterface(this);

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
    addSubInterface(m_layoutInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::ViewDashboard), "布局");
    addSubInterface(m_materialInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Color), "材料");
    addSubInterface(m_menuInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::ClipboardList), "菜单与工具栏");
    addSubInterface(m_navigationViewInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::OpenWith), "导航栏");
    addSubInterface(m_scrollInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Sort), "滚动条");

    addSubInterface(m_statusInfoInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Comment), "状态和信息");
    addSubInterface(m_textInfterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Font), "文本");
    addSubInterface(m_viewInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::ViewAll), "视图");

    m_navigationInterface->addWidget(
        "avatar",
        new FluNavigationAvatarWidget("mowangshuying", QPixmap("../res/mowangshuying.png")),
        [=]() {
            auto messageBox = new FluMessageBox("支持作者", "个人开发不易，如果这个项目帮助到了您，可以考虑请作者喝一瓶快乐水🥤。您的支持就是作者开发和维护项目的动力🚀!", window());
            messageBox->exec();
            messageBox->deleteLater();
        },
        FluNavigationItemPosition::BOTTOM);
    addSubInterface(m_settingInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Settings), "设置", FluNavigationItemPosition::BOTTOM);
}
