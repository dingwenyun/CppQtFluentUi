#pragma once

#include "FluLineEdit.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include "FluLineEditButton.h"

class FluPasswordLineEdit : public FluLineEdit
{
    Q_OBJECT
    Q_PROPERTY(bool passwordVisible READ isPassWordVisible WRITE setPassWordVisible)
  public:
    FluPasswordLineEdit(QWidget* parent = nullptr) : FluLineEdit(parent)
    {
        m_viewButton = new FluLineEditButton(FluIconUtils::GetFluentIconPixmap(FluAwesomeType::View), this);
        setEchoMode(QLineEdit::Password);
        setContextMenuPolicy(Qt::NoContextMenu);
        m_hBoxLayout->addWidget(m_viewButton, 0, Qt::AlignRight);
        setClearButtonEnabled(false);

        m_viewButton->installEventFilter(this);
        m_viewButton->setIconSize(QSize(13, 13));
        m_viewButton->setFixedSize(29, 25);
    }

    void setPassWordVisible(bool bVisible)
    {
        if (bVisible)
            setEchoMode(QLineEdit::Normal);
        else
            setEchoMode(QLineEdit::Password);
    }

    bool isPassWordVisible()
    {
        return echoMode() == QLineEdit::Normal;
    }

    void setClearButtonEnabled(bool bEnable)
    {
        m_bClearButtonEnable = bEnable;
        if (m_viewButton->isHidden())
        {
            if (bEnable)
                setTextMargins(0, 0, 28, 0);
            else
                setTextMargins(0, 0, 0, 0);
        }
        else
        {
            if (bEnable)
                setTextMargins(0, 0, 58, 0);
            else
                setTextMargins(0, 0, 30, 0);
        }
    }

    void setViewPasswordButtonVisible(bool bVisible)
    {
        m_viewButton->setVisible(bVisible);
    }

  protected:
    bool eventFilter(QObject* obj, QEvent* event)
    {
        if (obj != m_viewButton)
            return FluLineEdit::eventFilter(obj, event);

        if (event->type() == QEvent::MouseButtonPress)
        {
            setPassWordVisible(true);
        }
        else if (event->type() == QEvent::MouseButtonRelease)
        {
            setPassWordVisible(false);
        }

        return FluLineEdit::eventFilter(obj, event);
    }

  private:
    FluLineEditButton* m_viewButton;
};