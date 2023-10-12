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

    void addSubInterface(QWidget* interface, QIcon icon, QString str, FluNavigationItemPosition position = FluNavigationItemPosition::TOP, QWidget* parent = nullptr)
    {
        m_stackWidget->addWidget(interface);
        m_navigationInterface->addItem(interface->objectName(), icon, text, onClick, position, text, parent->objectName());
    }

    void swithTo(QWidget* widget)
    {
        m_stackWidget->setCurrentWidget(widget);
    }

  private:
    QHBoxLayout* m_hBoxLayout;
    FluNavigationInterface* m_navigationInterface;
    QStackedWidget* m_stackWidget;

    FluWidgetDemo* m_searchInterface;
    FluWindowDemo* m_musicInterface;
    FluWindowDemo* m_videoInterface;
    FluWindowDemo* m_folderInterface;
    FluWindowDemo* m_settingInterface;
    FluWindowDemo* m_albumInterface0;
    FluWindowDemo* m_albumInterface01;
    FluWindowDemo* m_albumInterface02;
    FluWindowDemo* m_albumInterface011;
};
