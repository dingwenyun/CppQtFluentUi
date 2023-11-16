#pragma once

#include <QWidget>
#include <QHBoxLayout>
#include <QCompleter>
#include "../FluentUiControl/FluLineEdit.h"
class FluLineEditDemo : public QWidget
{
  public:
    FluLineEditDemo(QWidget* parent = nullptr) : QWidget(nullptr)
    {
        m_hBoxLayout = new QHBoxLayout(this);
        m_lineEdit = new FluLineEdit(this);

        QList<QString> stands = {
            "Star Platinum", "Hierophant Green", "Made in Haven",     "King Crimson",      "Silver Chariot", "Crazy diamond",  "Metallica",        "Another One Bites The Dust",
            "Heaven's Door", "Killer Queen",     "The Grateful Dead", "Stone Free",        "The World",      "Sticky Fingers", "Ozone Baby",       "Love Love Deluxe",
            "Hermit Purple", "Gold Experience",  "King Nothing",      "Paper Moon King",   "Scary Monster",  "Mandom",         "20th Century Boy", "Tusk Act 4",
            "Ball Breaker",  "Sex Pistols",      "D4C • Love Train",  "Born This Way",     "SOFT & WET",     "Paisley Park",   "Wonder of U",      "Walking Heart",
            "Cream Starter", "November Rain",    "Smooth Operators",  "The Matte Kudasai",
        };

        m_completer = new QCompleter(stands, m_lineEdit);
        m_completer->setCaseSensitivity(Qt::CaseInsensitive);
        m_completer->setMaxVisibleItems(10);
        m_lineEdit->setCompleter(m_completer);

        resize(400, 400);
        m_hBoxLayout->setAlignment(Qt::AlignCenter);
        m_hBoxLayout->addWidget(m_lineEdit, 0, Qt::AlignCenter);

        m_lineEdit->setFixedSize(200, 33);
        m_lineEdit->setClearButtonEnabled(true);
        m_lineEdit->setPlaceholderText("Search stands");
    }

  private:
    QHBoxLayout* m_hBoxLayout;
    FluLineEdit* m_lineEdit;
    QCompleter* m_completer;
};
