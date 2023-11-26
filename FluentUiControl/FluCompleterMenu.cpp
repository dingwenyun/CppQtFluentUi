#include "FluCompleterMenu.h"
#include "FluLineEdit.h"

FluCompleterMenu::FluCompleterMenu(FluLineEdit* lineEdit) : FluRoundMenu("")
{
    m_lineEdit = lineEdit;
    getView()->viewport()->setContentsMargins(QMargins(0, 2, 0, 6));
    getView()->setObjectName("completerListWidget");

    m_delegate = new FluIndicatorMenuItemDelegate();
    getView()->setItemDelegate(m_delegate);
    //   getView()->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    installEventFilter(this);
    setItemHeight(33);
}

bool FluCompleterMenu::setCompletion(QAbstractItemModel* model)
{
    QList<QString> items;
    for (int i = 0; i < model->rowCount(); i++)
    {
        for (int j = 0; j < model->columnCount(); j++)
        {
            QString text = model->data(model->index(i, j)).toString();
            items.append(text);
        }
    }

    bool bSame = true;
    if (items.count() != m_items.count())
    {
        bSame = false;
    }
    else
    {
        for (auto text : items)
        {
            if (!m_items.contains(text))
            {
                bSame = false;
                break;
            }
        }
    }

    if (isVisible() && bSame)
    {
        return false;
    }

    clear();
    m_items = items;
    for (auto text : m_items)
    {
        QAction* action = new QAction(text);
        connect(action, &QAction::triggered, [=](bool trigger) { _onItemSelected(text); });
        addAction(action);
    }

    return true;
}

void FluCompleterMenu::popup()
{
    if (m_items.isEmpty())
        return;

    if (getView()->width() < m_lineEdit->width())
    {
        getView()->setMinimumWidth(m_lineEdit->width());
    }

    QPoint downPos = m_lineEdit->mapToGlobal(QPoint(0, m_lineEdit->height()));
    int nH = getView()->heightForAnimation(downPos, FluMenuAnimationType::FADE_IN_DROP_DOWN);
    getView()->adjustSize(downPos, FluMenuAnimationType::FADE_IN_DROP_DOWN);

    getView()->setStyle(QApplication::style());
    getView()->update();

    adjustSize();
    exec(downPos, true, FluMenuAnimationType::FADE_IN_DROP_DOWN);

    getView()->setFocusPolicy(Qt::NoFocus);
    setFocusPolicy(Qt::NoFocus);
    m_lineEdit->setFocus();
}

void FluCompleterMenu::_onItemSelected(const QString text)
{
    m_lineEdit->setText(text);
    emit activated(text);
}

bool FluCompleterMenu::eventFilter(QObject* watched, QEvent* event)
{
    if (event->type() != QEvent::KeyPress)
        return FluRoundMenu::eventFilter(watched, event);

    m_lineEdit->event(event);
    // getView()->event(event);
    // getView()->eventFilter(getView(), event);
    getView()->hockEvent(event);

    QKeyEvent* keyEvent = (QKeyEvent*)event;
    if (keyEvent->key() == Qt::Key_Escape)
        close();

    if (keyEvent->key() == Qt::Key_Enter || keyEvent->key() == Qt::Key_Return)
    {
        if (getView()->currentRow() >= 0)
        {
            _onItemSelected(getView()->currentItem()->text());
            close();
        }
    }

    return FluRoundMenu::eventFilter(watched, event);
}
