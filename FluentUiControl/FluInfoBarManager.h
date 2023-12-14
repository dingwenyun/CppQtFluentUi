#pragma once

#include "FluDef.h"
#include <QObject>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include "FluInfoBar.h"

// class FluInfoBar;
// enum class FluInfoBarPositon;
class FluInfoBarManager : public QObject
{
    Q_OBJECT
  public:
    FluInfoBarManager();
    void addInfoBar(FluInfoBar* infoBar);
    void removeInfoBar(FluInfoBar* infoBar);
    QPropertyAnimation* createSlideAni(FluInfoBar* infoBar);
    void updateDropAni(QWidget* parentWidget);
    QPoint slideAniStartPos(FluInfoBar* infoBar);
    QPoint slideAniEndPos(FluInfoBar* infoBar);
    QPoint dropAniStartPos(FluInfoBar* infoBar);
    QPoint dropAniEndPos(FluInfoBar* infoBar);
    QPoint getInfoBarPos(FluInfoBar* infoBar);

    static FluInfoBarManager* getInstance();
    static FluInfoBar* __new(FluAwesomeType awesomeType, FluInfoBarType type, const QString& context, bool bClosable = true, int duration = 1000, QWidget* parent = nullptr);
    static void __info(const QString& context, bool bClosable = true, int duration = 1000, QWidget* parent = nullptr);
    static void __warn(const QString& context, bool bClosable = true, int duration = 1000, QWidget* parent = nullptr);
    static void __succ(const QString& context, bool bClosable = true, int duration = 1000, QWidget* parent = nullptr);
    static void __err(const QString& context, bool bClosable = true, int duration = 1000, QWidget* parent = nullptr);

  protected:
    int m_spacing;
    int m_margin;
    QMap<QWidget*, QList<FluInfoBar*>> m_infoBars;
    QMap<QWidget*, QParallelAnimationGroup*> m_aniGroups;
    QList<QPropertyAnimation*> m_slideAnis;
    QList<QPropertyAnimation*> m_dropAnis;

  private:
    static FluInfoBarManager* m_infoBarManager;
};
