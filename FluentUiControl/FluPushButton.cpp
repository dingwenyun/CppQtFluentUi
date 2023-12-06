#include "FluPushButton.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include <QApplication>
#include <QPainter>

FluPushButton::FluPushButton(QWidget* parent) : QPushButton(parent)
{
    m_isPressed = false;
    m_isHover = false;
    setIconSize(QSize(16, 16));
    setIcon(QIcon());

    setFont();
    // setAttribute(Qt::WA_StyledBackground, true);
    //_postInit();

    QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluPushButton.qss");
    setStyleSheet(qss);

    //_postInit();
}

FluPushButton::FluPushButton(QString text, QWidget* parent /*= nullptr*/, QIcon icon /*= QIcon()*/) : FluPushButton(parent)
{
    setText(text);
    setIcon(icon);
}

void FluPushButton::setIcon(QIcon icon)
{
    setProperty("hasIcon", !icon.isNull());
    setStyle(QApplication::style());
    m_icon = icon;
    update();
}

QIcon FluPushButton::getIcon()
{
    return m_icon;
}

void FluPushButton::setFont(int fontSize /*= 14*/, QFont::Weight weight /*= QFont::Normal*/)
{
    QPushButton::setFont(getFont(fontSize, weight));
}

QFont FluPushButton::getFont(int fontSize /*= 14*/, QFont::Weight weight /*= QFont::Normal*/)
{
    QFont font;
    font.setFamilies({"Segoe UI", "Microsoft YaHei"});
    font.setPixelSize(fontSize);
    font.setWeight(weight);
    return font;
}

void FluPushButton::mousePressEvent(QMouseEvent* e)
{
    m_isPressed = true;
    QPushButton::mousePressEvent(e);
    update();
}

void FluPushButton::mouseReleaseEvent(QMouseEvent* e)
{
    m_isPressed = false;
    QPushButton::mouseReleaseEvent(e);
    update();
}

void FluPushButton::enterEvent(QEnterEvent* event)
{
    m_isHover = true;
    update();
}

void FluPushButton::leaveEvent(QEvent* event)
{
    m_isHover = false;
    update();
}

void FluPushButton::paintEvent(QPaintEvent* event)
{
    QPushButton::paintEvent(event);
    if (m_icon.isNull())
        return;

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    if (!isEnabled())
        painter.setOpacity(0.3628);
    else if (m_isPressed)
        painter.setOpacity(0.786);

    int iconW = iconSize().width();
    int iconH = iconSize().height();

    int minW = minimumSizeHint().width();
    int y = (height() - iconH) / 2;
    int x = 12;

    // 绘制按钮时也有一些效果
    QPixmap pixmap = m_icon.pixmap(iconW, iconH);
    painter.drawPixmap(x, y, pixmap);
}
