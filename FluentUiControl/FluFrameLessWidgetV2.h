#pragma once

#include <FramelessHelper/Widgets/framelesswidget.h>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
class QLabel;
class QShortcut;
QT_END_NAMESPACE

FRAMELESSHELPER_BEGIN_NAMESPACE
class StandardTitleBar;
FRAMELESSHELPER_END_NAMESPACE

class FluFrameLessWidgetV2 : public FRAMELESSHELPER_PREPEND_NAMESPACE(FramelessWidget)
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(FluFrameLessWidgetV2)

  public:
    explicit FluFrameLessWidgetV2(QWidget *parent = nullptr);
    ~FluFrameLessWidgetV2() override;

    void waitReady();

  protected:
    void closeEvent(QCloseEvent *event) override;

  private:
    void initialize();

  private Q_SLOTS:
    void updateStyleSheet();

  protected:
    FRAMELESSHELPER_PREPEND_NAMESPACE(StandardTitleBar) *m_titleBar = nullptr;
    // QWidget *m_centerWidget;
    QHBoxLayout *m_contentLayout;
};
