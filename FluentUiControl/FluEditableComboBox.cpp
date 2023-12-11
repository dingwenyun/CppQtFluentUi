#include "FluEditableComboBox.h"
#include "../FluentUiUtils/FluIconUtils.h"

FluEditableComboBox::FluEditableComboBox(QWidget* parent /*= nullptr*/) : FluLineEdit(parent)
{
    m_bHover = false;
    m_bPressed = false;
    m_currentIndex = -1;
    m_maxVisibleItems = -1;
    m_dropMenu = nullptr;
    m_comboBoxState = FluComboBoxState::FluCBS_CLOSE;

    // stylesheet
    installEventFilter(this);
    initDropMenu();

    m_dropButton = new FluLineEditButton(FluIconUtils::GetFluentIconPixmap(FluAwesomeType::ChevronDown), this);
    setTextMargins(0, 0, 29, 0);
    m_dropButton->setFixedSize(30, 25);
    m_hBoxLayout->addWidget(m_dropButton, 0, Qt::AlignRight);

    connect(m_dropButton, &FluLineEditButton::clicked, this, &FluEditableComboBox::toggleComboMenu);

    // m_arrowAni = new FluTranslateYAnimation(this);
    // FluFontUtils::setFont(this);
    // QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluEditableComboBox.qss");
    // setStyleSheet(qss);
}

void FluEditableComboBox::initDropMenu()
{
    FluComboBoxMenu* comboBoxMenu = new FluComboBoxMenu(this);
    comboBoxMenu->setMaxVisibleItems(m_maxVisibleItems);
    connect(comboBoxMenu, &FluComboBoxMenu::closedSignal, this, &FluEditableComboBox::onDropMenuClosed);
    m_dropMenu = comboBoxMenu;
}

void FluEditableComboBox::addItem(QString text, QPixmap icon /*= QPixmap()*/, QVariant userData /*= QVariant::fromValue(nullptr)*/)
{
    FluComboItem* item = new FluComboItem(text, icon, userData);
    m_items.append(item);
    if (m_items.count() == 1)
        setCurrentIndex(0);

    // 添加一个action
    QAction* action = new QAction(item->getIcon(), item->getText(), this);
    int nIndex = m_items.count() - 1;
    connect(action, &QAction::triggered, [=] {
        // int nIndex = m_items.count() - 1;
        onItemClicked(nIndex);
    });

    m_dropMenu->addAction(action);

    // 调整宽度
    int nMaxWidth = qMax(width(), m_dropMenu->getView()->width());
    setMinimumWidth(nMaxWidth);
}

void FluEditableComboBox::addItems(QList<QString> texts)
{
    for (auto itList = texts.begin(); itList != texts.end(); itList++)
    {
        addItem((*itList));
    }
}

void FluEditableComboBox::removeItem(int nIndex)
{
    bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
    if (!bCorrect)
        return;

    auto itf = m_items.begin() + nIndex;
    m_items.erase(itf);

    if (nIndex < m_currentIndex)
    {
        onItemClicked(m_currentIndex - 1);
    }
    else if (nIndex == m_currentIndex)
    {
        if (nIndex > 0)
            onItemClicked(m_currentIndex - 1);
        else
        {
            setCurrentIndex(0);
            emit currentIndexChanged(0);
            emit currentTextChanged(getCurrentText());
        }
    }
}

int FluEditableComboBox::getCurrentIndex()
{
    return m_currentIndex;
}

void FluEditableComboBox::setCurrentIndex(int nIndex)
{
    bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
    if (!bCorrect)
    {
        return;
    }

    m_currentIndex = nIndex;
    setText(getCurrentText());
    // adjustSize();
}

QString FluEditableComboBox::getCurrentText()
{
    bool bCorrect = m_currentIndex >= 0 && m_currentIndex < m_items.count();
    if (!bCorrect)
        return "";

    auto itf = m_items.begin() + m_currentIndex;
    return (*itf)->getText();
}

void FluEditableComboBox::setCurrentText(QString text)
{
    if (text == getCurrentText())
        return;

    int nIndex = findText(text);
    if (nIndex >= 0)
    {
        setCurrentIndex(nIndex);
    }
}

QString FluEditableComboBox::getItemText(int nIndex)
{
    bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
    if (!bCorrect)
        return "";

    auto itf = m_items.begin() + nIndex;
    return (*itf)->getText();
}

void FluEditableComboBox::setItemText(int nIndex, QString text)
{
    bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
    if (!bCorrect)
        return;

    auto itf = m_items.begin() + nIndex;
    (*itf)->setText(text);

    if (getCurrentIndex() == nIndex)
    {
        setText(text);
        // adjustSize();
    }
}

QVariant FluEditableComboBox::getItemData(int nIndex)
{
    bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
    if (!bCorrect)
        return QVariant::fromValue(nullptr);

    auto itf = m_items.begin() + nIndex;
    return (*itf)->getUserData();
}

FluComboItem* FluEditableComboBox::getComboItem(int nIndex)
{
    bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
    if (!bCorrect)
        return nullptr;

    auto itf = m_items.begin() + nIndex;
    return (*itf);
}

QPixmap FluEditableComboBox::getItemIcon(int nIndex)
{
    FluComboItem* item = getComboItem(nIndex);
    if (item == nullptr)
        return QPixmap();

    return item->getIcon();
}

void FluEditableComboBox::setItemIcon(int nIndex, QPixmap pixmap)
{
    FluComboItem* item = getComboItem(nIndex);
    if (item == nullptr)
        return;

    item->setIcon(pixmap);
}

int FluEditableComboBox::findText(QString text)
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

void FluEditableComboBox::clear()
{
    m_items.clear();
    m_currentIndex = -1;
}

int FluEditableComboBox::count()
{
    return m_items.count();
}

void FluEditableComboBox::insertItem(int nIndex, QString text, QPixmap icon, QVariant userData)
{
    FluComboItem* item = new FluComboItem(text, icon, userData);
    m_items.insert(nIndex, item);
    if (nIndex <= m_currentIndex)
        onItemClicked(m_currentIndex + 1);
}

void FluEditableComboBox::insertItems(int nIndex, QList<QString> texts)
{
    int nPos = nIndex;
    for (auto itList = texts.begin(); itList != texts.end(); itList++)
    {
        FluComboItem* item = new FluComboItem(*itList);
        m_items.insert(nPos, item);
        nPos++;
    }

    if (nIndex <= m_currentIndex)
        onItemClicked(m_currentIndex + nPos - nIndex);
}

int FluEditableComboBox::getMaxVisibleItems()
{
    return m_maxVisibleItems;
}

void FluEditableComboBox::setMaxVisibleItems(int nNum)
{
    m_maxVisibleItems = nNum;
}

void FluEditableComboBox::closeComboMenu()
{
    m_comboBoxState = FluComboBoxState::FluCBS_CLOSE;
    m_dropMenu->hide();
    // if (!m_dropMenu)
    //    return;
    // m_dropMenu->close();
    // m_dropMenu = nullptr;
}

void FluEditableComboBox::onDropMenuClosed()
{
    QPoint pos = mapFromGlobal(QCursor::pos());
    if (!rect().contains(pos))
    {
        // m_dropMenu = nullptr;
        m_comboBoxState = FluComboBoxState::FluCBS_CLOSE;
        m_dropMenu->hide();
    }
}

void FluEditableComboBox::showComboMenu()
{
    if (m_items.isEmpty())
        return;

    if (m_currentIndex >= 0 && !m_items.isEmpty())
    {
        m_dropMenu->setDefaultAction(m_currentIndex);
    }

    QPoint pd = mapToGlobal(QPoint(0, height()));
    int hd = m_dropMenu->getView()->heightForAnimation(pd, FluMenuAnimationType::DROP_DOWN);
    m_dropMenu->getView()->adjustSize(pd, FluMenuAnimationType::DROP_DOWN);
    m_dropMenu->exec(pd, true, FluMenuAnimationType::DROP_DOWN);
}

void FluEditableComboBox::toggleComboMenu()
{
    if (FluComboBoxState::FluCBS_SHOW == m_comboBoxState)
    {
        closeComboMenu();
    }
    else
    {
        showComboMenu();
    }
}

void FluEditableComboBox::onItemClicked(int nIndex)
{
    if (nIndex == m_currentIndex)
        return;

    setCurrentIndex(nIndex);
}

void FluEditableComboBox::setPlaceholderText(QString text)
{
    FluLineEdit::setPlaceholderText(text);
}

// void FluEditableComboBox::onReturnKeyPressed()
//{
//}
//
// void FluEditableComboBox::onTextEdited(QString str)
//{
//    m_currentIndex = -1;
//    emit currentTextChanged(str);
//}
//
// void FluEditableComboBox::onClearButtonClicked()
//{
//    FluLineEdit::clear();
//    m_currentIndex = -1;
//}

bool FluEditableComboBox::eventFilter(QObject* watched, QEvent* event)
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

// void FluEditableComboBox::mouseReleaseEvent(QMouseEvent* e)
//{
//    FluLineEdit::mouseReleaseEvent(e);
//    toggleComboMenu();
//}

// void FluEditableComboBox::paintEvent(QPaintEvent* e)
//{
//    FluLineEdit::paintEvent(e);
//    QPainter painter(this);
//    painter.setRenderHints(QPainter::Antialiasing);
//    if (m_bHover)
//        painter.setOpacity(0.8);
//    else if (m_bPressed)
//        painter.setOpacity(0.7);
//
//    QRect rect = QRect(width() - 22, height() / 2 - 5 + m_arrowAni->getY(), 10, 10);
//    if (FluThemeUtils::getInstance()->getThemeMode() == FluThemeMode::Dark)
//    {
//        painter.drawPixmap(rect, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::ChevronDown));
//    }
//    else
//    {
//        painter.drawPixmap(rect, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::ChevronDown));
//    }
//}
