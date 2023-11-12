#pragma once

#include <QString>
#include <QPixmap>
#include <QVariant>

class FluComboItem
{
  public:
    FluComboItem(QString text, QPixmap icon = QPixmap(), QVariant userData = QVariant::fromValue(nullptr))
    {
        m_text = text;
        m_icon = icon;
        m_userData = userData;
    }

    QString getText()
    {
        return m_text;
    }

    void setText(QString text)
    {
        m_text = text;
    }

    QPixmap getIcon()
    {
        return m_icon;
    }

    void setIcon(QPixmap icon)
    {
        m_icon = icon;
    }

    QVariant getUserData()
    {
        return m_userData;
    }

    void setUserData(QVariant userData)
    {
        m_userData = userData;
    }

  private:
    QString m_text;
    QPixmap m_icon;
    QVariant m_userData;
};
