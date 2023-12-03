#pragma once

#include "FluDef.h"
#include <QWidget>
#include <QPainter>
#include "../FluentUiUtils/FluIconUtils.h"
class FluIconWidget : public QWidget
{
    Q_PROPERTY(QIcon icon READ getIcon WRITE setIcon)
  public:
    FluIconWidget(QWidget* parent = nullptr) : QWidget(parent)
    {
        m_icon = QIcon();
    }

    FluIconWidget(QIcon icon, QWidget* parent = nullptr)
    {
        setIcon(icon);
    }

    FluIconWidget(FluAwesomeType type, QWidget* parent = nullptr)
    {
        setIcon(FluIconUtils::GetFluentIcon(type));
    }

    void setIcon(QIcon icon)
    {
        m_icon = icon;
        update();
    }

    QIcon getIcon()
    {
        return m_icon;
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
        painter.drawPixmap(rect(), m_icon.pixmap(size()));
    }

  private:
    QIcon m_icon;
};
