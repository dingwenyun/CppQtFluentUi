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
    virtual QPoint slideAniStartPos(FluInfoBar* infoBar) = 0;
    virtual QPoint slideAniEndPos(FluInfoBar* infoBar) = 0;
    virtual QPoint dropAniStartPos(FluInfoBar* infoBar) = 0;
    virtual QPoint dropAniEndPos(FluInfoBar* infoBar) = 0;
    virtual QPoint getInfoBarPos(FluInfoBar* infoBar) = 0;

  protected:
    int m_spacing;
    int m_margin;
    QMap<QWidget*, QList<FluInfoBar*>> m_infoBars;
    QMap<QWidget*, QParallelAnimationGroup*> m_aniGroups;
    QList<QPropertyAnimation*> m_slideAnis;
    QList<QPropertyAnimation*> m_dropAnis;
};

class FluInfoBarManagers : public QObject
{
    Q_OBJECT
  public:
    FluInfoBarManagers();
    ~FluInfoBarManagers();

    static FluInfoBarManagers* getInstance();
    static void addInfoBar(FluInfoBar* infoBar, FluInfoBarPositon postion);
    static FluInfoBarManager* getInfoBarManager(FluInfoBarPositon position);
    static FluInfoBar* __new(FluAwesomeType awesomeType, const QString& context, bool bClosable = true, int duration = 1000, FluInfoBarPositon position = FluInfoBarPositon::TOP, QWidget* parent = nullptr);
    static FluInfoBar* success(const QString& context, bool bClosable = true, int duration = 1000, FluInfoBarPositon position = FluInfoBarPositon::TOP, QWidget* parent = nullptr);

  public:
    QMap<FluInfoBarPositon, FluInfoBarManager*> m_managers;
  public:
    static FluInfoBarManagers* m_infoBarManagers;
};
