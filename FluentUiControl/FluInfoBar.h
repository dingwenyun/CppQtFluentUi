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

// CompletedSolid
// InfoSolid
// InfoSolid
// StatusErrorFull
class FluInfoBar : public QFrame
{
    Q_OBJECT
  public:
    FluInfoBar(FluAwesomeType awesomeType, QString context, bool bClosable = true, int duration = 1000, FluInfoBarPositon position = FluInfoBarPositon::TOP, QWidget* parent = nullptr);

    void __initWidget();

    void __initLayout();

    void __setQss();

    void __fadeOut();

  protected:
    void closeEvent(QCloseEvent* event);

    void showEvent(QShowEvent* event);

  signals:
    void closeSignal();

  private:
    //  QString m_title; // 去掉title
    QString m_context;
    int m_duration;
    FluInfoBarPositon m_positon;

    //	QLabel *m_titleLabel;
    QLabel* m_contextLabel;

    FluInfoBarIconWidget* m_iconWidget;
    FluTransparentToolButton* m_closeButton;
    bool m_bClosable;  // 是否可以关闭

    FluAwesomeType m_awesomeType;
    QHBoxLayout* m_hBoxLayout;

    QGraphicsOpacityEffect* m_opacityEffect;
    QPropertyAnimation* m_opacityAni;
};
