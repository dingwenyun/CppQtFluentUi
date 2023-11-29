#pragma once

#include <QToolButton>
#include <QPixmap>
#include <QPainter>
#include <QLineEdit>
#include <QCompleter>
#include <QHBoxLayout>
#include <QPainter>
#include <QPainterPath>
#include "FluLineEditButton.h"
#include "FluCompleterMenu.h"
#include "../FluentUiUtils/FluFontUtils.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include "../FluentUiUtils/FluLogUtils.h"
#include <QTimer>
#include <QCompleter>

class FluLineEdit : public QLineEdit
{
    Q_OBJECT
  public:
    FluLineEdit(QWidget* parent = nullptr) : QLineEdit(parent)
    {
        m_bClearButtonEnable = false;
        m_completer = nullptr;
        m_completerMenu = nullptr;

        setProperty("transparent", true);
        setFixedHeight(33);
        setAttribute(Qt::WA_MacShowFocusRect, false);

        FluFontUtils::setFont(this);

        m_hBoxLayout = new QHBoxLayout(this);
        m_clearButton = new FluLineEditButton(FluIconUtils::GetFluentIconPixmap(FluAwesomeType::ChromeClose), this);
        m_clearButton->setObjectName("lineEditButton");

        m_clearButton->setFixedSize(29, 25);
        m_clearButton->hide();

        m_hBoxLayout->setSpacing(3);
        m_hBoxLayout->setContentsMargins(4, 4, 4, 4);
        m_hBoxLayout->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        m_hBoxLayout->addWidget(m_clearButton, 0, Qt::AlignRight);

        QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluLineEdit.qss");
        setStyleSheet(qss);

        connect(m_clearButton, &FluLineEditButton::clicked, [=](bool bChecked) { clear(); });

        // connect(m_clearButton, &FluLineEditButton::clicked, this, &FluLineEdit::_onClicked);
        connect(this, &FluLineEdit::textChanged, this, &FluLineEdit::_onTextChanged);
        connect(this, &FluLineEdit::textEdited, this, &FluLineEdit::_onTextEdited);
    }

    ~FluLineEdit() noexcept
    {
    }

    void setClearButtonEnabled(bool bEnable)
    {
        m_bClearButtonEnable = bEnable;
        if (bEnable)
        {
            setTextMargins(0, 0, 28, 0);
        }
        else
        {
            setTextMargins(0, 0, 0, 0);
        }
    }

    bool getClearButtonEnabled()
    {
        return m_bClearButtonEnable;
    }

    void setCompleter(QCompleter* completer)
    {
        m_completer = completer;
    }

    QCompleter* getCompleter()
    {
        return m_completer;
    }

  public slots:
    void _onTextChanged(QString text)
    {
        if (getClearButtonEnabled())
        {
            bool bVisible = !text.isEmpty() && hasFocus();
            m_clearButton->setVisible(bVisible);
        }
    }

    void _onTextEdited(QString text)
    {
        if (m_completer == nullptr)
            return;

        if (!this->text().isEmpty())
        {
            QTimer::singleShot(50, this, SLOT(_showCompleterMenu()));
        }
        else if (m_completerMenu != nullptr)
        {
            m_completerMenu->close();
        }
    }

    void _showCompleterMenu()
    {
        if (m_completer == nullptr || text().isEmpty())
        {
            return;
        }

        if (!m_completerMenu)
        {
            m_completerMenu = new FluCompleterMenu(this);
            connect(m_completerMenu, &FluCompleterMenu::activated, m_completer, QOverload<const QString&>::of(&QCompleter::activated));
            //            m_completerMenu->setMaxVisibleItems(m_completer->maxVisibleItems());
        }

        m_completer->setCompletionPrefix(text());
        bool bChanged = m_completerMenu->setCompletion(m_completer->completionModel());
        m_completerMenu->setMaxVisibleItems(m_completer->maxVisibleItems());

        if (bChanged)
            m_completerMenu->popup();
    }

    // void _onClicked(bool b)
    // {
    //     LogDebug << "called";
    // }
  protected:
    void focusOutEvent(QFocusEvent* e)
    {
        QLineEdit::focusOutEvent(e);
        m_clearButton->hide();
    }

    void focusInEvent(QFocusEvent* e)
    {
        QLineEdit::focusInEvent(e);
        if (getClearButtonEnabled())
        {
            if (!text().isEmpty())
            {
                m_clearButton->setVisible(true);
            }
            else
            {
                m_clearButton->setVisible(false);
            }
        }
    }

    void paintEvent(QPaintEvent* event)
    {
        QLineEdit::paintEvent(event);

        if (!hasFocus())
            return;

        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing);
        painter.setPen(Qt::NoPen);

        QMargins margins = contentsMargins();
        QPainterPath path = QPainterPath();
        int nW = width() - margins.left() - margins.right();
        int nH = height();

        path.addRoundedRect(QRect(margins.left(), nH - 10, nW, 10), 5, 5);

        QPainterPath rectPath = QPainterPath();
        rectPath.addRect(margins.left(), nH - 10, nW, 8);
        path = path.subtracted(rectPath);

        painter.fillPath(path, QBrush(Qt::red));
    }

  private:
    bool m_bClearButtonEnable;
    QCompleter* m_completer;
    FluCompleterMenu* m_completerMenu;

    QHBoxLayout* m_hBoxLayout;
    FluLineEditButton* m_clearButton;
};