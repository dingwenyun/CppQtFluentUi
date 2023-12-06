#pragma once

#include <QLayout>
#include <QWidget>

class FluExpandLayout : public QLayout
{
  public:
    FluExpandLayout(QWidget* parent = nullptr) : QLayout(parent)
    {
    }

    bool hasWidget(QWidget* w)
    {
        bool bHas = false;
        for (auto tmpW : m_widgets)
        {
            if (tmpW == w)
            {
                bHas = true;
                break;
                ;
            }
        }

        return bHas;
    }

    void addWidget(QWidget* w)
    {
        if (w == nullptr)
            return;

        if (hasWidget(w))
            return;

        w->installEventFilter(this);
    }

  private:
    QList<QWidget*> m_widgets;
};
