#pragma once

#include "FluNavigationTreeWidgetBase.h"
//#include "FluNavigationTreeItem.h"
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <algorithm>

class FluNavigationTreeItem;
class FluNavigationTreeWidget : public FluNavigationTreeWidgetBase
{
    Q_OBJECT
  public:
    FluNavigationTreeWidget(QPixmap icon, QString text, bool bSelectable, QWidget* parent);

    void __initWidget();

    void addChild(FluNavigationWidget* child);

    QString getText();

    QPixmap getIcon();

    void setText(QString text);

    void setIcon(QPixmap icon);

    void setFont(QFont font);

    void insertChild(int index, FluNavigationWidget* child);

    void removeChild(FluNavigationWidget* child);

    // QVector<FluNavigationTreeWidget*> getTreeChildren()
    //{
    //	return m_treeChildren;
    //}

    QVector<FluNavigationWidget*> childItems()
    {
        return m_treeChildren;
    }

    FluNavigationTreeItem* getTreeItemWidget()
    {
        return m_itemWidget;
    }

    void setExpanded(bool bExpanded, bool bAni = false);

    bool isRoot()
    {
        return getTreeParent() == nullptr;
    }

    bool isLeaf()
    {
        return m_treeChildren.empty();
    }

    void setSelected(bool bSelected);

    void setCompacted(bool bCompacted);

    QPropertyAnimation* getExpandAni()
    {
        return m_expandAni;
    }
  protected:
    void mouseReleaseEvent(QMouseEvent* event);

  public slots:
    void _onClicked(bool triggerByUser, bool clickArrow);
    void _onSize(QVariant size);

  private:
    QPropertyAnimation* m_expandAni;
    QVector<FluNavigationWidget*> m_treeChildren;
    FluNavigationTreeItem* m_itemWidget;
    QVBoxLayout* m_vLayout;
    bool m_bExpanded;
};
