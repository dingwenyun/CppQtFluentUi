#include "FluNavigationTreeItem.h"

FluNavigationTreeItem::FluNavigationTreeItem(QPixmap icon, QString text, bool bSelectable, QWidget* parent /*= nullptr*/) : FluNavigationPushButton(icon, text, bSelectable, parent)
{
    m_nArrowAngle = 0;
    m_rotateAni = new QPropertyAnimation(this, "arrowAngle", this);
}

void FluNavigationTreeItem::setExpanded(bool bExpanded)
{
    m_rotateAni->stop();
    if (!bExpanded)
    {
        m_rotateAni->setEndValue(0);
        m_rotateAni->setDuration(150);
        m_rotateAni->start();
    }

    if (bExpanded)
    {
        m_rotateAni->setEndValue(180);
        m_rotateAni->setDuration(150);
        m_rotateAni->start();
    }
}

bool FluNavigationTreeItem::_canDrawIndicator()
{
    FluNavigationWidget* parentWidget = dynamic_cast<FluNavigationWidget*>(parent());
    if (parentWidget->isLeaf() || parentWidget->getSelected())
        return parentWidget->getSelected();

    FluNavigationTreeWidget* parentTreeWidget = dynamic_cast<FluNavigationTreeWidget*>(parentWidget);
    if (parentTreeWidget == nullptr)
        return false;

    QVector<FluNavigationWidget*> treeChildren = parentTreeWidget->childItems();
    for (auto itBeg = treeChildren.begin(); itBeg != treeChildren.end(); itBeg++)
    {
        auto treeWidget = dynamic_cast<FluNavigationTreeWidget*>(*itBeg);
        if (treeWidget->getTreeItemWidget()->_canDrawIndicator() && !treeWidget->isVisible())
        {
            return true;
        }
    }

    return false;
}

QMargins FluNavigationTreeItem::_margins()
{
    FluNavigationTreeWidget* parentWidget = dynamic_cast<FluNavigationTreeWidget*>(parent());
    if (parentWidget == nullptr)
        return QMargins(0, 0, 0, 0);

    if (!parentWidget->childItems().empty())
        return QMargins(parentWidget->getNodeDepth() * 28, 0, 0, 0);

    return QMargins(parentWidget->getNodeDepth() * 28, 0, 20, 0);
}

void FluNavigationTreeItem::paintEvent(QPaintEvent* event)
{
    FluNavigationPushButton::paintEvent(event);
    FluNavigationTreeWidget* parentWidget = dynamic_cast<FluNavigationTreeWidget*>(parent());
    if (getCompacted() || parentWidget->childItems().empty())
        return;

    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);

    if (getPressed())
        painter.setOpacity(0.7);  // 按下

    if (!isEnabled())  // 是有被禁用
        painter.setOpacity(0.4);

    painter.translate(width() - 20, 18);
    painter.rotate(m_nArrowAngle);
    painter.drawPixmap(QRect(-5, -5, 10, 10), FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::ChevronDown));
}

void FluNavigationTreeItem::mouseReleaseEvent(QMouseEvent* event)
{
    FluNavigationPushButton::mouseReleaseEvent(event);
    //判断是否点击了"箭头"
    QRect tmpArrowRect = QRect(width() - 30, 8, 20, 20);
    bool bClickArrow = tmpArrowRect.contains(event->pos());
    FluNavigationWidget* parentWidget = dynamic_cast<FluNavigationWidget*>(parent());
    emit itemClicked(true, bClickArrow && !parentWidget->isLeaf());
    update();
}
