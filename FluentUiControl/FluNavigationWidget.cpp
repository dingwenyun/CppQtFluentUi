#include "FluNavigationWidget.h"

FluNavigationWidget::FluNavigationWidget(bool bSelectable, QWidget* parent /*= nullptr*/) : QWidget(parent)
{
    m_bCompacted = true;
    m_bSelected = false;
    m_bPressed = false;
    m_bEnter = false;
    m_bSelectable = bSelectable;
    m_treeParent = nullptr;
    m_nNodeDepth = 0;
    setFixedSize(40, 36);
}

void FluNavigationWidget::enterEvent(QEnterEvent* event)
{
    m_bEnter = true;
    update();
}

void FluNavigationWidget::leaveEvent(QEvent* event)
{
    m_bEnter = false;
    m_bPressed = false;
    update();
}

void FluNavigationWidget::mousePressEvent(QMouseEvent* event)
{
    QWidget::mousePressEvent(event);
    m_bPressed = true;
    update();
}

void FluNavigationWidget::mouseReleaseEvent(QMouseEvent* event)
{
    QWidget::mouseReleaseEvent(event);
    m_bPressed = false;
    update();
    emit clicked(true);
}
