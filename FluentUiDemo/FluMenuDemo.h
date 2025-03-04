#pragma once

#include "../FluentUiControl/FluRoundMenu.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include <QWidget>
#include <QLabel>

class FluMenuDemo : public QWidget
{
  public:
    FluMenuDemo(QWidget* parent = nullptr) : QWidget(parent)
    {
        m_hLayout = new QHBoxLayout();
        setLayout(m_hLayout);

        m_label = new QLabel("Right click your mourse!", this);
        m_label->setAlignment(Qt::AlignCenter);
        m_hLayout->addWidget(m_label);

        resize(400, 400);
        setStyleSheet("FluMenuDemo{background: white} QLabel{font-size: 20px}");
    }

  protected:
    void contextMenuEvent(QContextMenuEvent* event)
    {
        FluRoundMenu* roundMenu = new FluRoundMenu("", this);

        QAction* copyAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Copy), "Copy");
        roundMenu->addAction(copyAction);

        QAction* cutAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Cut), "Cut");
        roundMenu->addAction(cutAction);

        FluRoundMenu* subRoundMenu = new FluRoundMenu("Add to", this);
        subRoundMenu->setIcon(FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Add));

        QAction* musicAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::MusicAlbum), "Music");
        QAction* videoAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Video), "Video");
        QList<QAction*> actions;
        actions.append(musicAction);
        actions.append(videoAction);
        subRoundMenu->addActions(actions);
        roundMenu->addMenu(subRoundMenu);

        QAction* pasteAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Paste), "Paste");
        roundMenu->addAction(pasteAction);

        QAction* undoAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Undo), "Undo");
        roundMenu->addAction(undoAction);

        roundMenu->addSeparator();

        QAction* selectAllAction = new QAction("Select all");
        selectAllAction->setShortcut(QKeySequence("Ctrl+A"));
        roundMenu->addAction(selectAllAction);

        QAction* settingAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Settings), "Setting");
        QAction* helpAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Help), "Help");
        QAction* feedbackAction = new QAction(FluIconUtils::GetFluentIcon(FluAwesomeType::Feedback), "Feedback");

        settingAction->setShortcut(QKeySequence("Ctrl+S"));
        helpAction->setShortcut(QKeySequence("Ctrl+H"));
        feedbackAction->setShortcut(QKeySequence("Ctrl+F"));

        roundMenu->addAction(settingAction);
        roundMenu->addAction(helpAction);
        roundMenu->addAction(feedbackAction);

        roundMenu->exec(event->globalPos(), true, FluMenuAnimationType::DROP_DOWN);
    }

  private:
    QLabel* m_label;
    QHBoxLayout* m_hLayout;
};
