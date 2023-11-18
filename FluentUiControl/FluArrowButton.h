#pragma once

#include <QToolButton>
#include <QPainter>

class FluArrowButton : public QToolButton
{
    Q_OBJECT
  public:
    FluArrowButton(QPixmap icon, QWidget* parent = nullptr) : QToolButton(parent)
    {
        setFixedSize(10, 10);
        m_icon = icon;
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing);

        int s = 7;
        if (!isDown())
            s = 8;

        int x = (width() - s) / 2;
        painter.drawPixmap(QRect(x, x, s, s), m_icon);
    }

  private:
    QPixmap m_icon;
};