#pragma once

#include <QToolButton>
#include <QPixmap>
#include <QPainter>
#include <QLineEdit>
#include <QCompleter>

class FluLineEditButton : public QToolButton
{
  public:
    FluLineEditButton(QPixmap icon, QWidget *parent = nullptr) : QToolButton(parent)
    {
        m_icon = icon;
        m_bPressed = false;

        setFixedSize(31, 23);
        setIconSize(QSize(10, 10));
        setCursor(Qt::PointingHandCursor);
        setObjectName("lineEditButton");

        // mark it!
    }

  protected:
    void mousePressEvent(QMouseEvent *event)
    {
        QToolButton::mousePressEvent(event);
        m_bPressed = true;
    }

    void mouseReleaseEvent(QMouseEvent *event)
    {
        QToolButton::mousePressEvent(event);
        m_bPressed = false;
    }

    void paintEvent(QPaintEvent *event)
    {
        QToolButton::paintEvent(event);

        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        int iw = iconSize().width();
        int ih = iconSize().height();

        int w = width();
        int h = height();

        QRect rect((w - iw) / 2, (h - ih) / 2, iw, ih);
        if (m_bPressed)
            painter.setOpacity(0.7);

        // mark it!
        painter.drawPixmap(rect, m_icon);
    }

  private:
    QPixmap m_icon;
    bool m_bPressed;
};

class FluLineEdit : public QLineEdit
{
  public:
    FluLineEdit(QWidget *parent = nullptr) : QLineEdit(parent)
    {
    }

    ~FluLineEdit() noexcept
    {
    }

  private:
    bool m_bClearButtonEnable;
    //   bool
};