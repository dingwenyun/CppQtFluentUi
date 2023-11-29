#pragma once

#include "FluNavigationPushButton.h"

class FluNavigationBarPushButton : public FluNavigationPushButton
{
    Q_OBJECT
  public:
    FluNavigationBarPushButton(QPixmap icon, QString text, bool bSelectable, QPixmap selectedIcon = QPixmap(), QWidget* parent = nullptr) : FluNavigationPushButton(icon, text, bSelectable, parent)
    {
        m_selectedIcon = selectedIcon;
        setFixedSize(64, 58);
        // setFont(11);
    }

    QPixmap getSelectedIcon()
    {
        return m_selectedIcon;
    }

    void setSelectedIcon(QPixmap icon)
    {
        m_selectedIcon = icon;
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
        painter.setPen(Qt::NoPen);

        if (getSelected())
        {
            if (FluThemeUtils::getInstance()->getThemeMode() == FluThemeMode::Dark)
            {
                painter.setBrush(QColor(255, 255, 255, 42));
            }
            else
            {
                painter.setBrush(Qt::white);
            }

            // mark it!
            painter.setBrush(Qt::blue);
            if (!getPressed())
            {
                painter.drawRoundedRect(0, 16, 4, 24, 2, 2);
            }
            else
            {
                painter.drawRoundedRect(0, 19, 4, 18, 2, 2);
            }
        }

        if (!getSelected() && (getPressed() || getEnter()))
        {
            int alpha = 6;
            if (getEnter())
                alpha = 9;

            int c = 0;
            if (FluThemeUtils::getInstance()->getThemeMode() == FluThemeMode::Dark)
            {
                c = 255;
            }
            painter.setBrush(QColor(c, c, c, alpha));
            painter.drawRoundedRect(rect(), 5, 5);
        }

        if ((getPressed() && !getEnter()) && !getSelected())
            painter.setOpacity(0.6);
        if (!isEnabled())
            painter.setOpacity(0.4);

        if (getSelected())
        {
            if (m_selectedIcon.isNull())
                painter.drawPixmap(rect(), m_selectedIcon);
            else
                painter.drawPixmap(rect(), getIcon());
        }
        else
        {
            painter.drawPixmap(rect(), getIcon());
        }

        if (getSelected())
            painter.setPen(Qt::blue);  // theme color
        else
        {
            if (FluThemeUtils::getInstance()->getThemeMode() == FluThemeMode::Dark)
            {
                painter.setPen(Qt::white);
            }
            else
            {
                painter.setPen(Qt::black);
            }
        }

        painter.setFont(font());
        painter.drawText(0, 32, width(), 26, Qt::AlignCenter, getText());
    }

  private:
    QPixmap m_selectedIcon;
};
