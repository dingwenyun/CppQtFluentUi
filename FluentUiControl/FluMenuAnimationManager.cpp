#include "FluMenuAnimationManager.h"

FluMenuAnimationManager::FluMenuAnimationManager(FluRoundMenu* menu) : QObject()
{
    m_menu = menu;
    m_ani = new QPropertyAnimation((QObject*)menu, "pos", (QObject*)menu);
    m_ani->setDuration(250);
    m_ani->setEasingCurve(QEasingCurve::OutQuad);

    connect(m_ani, &QPropertyAnimation::valueChanged, this, &FluMenuAnimationManager::_onValueChanged);
    connect(m_ani, &QPropertyAnimation::valueChanged, this, &FluMenuAnimationManager::_updateMenuViewport);
}

QSize FluMenuAnimationManager::availableViewSize(QPoint pos)
{
    QRect screenRect = QApplication::screenAt(QCursor::pos())->availableGeometry();
    int w = screenRect.width() - 100;
    int h = screenRect.height() - 100;
    return QSize(w, h);
}

QPoint FluMenuAnimationManager::_endPosition(QPoint pos)
{
    QRect screenRect = QApplication::screenAt(QCursor::pos())->availableGeometry();
    int nMenuW = m_menu->width() + 5;
    int nMenuH = m_menu->height();

    int nX = qMin(pos.x() - m_menu->layout()->contentsMargins().left(), screenRect.right() - nMenuW);
    int nY = qMin(pos.y() - 4, screenRect.bottom() - nMenuH);

    return QPoint(nX, nY);
}

QSize FluMenuAnimationManager::_menuSize()
{
    QMargins contentMargins = m_menu->layout()->contentsMargins();
    int nW = m_menu->getView()->width() + contentMargins.left() + contentMargins.right() + 120;
    int nH = m_menu->getView()->height() + contentMargins.top() + contentMargins.bottom() + 20;
    return QSize(nW, nH);
}

void FluMenuAnimationManager::exec(QPoint pos)
{
    // pass
}

void FluMenuAnimationManager::_register(FluMenuAnimationType type, FluMenuAnimationManager* manager)
{
    m_managers[type] = manager;
}

FluRoundMenu* FluMenuAnimationManager::make(FluMenuAnimationType type)
{
    auto itf = m_managers.find(type);
    if (itf == m_managers.end())
        return nullptr;

    return itf->second->m_menu;
}

void FluMenuAnimationManager::_updateMenuViewport()
{
    if (m_menu == nullptr)
        return;

    FluMenuActionListWidget* view = m_menu->getView();
    if (view == nullptr)
        return;

    view->viewport()->update();
    view->setAttribute(Qt::WA_UnderMouse, true);

    QHoverEvent hoverEvent = QHoverEvent(QEvent::HoverEnter, QPoint(), QPoint(1, 1));
    QApplication::sendEvent(view, &hoverEvent);
}
