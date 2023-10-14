#include "../FluentUiControl/FluDef.h"
#include <QWidget>
#include <QFrame>
#include <QLabel>
#include <QHBoxLayout>
#include <QStackedWidget>
#include <QApplication>
#include <QScreen>
#include "../FluentUiControl/FluNavigationPanel.h"
#include "../FluentUiControl/FluFrameLessWidgetV1.h"
#include "../FluentUiControl/FluNavigationInterface.h"

class FluWidgetDemo : public QFrame
{
  public:
    FluWidgetDemo(QString text, QWidget* parent = nullptr) : QFrame(parent)
    {
        m_label = new QLabel(text, this);
        m_label->setAlignment(Qt::AlignCenter);

        m_hLayout = new QHBoxLayout(this);
        m_hLayout->addWidget(m_label, 1, Qt::AlignCenter);
        setObjectName(text.replace(" ", "-"));
    }

  private:
    QLabel* m_label;
    QHBoxLayout* m_hLayout;
};

class FluWindowDemo : public FluFrameLessWidgetV1
{
  public:
    FluWindowDemo(QWidget* parent = nullptr) : FluFrameLessWidgetV1(parent)
    {
        m_hBoxLayout = new QHBoxLayout(this);
        m_navigationInterface = new FluNavigationInterface(this, true, false);
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
    }

    void __initLayout()
    {
        m_hBoxLayout->setSpacing(0);
        m_hBoxLayout->setContentsMargins(0, 0, 0, 0);
        m_hBoxLayout->addWidget(m_navigationInterface);
        m_hBoxLayout->addWidget(m_stackWidget, 1);
    }

    void __initNavigation()
    {
        addSubInterface(m_searchInterface, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::Search), "Search");
        addSubInterface(m_musicInterface, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::MusicAlbum), "Music library");
        addSubInterface(m_videoInterface, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::Video), "Video library");

        m_navigationInterface->addSeparator();

        addSubInterface(m_albumInterface0, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::MusicAlbum), "albums", FluNavigationItemPosition::SCROLL);
        addSubInterface(m_albumInterface01, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::MusicAlbum), "albums 01", FluNavigationItemPosition::TOP, m_albumInterface0);
        addSubInterface(m_albumInterface011, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::MusicAlbum), "albums 011", FluNavigationItemPosition::TOP, m_albumInterface01);
        addSubInterface(m_albumInterface02, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::MusicAlbum), "albums 02", FluNavigationItemPosition::TOP, m_albumInterface0);
    }

    void __initWindow()
    {
        resize(900, 700);

        QRect desktopRect = QApplication::primaryScreen()->geometry();
        int nW = desktopRect.width();
        int nH = desktopRect.height();
        move(nW / 2 - width() / 2, nH / 2 - height() / 2);
    }

    void __setQss()
    {
    }

    void addSubInterface(QWidget* interface, QPixmap icon, QString text, FluNavigationItemPosition position = FluNavigationItemPosition::TOP, QWidget* parent = nullptr)
    {
        m_stackWidget->addWidget(interface);

        QString parentRouteKey = "";
        if (parent != nullptr)
        {
            parentRouteKey = parent->objectName();
        }
        m_navigationInterface->addItem(
            interface->objectName(), icon, text, []() {}, true, position, text, parentRouteKey);
    }

    void setQss()
    {
    }

    void swithTo(QWidget* widget)
    {
        m_stackWidget->setCurrentWidget(widget);
    }

    void onCurrentInterfaceChanged(int nIndex)
    {
        QWidget* widget = m_stackWidget->widget(nIndex);
        m_navigationInterface->setCurrentItem(widget->objectName());
    }

  private:
    QHBoxLayout* m_hBoxLayout;
    FluNavigationInterface* m_navigationInterface;
    QStackedWidget* m_stackWidget;

    FluWidgetDemo* m_searchInterface;
    FluWidgetDemo* m_musicInterface;
    FluWidgetDemo* m_videoInterface;
    FluWidgetDemo* m_folderInterface;
    FluWidgetDemo* m_settingInterface;
    FluWidgetDemo* m_albumInterface0;
    FluWidgetDemo* m_albumInterface01;
    FluWidgetDemo* m_albumInterface02;
    FluWidgetDemo* m_albumInterface011;
};
