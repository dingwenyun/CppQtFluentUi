#pragma once

#include "FluGalleryInterface.h"
#include "FluButton.h"
#include "FluRoundMenu.h"
#include "../FluentUiUtils/FluColorUtils.h"
#include <QAction>

class FluMenuInterface : public FluGalleryInterface
{
    Q_OBJECT
  public:
    FluMenuInterface(QWidget* parent = nullptr) : FluGalleryInterface("菜单与工具栏", "FlunetUiControl::Menu", parent)
    {
        setObjectName("menuInterface");

        initContextMenu();
    }

    FluRoundMenu* buildRoundMenu()
    {
        FluRoundMenu* roundMenu = new FluRoundMenu("", this);

        QAction* copyAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Copy), "复制");
        QAction* cutAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Cut), "剪切");

        roundMenu->addAction(copyAction);
        roundMenu->addAction(cutAction);

        FluRoundMenu* subRoundMenu = new FluRoundMenu("添加到", this);
        QAction* videoAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Video), "视频");
        QAction* musicAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::MusicSharing), "音乐");
        subRoundMenu->addActions({videoAction, musicAction});
        roundMenu->addMenu(subRoundMenu);

        QAction* pasteAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Paste), "黏贴");
        QAction* undoAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Undo), "撤回");
        roundMenu->addActions({pasteAction, undoAction});

        roundMenu->addSeparator();

        QAction* settingsAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Settings), "设置");
        roundMenu->addAction(settingsAction);

        QAction* helpAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Help), "帮助");
        QAction* feedbackAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Feedback), "反馈");
        roundMenu->addActions({helpAction, feedbackAction});

        QAction* selectAllAction = new QAction("全部选择");
        roundMenu->addAction(selectAllAction);

        return roundMenu;
    }

    void initContextMenu()
    {
        m_contextMenu = buildRoundMenu();
        FluPushButton* button = new FluPushButton("显示菜单", this);
        connect(button, &FluPushButton::clicked, [=](bool bClicked) {
            QPoint pos = button->mapToGlobal(QPoint(button->width() + 5, -100));
            m_contextMenu->exec(pos, true);
            });

        addExampleCard("圆角菜单", button, "");
    }

    private:
        FluRoundMenu* m_contextMenu;
};
