#pragma once

#include <QWidget>
#include <QEnterEvent>
#include <QMouseEvent>
#include <QEvent>

class FluNavigationWidget : public QWidget
{
    Q_OBJECT
  public:
    FluNavigationWidget(bool bSelectable, QWidget* parent = nullptr);
  signals:
    void clicked(bool bClicked);

  protected:
    void enterEvent(QEnterEvent* event);

    void leaveEvent(QEvent* event);

    void mousePressEvent(QMouseEvent* event);

    void mouseReleaseEvent(QMouseEvent* event);

  public:
    void emitClicked(bool bClicked)
    {
        emit clicked(bClicked);
    }

    void click()
    {
        emit clicked(true);
    }

    // 获取是否在收缩状态
    bool getCompacted()
    {
        return m_bCompacted;
    }

    virtual void setCompacted(bool bCompacted)  // 是否收缩状态
    {
        if (m_bCompacted == bCompacted)
        {
            return;
        }

        m_bCompacted = bCompacted;
        if (m_bCompacted)
        {
            setFixedSize(40, 36);
        }
        else
        {
            setFixedSize(EXPAND_WIDTH, 36);
        }
        update();
    }

    bool getEnter()
    {
        return m_bEnter;
    }

    void setEnter(bool bEnter)
    {
        m_bEnter = bEnter;
    }

    bool getPressed()
    {
        return m_bPressed;
    }

    void setPressed(bool bPressed)
    {
        m_bPressed = bPressed;
    }

    bool getSelected()
    {
        return m_bSelected;
    }

    virtual void setSelected(bool bSelected)
    {
        if (!m_bSelectable)
        {
            return;
        }

        m_bSelected = bSelected;
        update();
    }

    bool getSelectable()
    {
        return m_bSelectable;
    }

    void setSelectable(bool bSelectable)
    {
        m_bSelectable = bSelectable;
    }

    virtual bool isRoot()
    {
        return true;
    }

    virtual bool isLeaf()
    {
        return true;
    }

    FluNavigationWidget* getTreeParent()
    {
        return m_treeParent;
    }

    void setTreeParent(FluNavigationWidget* treeParent)
    {
        m_treeParent = treeParent;
    }

    int getNodeDepth()
    {
        return m_nNodeDepth;
    }

    void setNodeDepth(int nNodeDepth)
    {
        m_nNodeDepth = nNodeDepth;
    }

    int getEXPAND_WIDTH()
    {
        return EXPAND_WIDTH;
    }


  private:
    int EXPAND_WIDTH = 312;

  private:
    bool m_bCompacted;
    bool m_bSelected;
    bool m_bPressed;
    bool m_bEnter;
    bool m_bSelectable;

    FluNavigationWidget* m_treeParent;
    int m_nNodeDepth;
};
