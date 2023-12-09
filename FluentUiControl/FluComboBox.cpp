#include "FluComboBox.h"


FluComboBox::FluComboBox(QWidget* parent /*= nullptr*/) : QPushButton(parent)
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

    m_arrowAni = new FluTranslateYAnimation(this);
    FluFontUtils::setFont(this);
    QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluComboBox.qss");
    setStyleSheet(qss);
}

void FluComboBox::initDropMenu()
{
    FluComboBoxMenu* comboBoxMenu = new FluComboBoxMenu(this);
    comboBoxMenu->setMaxVisibleItems(m_maxVisibleItems);
    connect(comboBoxMenu, &FluComboBoxMenu::closedSignal, this, &FluComboBox::_onDropMenuClosed);
    m_dropMenu = comboBoxMenu;
}

void FluComboBox::addItem(QString text, QPixmap icon /*= QPixmap()*/, QVariant userData /*= QVariant::fromValue(nullptr)*/)
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
        _onItemClicked(nIndex);
    });

    m_dropMenu->addAction(action);

    // 调整宽度
    int nMaxWidth = qMax(width(), m_dropMenu->getView()->width());
    setMinimumWidth(nMaxWidth);
}

void FluComboBox::addItems(QList<QString> texts)
{
    for (auto itList = texts.begin(); itList != texts.end(); itList++)
    {
        addItem((*itList));
    }
}

void FluComboBox::removeItem(int nIndex)
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

int FluComboBox::getCurrentIndex()
{
    return m_currentIndex;
}

void FluComboBox::setCurrentIndex(int nIndex)
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

QString FluComboBox::getCurrentText()
{
    bool bCorrect = m_currentIndex >= 0 && m_currentIndex < m_items.count();
    if (!bCorrect)
        return "";

    auto itf = m_items.begin() + m_currentIndex;
    return (*itf)->getText();
}

void FluComboBox::setCurrentText(QString text)
{
    if (text == getCurrentText())
        return;

    int nIndex = findText(text);
    if (nIndex >= 0)
    {
        setCurrentIndex(nIndex);
    }
}

QString FluComboBox::getItemText(int nIndex)
{
    bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
    if (!bCorrect)
        return "";

    auto itf = m_items.begin() + nIndex;
    return (*itf)->getText();
}

void FluComboBox::setItemText(int nIndex, QString text)
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

QVariant FluComboBox::getItemData(int nIndex)
{
    bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
    if (!bCorrect)
        return QVariant::fromValue(nullptr);

    auto itf = m_items.begin() + nIndex;
    return (*itf)->getUserData();
}

FluComboItem* FluComboBox::getComboItem(int nIndex)
{
    bool bCorrect = nIndex >= 0 && nIndex < m_items.count();
    if (!bCorrect)
        return nullptr;

    auto itf = m_items.begin() + nIndex;
    return (*itf);
}

QPixmap FluComboBox::getItemIcon(int nIndex)
{
    FluComboItem* item = getComboItem(nIndex);
    if (item == nullptr)
        return QPixmap();

    return item->getIcon();
}

void FluComboBox::setItemIcon(int nIndex, QPixmap pixmap)
{
    FluComboItem* item = getComboItem(nIndex);
    if (item == nullptr)
        return;

    item->setIcon(pixmap);
}

int FluComboBox::findText(QString text)
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

void FluComboBox::clear()
{
    m_items.clear();
    m_currentIndex = -1;
}

int FluComboBox::count()
{
    return m_items.count();
}

void FluComboBox::insertItem(int nIndex, QString text, QPixmap icon, QVariant userData)
{
    FluComboItem* item = new FluComboItem(text, icon, userData);
    m_items.insert(nIndex, item);
    if (nIndex <= m_currentIndex)
        _onItemClicked(m_currentIndex + 1);
}

void FluComboBox::insertItems(int nIndex, QList<QString> texts)
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

int FluComboBox::getMaxVisibleItems()
{
    return m_maxVisibleItems;
}

void FluComboBox::setMaxVisibleItems(int nNum)
{
    m_maxVisibleItems = nNum;
}

void FluComboBox::_closeComboMenu()
{
    m_comboBoxState = FluComboBoxState::FluCBS_CLOSE;
    m_dropMenu->hide();
    // if (!m_dropMenu)
    //    return;
    // m_dropMenu->close();
    // m_dropMenu = nullptr;
}

void FluComboBox::_onDropMenuClosed()
{
    QPoint pos = mapFromGlobal(QCursor::pos());
    if (!rect().contains(pos))
    {
        // m_dropMenu = nullptr;
        m_comboBoxState = FluComboBoxState::FluCBS_CLOSE;
        m_dropMenu->hide();
    }
}

void FluComboBox::_showComboMenu()
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

void FluComboBox::_toggleComboMenu()
{
    if (FluComboBoxState::FluCBS_SHOW == m_comboBoxState)
    {
        _closeComboMenu();
    }
    else
    {
        _showComboMenu();
    }
}

void FluComboBox::_onItemClicked(int nIndex)
{
    if (nIndex == m_currentIndex)
        return;

    setCurrentIndex(nIndex);
}

void FluComboBox::setPlaceholderText(QString text)
{
    QPushButton::setText(text);
}

bool FluComboBox::eventFilter(QObject* watched, QEvent* event)
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

void FluComboBox::mouseReleaseEvent(QMouseEvent* e)
{
    QPushButton::mouseReleaseEvent(e);
    _toggleComboMenu();
}

void FluComboBox::paintEvent(QPaintEvent* e)
{
    QPushButton::paintEvent(e);
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing);
    if (m_bHover)
        painter.setOpacity(0.8);
    else if (m_bPressed)
        painter.setOpacity(0.7);

    QRect rect = QRect(width() - 22, height() / 2 - 5 + m_arrowAni->getY(), 10, 10);
    if (FluThemeUtils::getInstance()->getThemeMode() == FluThemeMode::Dark)
    {
        painter.drawPixmap(rect, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::ChevronDown));
    }
    else
    {
        painter.drawPixmap(rect, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::ChevronDown));
    }
}
