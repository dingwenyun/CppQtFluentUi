#include "FluNavigationTreeWidget.h"
#include "FluNavigationTreeItem.h"
#include "../FluentUiUtils/FluLogUtils.h"

FluNavigationTreeWidget::FluNavigationTreeWidget(QPixmap icon, QString text, bool bSelectable, QWidget* parent) : FluNavigationTreeWidgetBase(bSelectable, parent)
{
    // treeChildren = []
    m_bExpanded = false;

    m_itemWidget = new FluNavigationTreeItem(icon, text, bSelectable, this);
    m_vLayout = new QVBoxLayout(this);
    m_expandAni = new QPropertyAnimation(this, "geometry", this);

    __initWidget();
}

void FluNavigationTreeWidget::__initWidget()
{
    m_vLayout->setSpacing(4);
    m_vLayout->setContentsMargins(0, 0, 0, 0);
    m_vLayout->addWidget(m_itemWidget, 0, Qt::AlignTop);
    connect(m_itemWidget, &FluNavigationTreeItem::itemClicked, this, &FluNavigationTreeWidget::_onClicked);

    // 设置窗口透明
    setAttribute(Qt::WA_TranslucentBackground);
    connect(m_expandAni, &QPropertyAnimation::valueChanged, [this](const QVariant& variant) {
        QRect gemo = variant.toRect();
        setFixedSize(gemo.size());
    });
}

void FluNavigationTreeWidget::addChild(FluNavigationWidget* child)
{
    insertChild(-1, child);
}

QString FluNavigationTreeWidget::getText()
{
    return m_itemWidget->getText();
}

QPixmap FluNavigationTreeWidget::getIcon()
{
    return m_itemWidget->getIcon();
}

void FluNavigationTreeWidget::setText(QString text)
{
    m_itemWidget->setText(text);
}

void FluNavigationTreeWidget::setIcon(QPixmap icon)
{
    m_itemWidget->setIcon(icon);
}

void FluNavigationTreeWidget::setFont(QFont font)
{
    QWidget* pParentWidget = dynamic_cast<QWidget*>(parent());
    pParentWidget->setFont(font);
    m_itemWidget->setFont(font);
}

void FluNavigationTreeWidget::insertChild(int index, FluNavigationWidget* child)
{
    auto itf = std::find(m_treeChildren.begin(), m_treeChildren.end(), child);
    if (itf != m_treeChildren.end())
        return;

    child->setTreeParent(this);
    child->setNodeDepth(getNodeDepth() + 1);
    child->setVisible(m_bExpanded);

    FluNavigationTreeWidget* treeWidget = (FluNavigationTreeWidget*)child;
    connect(treeWidget->getExpandAni(), &QPropertyAnimation::valueChanged, [this]() { setFixedSize(sizeHint()); });

    if (index < 0)
        index = m_treeChildren.size();

    m_treeChildren.insert(index + m_treeChildren.begin(), (FluNavigationTreeWidget*)child);
    m_vLayout->insertWidget(index + 1, child, 0, Qt::AlignTop);
}

void FluNavigationTreeWidget::removeChild(FluNavigationWidget* child)
{
    auto itf = std::find(m_treeChildren.begin(), m_treeChildren.end(), child);
    if (itf != m_treeChildren.end())
        m_treeChildren.erase(itf);

    m_vLayout->removeWidget(child);
}

void FluNavigationTreeWidget::setExpanded(bool bExpanded, bool bAni)
{
    if (bExpanded == m_bExpanded)
        return;

    m_bExpanded = bExpanded;
    m_itemWidget->setExpanded(bExpanded);

    for (auto child : m_treeChildren)
    {
        child->setVisible(bExpanded);
        child->setFixedSize(child->sizeHint());
    }

    if (bAni)
    {
        m_expandAni->stop();
        m_expandAni->setStartValue(geometry());
        m_expandAni->setEndValue(QRect(pos(), sizeHint()));

        LogDebug << "expandAni start:" << geometry() << ","
                 << "end:" << QRect(pos(), sizeHint());
        m_expandAni->setDuration(120);
        m_expandAni->setEasingCurve(QEasingCurve::OutQuad);
        m_expandAni->start();
    }
    else
    {
        setFixedSize(sizeHint());
    }
}

void FluNavigationTreeWidget::setSelected(bool bSelected)
{
    FluNavigationTreeWidgetBase::setSelected(bSelected);
    m_itemWidget->setSelected(true);
}

void FluNavigationTreeWidget::mouseReleaseEvent(QMouseEvent* event)
{
    // pass
}

void FluNavigationTreeWidget::setCompacted(bool bCompacted)
{
    FluNavigationTreeWidgetBase::setCompacted(bCompacted);
    m_itemWidget->setCompacted(bCompacted);
}

void FluNavigationTreeWidget::_onClicked(bool triggerByUser, bool clickArrow)
{
    if (!getCompacted())
    {
        if (getSelectable() && !getSelected() && !clickArrow)
        {
            setExpanded(true, true);
        }
        else
        {
            setExpanded(!m_bExpanded, true);
        }
    }

    if (!clickArrow || getCompacted())
    {
        emitClicked(triggerByUser);
    }
}

void FluNavigationTreeWidget::_onSize(QVariant size)
{
    QRect tmpRect = size.toRect();
    // this->setFixedSize(tmpRect.width(), tmpRect.height());
    // LogDebug << "sizeHint[" << getText() << "]:" << sizeHint();
    setFixedSize(tmpRect.size());
}
