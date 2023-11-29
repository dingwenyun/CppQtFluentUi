#pragma once

#include <QPushButton>
#include <QIcon>
#include <QApplication>
#include <QPainter>
#include <QPaintEvent>
#include <QMouseEvent>
#include "../FluentUiUtils/FluStyleSheetUitls.h"

class FluPushButton : public QPushButton
{
    Q_OBJECT
  public:
    FluPushButton(QWidget* parent);

    FluPushButton(QString text, QWidget* parent = nullptr, QIcon icon = QIcon());

    virtual void _postInit()
    {
    }

    void setIcon(QIcon icon);

    QIcon getIcon();

    void setFont(int fontSize = 14, QFont::Weight weight = QFont::Normal);

    QFont getFont(int fontSize = 14, QFont::Weight weight = QFont::Normal);

    void mousePressEvent(QMouseEvent* e)
    {
        m_isPressed = true;
        QPushButton::mousePressEvent(e);
        update();
    }

    void mouseReleaseEvent(QMouseEvent* e)
    {
        m_isPressed = false;
        QPushButton::mouseReleaseEvent(e);
        update();
    }

    void enterEvent(QEnterEvent* event)
    {
        m_isHover = true;
        update();
    }

    void leaveEvent(QEvent* event)
    {
        m_isHover = false;
        update();
    }

    void paintEvent(QPaintEvent* event);

  private:
    bool m_isPressed;
    bool m_isHover;
    QIcon m_icon;
};

class FluPrimaryPushButton : public FluPushButton
{
    Q_OBJECT
  public:
    FluPrimaryPushButton(QWidget* parent) : FluPushButton(parent)
    {
    }
    FluPrimaryPushButton(QString text, QWidget* parent = nullptr, QIcon icon = QIcon()) : FluPushButton(text, parent, icon)
    {
    }
};

class FluTransparentPushButton : public FluPushButton
{
};

class FluTogglePushButton : public FluPushButton
{
    Q_OBJECT
  public:
    void _postInit();
};