#pragma once
#include "FluLabel.h"
#include <QWidget>
#include "FluLineEdit.h"
#include "FluSmoothScrollArea.h"
#include "FluIconInfoPanel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "FluFlowLayout.h"
#include "FluIconCard.h"
#include "FluSearchLineEdit.h"

class FluIconCardView : public QWidget
{
    Q_OBJECT
  public:
    FluIconCardView(QWidget* parent = nullptr) : QWidget(parent)
    {
        m_iconLibraryLabel = new FluStrongBodyLabel("Flu Icons Library", this);
        m_searchLineEdit = new FluSearchLineEdit(this);
        m_searchLineEdit->setFixedWidth(200);

        m_view = new QFrame(this);
        m_scrollArea = new FluSmoothScrollArea(m_view);
        m_scrollWidget = new QWidget(m_scrollArea);

        m_infoPanel = new FluIconInfoPanel(FluAwesomeType::More, this);

        m_vBoxLayout = new QVBoxLayout(this);
        m_hBoxLayout = new QHBoxLayout(m_view);
        m_flowLayout = new FluFlowLayout(m_scrollWidget);

        m_currentIndex = -1;
        __initWidget();
    }

    void __initWidget()
    {
        m_scrollArea->setWidget(m_scrollWidget);
        m_scrollArea->viewport()->setContentsMargins(0, 5, 0, 5);
        m_scrollArea->setWidgetResizable(true);
        m_scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        m_vBoxLayout->setContentsMargins(0, 0, 0, 0);
        m_vBoxLayout->setSpacing(12);
        m_vBoxLayout->addWidget(m_iconLibraryLabel);
        m_vBoxLayout->addWidget(m_searchLineEdit);
        m_vBoxLayout->addWidget(m_view);

        m_hBoxLayout->setSpacing(0);
        m_hBoxLayout->setContentsMargins(0, 0, 0, 0);
        m_hBoxLayout->addWidget(m_scrollArea);
        m_hBoxLayout->addWidget(m_infoPanel, 0, Qt::AlignRight);

        m_flowLayout->setContentsMargins(8, 3, 8, 8);

        __setQss();

        connect(m_searchLineEdit, &FluSearchLineEdit::clearSignal, this, &FluIconCardView::showAllIcons);
        connect(m_searchLineEdit, &FluSearchLineEdit::searchSigal, this, &FluIconCardView::search);

        __setAllIcons();
    }

    void __setQss()
    {
        m_view->setObjectName("iconView");
        m_scrollWidget->setObjectName("scrollWidget");

        // styleSheet
        if (m_currentIndex >= 0)
        {
            m_listCards.at(m_currentIndex)->setSelected(true, true);
        }

        QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluIconInterface.qss");
        // FluStyleSheetUitls::replaceVar("{\"ThemeColorNormal\":\"blue\"}", qss);
        m_scrollWidget->setStyleSheet(qss);
        setStyleSheet(qss);
    }

    void __setAllIcons()
    {
        QMetaEnum metaEnum = QMetaEnum::fromType<FluAwesomeType>();
        for (int i = 0; i < metaEnum.keyCount(); i++)
        {
#ifdef _DEBUG  // debug加载图标设置为256个，太多影响体验
            if (i >= 256)
                return;
#endif
            addIcon((FluAwesomeType)metaEnum.value(i));
        }
        setSelectedIcon(m_listIcons.at(0));
    }

    void addIcon(FluAwesomeType awesomeType)
    {
        FluIconCard* card = new FluIconCard(awesomeType);
        connect(card, &FluIconCard::clicked, this, &FluIconCardView::setSelectedIcon);

        m_listCards.append(card);
        m_listIcons.append(awesomeType);
        m_flowLayout->addWidget(card);
    }

    void search(QString keyWord)
    {
    }

    void showAllIcons()
    {
        m_flowLayout->removeAllWidgets();
    }
  public slots:
    void setSelectedIcon(FluAwesomeType awesomeType)
    {
        int nIndex = m_listIcons.indexOf(awesomeType);
        if (m_currentIndex >= 0)
        {
            m_listCards.at(m_currentIndex)->setSelected(false);
        }

        m_currentIndex = nIndex;  // 找到index
        m_listCards.at(nIndex)->setSelected(true);
        m_infoPanel->setIcon(awesomeType);
    }

  private:
    FluStrongBodyLabel* m_iconLibraryLabel;
    FluSearchLineEdit* m_searchLineEdit;

    QFrame* m_view;  // 用于显示图像

    FluSmoothScrollArea* m_scrollArea;
    QWidget* m_scrollWidget;

    FluIconInfoPanel* m_infoPanel;

    QVBoxLayout* m_vBoxLayout;
    QHBoxLayout* m_hBoxLayout;
    FluFlowLayout* m_flowLayout;

    QList<FluIconCard*> m_listCards;
    QList<FluAwesomeType> m_listIcons;

    int m_currentIndex;
};
