#pragma once

#include "FluLineEdit.h"
#include <QPushButton>
#include <QObject>
#include <QList>

#include "FluComboBox.h"
#include "FluComboItem.h"
#include "FluComboBoxMenu.h"
#include <QPixmap>
#include <QVariant>
#include "FluTranslateYAnimation.h"
#include "../FluentUiUtils/FluFontUtils.h"
#include "../FluentUiUtils/FluThemeUtils.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"

class FluEditableComboBox : public FluLineEdit
{
    Q_OBJECT
  public:
    FluEditableComboBox(QWidget* parent = nullptr);

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

    // void onReturnKeyPressed();
    // void onTextEdited(QString str);
    // void onClearButtonClicked();
  signals:
    void currentIndexChanged(int nIndex);
    void currentTextChanged(QString text);

  protected:
    bool eventFilter(QObject* watched, QEvent* event);

    // void mouseReleaseEvent(QMouseEvent* e);

    // void paintEvent(QPaintEvent* e);

  private:
    bool m_bHover;
    bool m_bPressed;
    int m_currentIndex = -1;
    int m_maxVisibleItems = -1;

    FluLineEditButton* m_dropButton;  // 下拉按钮

    FluComboBoxState m_comboBoxState;
    QString m_currentText;
    QList<FluComboItem*> m_items;
    FluComboBoxMenu* m_dropMenu;
    FluTranslateYAnimation* m_arrowAni;
};
