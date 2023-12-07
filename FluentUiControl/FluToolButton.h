#pragma once

#include <QToolButton>
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include "../FluentUiUtils/FluFontUtils.h"
#include <QPainter>

class FluToolButton : public QToolButton
{
    Q_OBJECT
  public:
    FluToolButton(QWidget* parent = nullptr) : QToolButton(parent)
    {
        // set qss

        m_bPressed = false;
        m_bHover = false;
        setIconSize(QSize(16, 16));
        setIcon(QIcon());
        FluFontUtils::setFont(this);

        QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluToolButton.qss");
        setStyleSheet(qss);
    }

    FluToolButton(FluAwesomeType awesomeType, QWidget* parent = nullptr) : FluToolButton(parent)
    {
        setIcon(FluIconUtils::GetFluentIcon(awesomeType));
    }

    FluToolButton(QIcon icon, QWidget* parent = nullptr) : FluToolButton(parent)
    {
        setIcon(icon);
    }

    void setIcon(const QIcon& icon)
    {
        m_icon = icon;
        update();
    }

    bool setProperty(const char* name, const QVariant& value)
    {
        if (name == nullptr || name != "icon")
        {
            return QToolButton::setProperty(name, value);
        }
        setIcon(value.value<QIcon>());
        return true;
    }

  protected:
    void mousePressEvent(QMouseEvent* event)
    {
        QToolButton::mousePressEvent(event);
        m_bPressed = true;
    }

    void mouseReleaseEvent(QMouseEvent* event)
    {
        QToolButton::mouseReleaseEvent(event);
        m_bPressed = false;
    }

    void enterEvent(QEnterEvent* event)
    {
        QToolButton::enterEvent(event);
        m_bHover = true;
        update();
    }

    void leaveEvent(QEvent* event)
    {
        QToolButton::leaveEvent(event);
        m_bHover = false;
        update();
    }

    void paintEvent(QPaintEvent* event)
    {
        QToolButton::paintEvent(event);
        if (m_icon.isNull())
            return;

        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        if (isEnabled())
        {
            painter.setOpacity(0.43);
        }
        else if (m_bPressed)
        {
            painter.setOpacity(0.63);
        }

        int iconW = iconSize().width();
        int iconH = iconSize().height();

        int nX = (width() - iconW) / 2;
        int nY = (height() - iconH) / 2;
        painter.drawPixmap(QRect(nX, nY, iconW, iconH), m_icon.pixmap(iconH, iconW));
    }

  protected:
    bool m_bPressed;
    bool m_bHover;
    QIcon m_icon;
};