#pragma once

#include <QObject>
#include <QList>

#include "FluComboItem.h"
#include "FluComboBoxMenu.h"
#include <QPixmap>
#include <QVariant>

class FluComboBoxBase : public QPushButton
{
    Q_OBJECT
  public:
    FluComboBoxBase(QWidget* parent = nullptr) : QPushButton(parent)
    {
        installEventFilter(this);
    }

    void addItem(QString text, QPixmap icon = QPixmap(), QVariant userData = QVariant::fromValue(nullptr))
    {
        FluComboItem* item = new FluComboItem(text, icon, userData);
        m_items.append(item);
        if (m_items.count() == 1)
            setCurrentIndex(0);
    }

    void addItems(QList<QString> texts)
    {
        for (auto itList = texts.begin(); itList != texts.end(); itList++)
        {
            addItem((*itList));
        }
    }

    void removeItem(int nIndex)
    {
        bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
        if (!bCorrect)
            return;

        auto itf = m_items.begin() + nIndex;
        m_items.erase(itf);

        if (nIndex < m_currentIndex)
        {
            _onItemClicked(m_currentIndex - 1);
        }
        else if (nIndex == m_currentIndex)
        {
            if (nIndex > 0)
                _onItemClicked(m_currentIndex - 1);
            else
            {
                setCurrentIndex(0);
                emit currentIndexChanged(0);
                emit currentTextChanged(getCurrentText());
            }
        }
    }

    int getCurrentIndex()
    {
        return m_currentIndex;
    }

    void setCurrentIndex(int nIndex)
    {
        bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
        if (!bCorrect)
        {
            return;
        }

        m_currentIndex = nIndex;
    }

    QString getCurrentText()
    {
        bool bCorrect = m_currentIndex >= 0 && m_currentIndex < m_items.count();
        if (!bCorrect)
            return "";

        auto itf = m_items.begin() + m_currentIndex;
        return (*itf)->getText();
    }

    void setCurrentText(QString text)
    {
        if (text == getCurrentText())
            return;

        int nIndex = findText(text);
        if (nIndex >= 0)
        {
            setCurrentIndex(nIndex);
        }
    }

    QString getItemText(int nIndex)
    {
        bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
        if (!bCorrect)
            return "";

        auto itf = m_items.begin() + nIndex;
        return (*itf)->getText();
    }

    void setItemText(int nIndex, QString text)
    {
        bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
        if (!bCorrect)
            return;

        auto itf = m_items.begin() + nIndex;
        (*itf)->setText(text);
    }

    QVariant getItemData(int nIndex)
    {
        bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
        if (!bCorrect)
            return QVariant::fromValue(nullptr);

        auto itf = m_items.begin() + nIndex;
        return (*itf)->getUserData();
    }

    FluComboItem* getComboItem(int nIndex)
    {
        bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
        if (!bCorrect)
            return nullptr;

       auto itf = m_items.begin() + nIndex;
        return (*itf);
    }

    QPixmap getItemIcon(int nIndex)
    {
        FluComboItem* item = getComboItem(nIndex);
        if (item == nullptr)
            return QPixmap();

        return item->getIcon();
    }

    void setItemIcon(int nIndex, QPixmap pixmap)
    {
        FluComboItem* item = getComboItem(nIndex);
        if (item == nullptr)
            return;

        item->setIcon(pixmap);
    }

    int findText(QString text)
    {
        for (int i = 0; i < m_items.count(); i++)
        {
            FluComboItem* item = m_items.at(i);
            if (item->getText() == text)
            {
                return i;
            }
        }

        return -1;
    }

     void clear()
    {
        m_items.clear();
        m_currentIndex = -1;
    }

    int count()
    {
        return m_items.count();
    }

    void insertItem(int nIndex, QString text, QPixmap icon, QVariant userData)
    {
        FluComboItem* item = new FluComboItem(text, icon, userData);
        m_items.insert(nIndex, item);
        if (nIndex <= m_currentIndex)
            _onItemClicked(m_currentIndex + 1);
    }

    void insertItems(int nIndex, QList<QString> texts)
    {
        int nPos = nIndex;
        for (auto itList = texts.begin(); itList != texts.end(); itList++)
        {
            FluComboItem* item = new FluComboItem(*itList);
            m_items.insert(nPos, item);
            nPos++;
        }

        if (nIndex <= m_currentIndex)
            _onItemClicked(m_currentIndex + nPos - nIndex);
    }

    int getMaxVisibleItems()
    {
        return m_maxVisibleItems;
    }

    void setMaxVisibleItems(int nNum)
    {
        m_maxVisibleItems = nNum;
    }

    void _closeComboMenu()
    {
        if (!m_dropMenu)
            return;

        m_dropMenu->close();
        m_dropMenu = nullptr;
    }

    void _showComboMenu()
    {
        if (m_items.isEmpty())
            return;

        FluComboBoxMenu* comboBoxMenu = new FluComboBoxMenu((QWidget*)this);
        for (auto itList = m_items.begin(); itList != m_items.end(); itList++)
        {
            FluComboItem* item = (*itList);
            QAction* action = new QAction(item->getIcon(), item->getText(), this);

            connect(action, &QAction::toggle, [=] {
                int nIndex = itList - m_items.begin();
                _onItemClicked(nIndex);
            });

            comboBoxMenu->addAction(action);
        }


        QWidget* thiswidget = (QWidget*)this;
        if (comboBoxMenu->getView()->width() < thiswidget->width())
        {
            comboBoxMenu->setMinimumWidth(thiswidget->width());
            comboBoxMenu->adjustSize();
        }

        comboBoxMenu->setMaxVisibleItems(m_maxVisibleItems);
        connect(comboBoxMenu, &FluComboBoxMenu::closedSignal, this, &FluComboBoxBase::_closeComboMenu);
        m_dropMenu = comboBoxMenu;

        if (m_currentIndex >= 0 && !m_items.isEmpty())
        {
            comboBoxMenu->setDefaultAction(m_currentIndex);
        }

        int nX = thiswidget->width() / 2 + comboBoxMenu->layout()->contentsMargins().left() - comboBoxMenu->width() / 2;
        QPoint pd = thiswidget->mapToGlobal(QPoint(nX, thiswidget->height()));
        int hd = comboBoxMenu->getView()->heightForAnimation(pd, FluMenuAnimationType::DROP_DOWN);
        
        QPoint pu = thiswidget->mapToGlobal(QPoint(nX, 0));
        int hu = comboBoxMenu->getView()->heightForAnimation(pu, FluMenuAnimationType::PULL_UP);

        if (hd > hu)
        {
            comboBoxMenu->getView()->adjustSize(pd, FluMenuAnimationType::DROP_DOWN);
            comboBoxMenu->exec(pd, true, FluMenuAnimationType::DROP_DOWN);
        }
        else
        {
            comboBoxMenu->getView()->adjustSize(pu, FluMenuAnimationType::PULL_UP);
            comboBoxMenu->exec(pu, true, FluMenuAnimationType::PULL_UP);
        }

    }


  //  void setText(QString text)
  //  {
  //  }

    void _toggleComboMenu()
    {
        if (m_dropMenu)
            _closeComboMenu();
        else
            _showComboMenu();
    }

    void _onItemClicked(int nIndex)
    {
        if (nIndex == m_currentIndex)
            return;

        setCurrentIndex(nIndex);

    }
signals:
  void currentIndexChanged(int nIndex);
  void currentTextChanged(QString text);
protected:
    bool eventFilter(QObject* watched, QEvent* event)
    {
        if (watched == this)
        {
            if (event->type() == QEvent::MouseButtonPress)
                m_bPressed = true;
            else if (event->type() == QEvent::MouseButtonRelease)
                m_bPressed = false;
            else if (event->type() == QEvent::Enter)
                m_bHover = true;
            else if (event->type() == QEvent::Leave)
                m_bHover = false;
        }

        return QObject::eventFilter(watched, event);
    }


  protected:
    bool m_bHover;
    bool m_bPressed;

    int m_currentIndex = -1;
    int m_maxVisibleItems = -1;

    QString m_currentText;
    QList<FluComboItem*> m_items;
    FluComboBoxMenu* m_dropMenu;
};
