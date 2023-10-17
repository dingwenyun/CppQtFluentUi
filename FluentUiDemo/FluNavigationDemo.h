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
    Q_OBJECT
  public:
    FluWidgetDemo(QString text, QWidget* parent = nullptr);

  private:
    QLabel* m_label;
    QHBoxLayout* m_hLayout;
};

class FluWindowDemo : public FluFrameLessWidgetV1
{
    Q_OBJECT
  public:
    FluWindowDemo(QWidget* parent = nullptr);

    void __initLayout();

    void __initNavigation();

    void __initWindow();

    void addSubInterface(QWidget* interface, QPixmap icon, QString text, FluNavigationItemPosition position = FluNavigationItemPosition::TOP, QWidget* parent = nullptr);

    void setQss();

    void swithTo(QWidget* widget);

    void onCurrentInterfaceChanged(int nIndex);

  private:
    QHBoxLayout* m_hBoxLayout;
    // QWidget* m_centerWidget;
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
