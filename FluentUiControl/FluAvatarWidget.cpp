#include "FluAvatarWidget.h"

FluAvatarWidget::FluAvatarWidget(QWidget* parent /*= nullptr*/) : FluImageLabel(parent)
{
    _postInit();
}

FluAvatarWidget::FluAvatarWidget(QString image, QWidget* parent /*= nullptr*/) : FluImageLabel(image, parent)
{
    _postInit();
}

FluAvatarWidget::FluAvatarWidget(QImage image, QWidget* parent /*= nullptr*/) : FluImageLabel(image, parent)
{
    _postInit();
}

FluAvatarWidget::FluAvatarWidget(QPixmap image, QWidget* parent /*= nullptr*/) : FluImageLabel(image, parent)
{
    _postInit();
}

void FluAvatarWidget::_postInit()
{
    setRadius(48);
}

int FluAvatarWidget::getRadius()
{
    return m_radius;
}

void FluAvatarWidget::setRadius(int radius)
{
    m_radius = radius;
    setFixedSize(radius * 2, radius * 2);
    update();
}

void FluAvatarWidget::paintEvent(QPaintEvent* event)
{
    if (isNull())
        return;

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);

    m_image = m_image.scaled(size() * devicePixelRatioF(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation);

    int iw = m_image.width();
    int ih = m_image.height();
    int d = getRadius() * 2 * devicePixelRatioF();
    int x = (iw - d) / 2;
    int y = (ih - d) / 2;

    m_image = m_image.copy(x, y, d, d);

    QPainterPath path = QPainterPath();
    path.addEllipse(QRectF(rect()));
    painter.setPen(Qt::NoPen);
    painter.setClipPath(path);
    painter.drawImage(rect(), m_image);
}
