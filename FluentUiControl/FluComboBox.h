#pragma once

#include <QPushButton>
#include <QObject>
#include <QList>

#include "FluComboItem.h"
#include "FluComboBoxMenu.h"
#include <QPixmap>
#include <QVariant>
#include "FluTranslateYAnimation.h"
#include "../FluentUiUtils/FluFontUtils.h"
#include "../FluentUiUtils/FluThemeUtils.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"

enum class FluComboBoxState
{
    FluCBS_SHOW,  // 展示状态
    FluCBS_CLOSE  // 关闭状态
};

class FluComboBox : public QPushButton
{
    Q_OBJECT
  public:
    FluComboBox(QWidget* parent = nullptr);

    void initDropMenu();

    void addItem(QString text, QPixmap icon = QPixmap(), QVariant userData = QVariant::fromValue(nullptr));

    void addItems(QList<QString> texts);

    void removeItem(int nIndex);

    int getCurrentIndex();

    void setCurrentIndex(int nIndex);

    QString getCurrentText();

    void setCurrentText(QString text);

    QString getItemText(int nIndex);

    void setItemText(int nIndex, QString text);

    QVariant getItemData(int nIndex);

    FluComboItem* getComboItem(int nIndex);

    QPixmap getItemIcon(int nIndex);

    void setItemIcon(int nIndex, QPixmap pixmap);

    int findText(QString text);

    void clear();

    int count();

    void insertItem(int nIndex, QString text, QPixmap icon, QVariant userData);

    void insertItems(int nIndex, QList<QString> texts);

    int getMaxVisibleItems();

    void setMaxVisibleItems(int nNum);

    void closeComboMenu();

    void onDropMenuClosed();

    void showComboMenu();

    void toggleComboMenu();

    void onItemClicked(int nIndex);
    void setPlaceholderText(QString text);
  signals:
    void currentIndexChanged(int nIndex);
    void currentTextChanged(QString text);

  protected:
    bool eventFilter(QObject* watched, QEvent* event);

    void mouseReleaseEvent(QMouseEvent* e);

    void paintEvent(QPaintEvent* e);

  private:
    bool m_bHover;
    bool m_bPressed;
    int m_currentIndex = -1;
    int m_maxVisibleItems = -1;
    FluComboBoxState m_comboBoxState;
    QString m_currentText;
    QList<FluComboItem*> m_items;
    FluComboBoxMenu* m_dropMenu;
    FluTranslateYAnimation* m_arrowAni;
};
