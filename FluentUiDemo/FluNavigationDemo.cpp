#include "FluNavigationDemo.h"
#include "../FluentUiControl/FluNavigationAvatarWidget.h"
#include "../FluentUiUtils/FluentUiLogUtils.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"
#include <QMessageBox>

using namespace std;

FluWidgetDemo::FluWidgetDemo(QString text, QWidget* parent /*= nullptr*/) : QFrame(parent)
{
    m_label = new QLabel(text, this);
    m_label->setAlignment(Qt::AlignCenter);

    m_hLayout = new QHBoxLayout(this);
    m_hLayout->addWidget(m_label, 1, Qt::AlignCenter);
    setObjectName(text.replace(" ", "-"));

    QString qss =
        " FluWidgetDemo{\
        border : 1px solid rgb(229, 229, 229); \
        border-right : none; \
        border-bottom : none;\
        border-top-left-radius : 10px;\
        background-color : rgb(249, 249, 249) \
        } ";

    //  setStyleSheet("background-color:pink");

    setStyleSheet(qss);
    m_label->setStyleSheet("font: 24px 'Segoe UI', 'Microsoft YaHei';");
    LogDebug << "demo size:" << size();
}

FluWindowDemo::FluWindowDemo(QWidget* parent /*= nullptr*/) : FluFrameLessWidgetV2(parent)
{
    setWindowTitle("Fluent Navigation Demo Application");
    //  m_hBoxLayout = new QHBoxLayout(m_centerWidget);
    //  m_centerWidget->setLayout(m_hBoxLayout);

    m_navigationInterface = new FluNavigationInterface(this);
    LogDebug << "navigation infterface size:" << m_navigationInterface->size();

    m_stackWidget = new QStackedWidget(this);

    m_searchInterface = new FluWidgetDemo("Search Interface", this);
    m_musicInterface = new FluWidgetDemo("Music Interface", this);

    m_videoInterface = new FluWidgetDemo("Video Interface", this);
    m_folderInterface = new FluWidgetDemo("Folder Interface", this);
    m_settingInterface = new FluWidgetDemo("Setting Interface", this);
    m_albumInterface0 = new FluWidgetDemo("Album Interface", this);
    m_albumInterface01 = new FluWidgetDemo("Album Interface 1", this);
    m_albumInterface02 = new FluWidgetDemo("Album Interface 2", this);
    m_albumInterface011 = new FluWidgetDemo("Album Interface 1-1", this);

    __initLayout();

    __initNavigation();

    __initWindow();

    LogDebug << "navigation interface size:" << m_navigationInterface->size();
    setMouseTracking(true);
}

void FluWindowDemo::__initLayout()
{
    m_contentLayout->setSpacing(0);
    m_contentLayout->setContentsMargins(0, 0, 0, 0);
    m_contentLayout->addWidget(m_navigationInterface);
    m_contentLayout->addWidget(m_stackWidget, 1);
}

void FluWindowDemo::__initNavigation()
{
    addSubInterface(m_searchInterface, FluGetIconPixmap(FluAwesomeType::Search), "Search");
    addSubInterface(m_musicInterface, FluGetIconPixmap(FluAwesomeType::MusicNote), "Music library");
    addSubInterface(m_videoInterface, FluGetIconPixmap(FluAwesomeType::Video), "Video library");

    m_navigationInterface->addSeparator();

    addSubInterface(m_albumInterface0, FluGetIconPixmap(FluAwesomeType::MusicAlbum), "albums", FluNavigationItemPosition::SCROLL);
    addSubInterface(m_albumInterface01, FluGetIconPixmap(FluAwesomeType::MusicAlbum), "albums 01", FluNavigationItemPosition::TOP, m_albumInterface0);
    addSubInterface(m_albumInterface011, FluGetIconPixmap(FluAwesomeType::MusicAlbum), "albums 011", FluNavigationItemPosition::TOP, m_albumInterface01);
    addSubInterface(m_albumInterface02, FluGetIconPixmap(FluAwesomeType::MusicAlbum), "albums 02", FluNavigationItemPosition::TOP, m_albumInterface0);

    addSubInterface(m_folderInterface, FluGetIconPixmap(FluAwesomeType::Folder), "Folder library", FluNavigationItemPosition::SCROLL);

    FluNavigationAvatarWidget* avatarWidget = new FluNavigationAvatarWidget("mowangshuying", QPixmap("../res/shoko.png"));
    m_navigationInterface->addWidget(
        "avatar", avatarWidget, []() { QMessageBox::information(nullptr, "info", "write by mowangshuying"); }, FluNavigationItemPosition::BOTTOM);
    addSubInterface(m_settingInterface, FluGetIconPixmap(FluAwesomeType::Settings), "Settings", FluNavigationItemPosition::BOTTOM);
}

void FluWindowDemo::__initWindow()
{
    //   resize(900, 700);
    resize(900, 700);
    // m_navigationInterface->resize(m_navigationInterface->width(), 700);

    setWindowIcon(QIcon("../res/logo.png"));

    QRect desktopRect = QApplication::primaryScreen()->geometry();
    int nW = desktopRect.width();
    int nH = desktopRect.height();
    move(nW / 2 - width() / 2, nH / 2 - height() / 2);
}

void FluWindowDemo::addSubInterface(QWidget* interface, QPixmap icon, QString text, FluNavigationItemPosition position /*= FluNavigationItemPosition::TOP*/, QWidget* parent /*= nullptr*/)
{
    m_stackWidget->addWidget(interface);

    QString parentRouteKey = "";
    if (parent != nullptr)
    {
        parentRouteKey = parent->objectName();
    }
    m_navigationInterface->addItem(
        interface->objectName(), icon, text, [interface, this]() { swithTo(interface); }, true, position, text, parentRouteKey);
}

void FluWindowDemo::setQss()
{
    QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluNavigationPanel.qss");
    setStyleSheet(qss);
}

void FluWindowDemo::swithTo(QWidget* widget)
{
    m_stackWidget->setCurrentWidget(widget);
}

void FluWindowDemo::onCurrentInterfaceChanged(int nIndex)
{
    QWidget* widget = m_stackWidget->widget(nIndex);
    m_navigationInterface->setCurrentItem(widget->objectName());
}
