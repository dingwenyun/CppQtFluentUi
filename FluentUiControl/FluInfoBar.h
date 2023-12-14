#pragma once

#include <QFrame>
#include "FluDef.h"
#include "FluTransparentToolButton.h"
#include "FluInfoBarIconWidget.h"
#include <QHBoxLayout>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include <QTimer>

enum class FluInfoBarPositon
{
    NONE,
    TOP,
    BOTTOM,
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT,
};

enum class FluInfoBarType
{
    INFO,
    WARN,
    SUCC,
    ERR,
};

// CompletedSolid
// InfoSolid
// InfoSolid
// StatusErrorFull
class FluInfoBar : public QFrame
{
    Q_OBJECT
  public:
    FluInfoBar(FluAwesomeType awesomeType, FluInfoBarType type, QString context, bool bClosable = false, int duration = 1000, QWidget* parent = nullptr);

    void __initWidget();

    void __initLayout();

    void __setQss();

    void __fadeOut();

    static void __info(const QString& context, bool bClosable = false, int duration = 1000, QWidget* parent = nullptr);
    static void __warn(const QString& context, bool bClosable = false, int duration = 1000, QWidget* parent = nullptr);
    static void __succ(const QString& context, bool bClosable = false, int duration = 1000, QWidget* parent = nullptr);
    static void __err(const QString& context, bool bClosable = false, int duration = 1000, QWidget* parent = nullptr);

  protected:
    void closeEvent(QCloseEvent* event);

    void showEvent(QShowEvent* event);

  signals:
    void closeSignal();

  private:
    bool m_bClosable;
    int m_duration;
    QString m_context;
    FluInfoBarPositon m_positon;
    QLabel* m_contextLabel;
    FluInfoBarIconWidget* m_iconWidget;
    FluTransparentToolButton* m_closeButton;
    FluAwesomeType m_awesomeType;
    FluInfoBarType m_infoBarType;
    QHBoxLayout* m_hBoxLayout;
    QGraphicsOpacityEffect* m_opacityEffect;
    QPropertyAnimation* m_opacityAni;
};
