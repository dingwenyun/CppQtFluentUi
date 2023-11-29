#pragma once

#include <FramelessHelper/Widgets/framelesswidget.h>
#include <QHBoxLayout>
#include "FluNavigationInterface.h"
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
class QLabel;
class QShortcut;
QT_END_NAMESPACE

FRAMELESSHELPER_BEGIN_NAMESPACE
class StandardTitleBar;
FRAMELESSHELPER_END_NAMESPACE

class FluFrameLessWindow : public FRAMELESSHELPER_PREPEND_NAMESPACE(FramelessWidget)
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(FluFrameLessWindow)

  public:
    explicit FluFrameLessWindow(QWidget *parent = nullptr);
    ~FluFrameLessWindow();

    void initialize();
    void waitReady();

    FluNavigationTreeWidget *addSubInterface(QWidget *interface, QPixmap icon, QString text, FluNavigationItemPosition position = FluNavigationItemPosition::TOP, QWidget *parentWidget = nullptr, bool bTransparent = false);

    void updateStackedBackground()
    {
        bool bCurrentWidgetTransparent = m_stackedWidget->currentWidget()->property("isStackedTransparent").value<bool>();
        bool bStatckedWidgetTransparent = m_stackedWidget->property("isStackedTransparent").value<bool>();

        if (bCurrentWidgetTransparent == bStatckedWidgetTransparent)
            return;

        m_stackedWidget->setProperty("isStackedTransparent", bCurrentWidgetTransparent);
        m_stackedWidget->setStyle(QApplication::style());
    }

  protected:
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

  public slots:
    void updateStyleSheet();
    void onCurrentInterfaceChanged(int nIndex);

  protected:
    FRAMELESSHELPER_PREPEND_NAMESPACE(StandardTitleBar) *m_titleBar = nullptr;
    // QWidget *m_centerWidget;
    QVBoxLayout *m_contentLayout;
    FluNavigationInterface *m_navigationInterface = nullptr;
    QStackedWidget *m_stackedWidget;
};
