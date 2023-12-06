#pragma once

#include <QPushButton>
#include <QFont>
#include <QMouseEvent>

class FluPushButton : public QPushButton
{
    Q_OBJECT
  public:
    FluPushButton(QWidget* parent);
    FluPushButton(QString text, QWidget* parent = nullptr, QIcon icon = QIcon());

    void setIcon(QIcon icon);
    QIcon getIcon();

    void setFont(int fontSize = 14, QFont::Weight weight = QFont::Normal);
    QFont getFont(int fontSize = 14, QFont::Weight weight = QFont::Normal);

  protected:
    void mousePressEvent(QMouseEvent* e);

    void mouseReleaseEvent(QMouseEvent* e);

    void enterEvent(QEnterEvent* event);

    void leaveEvent(QEvent* event);

    void paintEvent(QPaintEvent* event);

  protected:
    bool m_isPressed;
    bool m_isHover;
    QIcon m_icon;
};