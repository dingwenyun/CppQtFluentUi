#include "FluInfoBarIconWidget.h"
#include "FluInfoBar.h"

FluInfoBarIconWidget::FluInfoBarIconWidget(FluAwesomeType awesomeType, FluInfoBarType type, QWidget* parent /*= nullptr*/) : QWidget(parent)
{
    setFixedSize(28, 28);
    m_awesomeType = awesomeType;
    m_infoBarType = type;
}

void FluInfoBarIconWidget::paintEvent(QPaintEvent* event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QRect rect(0, 0, 28, 28);

    QPixmap pixmap;
    switch (m_infoBarType)
    {
        case FluInfoBarType::INFO:
            pixmap = FluIconUtils::GetFluentIconPixmap(m_awesomeType, QColor(0, 102, 180));
            break;
        case FluInfoBarType::WARN:
            pixmap = FluIconUtils::GetFluentIconPixmap(m_awesomeType, QColor(157, 93, 0));
            break;
        case FluInfoBarType::SUCC:
            pixmap = FluIconUtils::GetFluentIconPixmap(m_awesomeType, QColor(15, 123, 15));
            break;
        case FluInfoBarType::ERR:
            pixmap = FluIconUtils::GetFluentIconPixmap(m_awesomeType, QColor(196, 43, 28));
            break;
        default:
            break;
    }
    painter.drawPixmap(rect, pixmap);
}
