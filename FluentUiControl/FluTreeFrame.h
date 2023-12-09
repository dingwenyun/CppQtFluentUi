#pragma once

#include "FluFrame.h"
#include "FluTreeWidget.h"
#include <QTreeWidgetItemIterator>

class FluTreeFrame : public FluFrame
{
  public:
    FluTreeFrame(QWidget* parent = nullptr, bool bEnableCheck = false) : FluFrame(parent)
    {
        m_treeWidget = new FluTreeWidget(this);
        m_hBoxLayout->addWidget(m_treeWidget);

        auto item1 = new QTreeWidgetItem({"Jojo 1 - 幻影之血"});
        auto item11 = new QTreeWidgetItem({"乔纳森 乔斯达"});
        auto item12 = new QTreeWidgetItem({"迪奥 布兰度"});
        auto item13 = new QTreeWidgetItem({"威廉A 齐贝林"});
        item1->addChildren({item11, item12, item13});

        auto item2 = new QTreeWidgetItem({"Jojo 3 - 星尘斗士"});
        auto item21 = new QTreeWidgetItem({"Jotaro kujo"});
        auto item211 = new QTreeWidgetItem({"空条承太郎"});
        auto item212 = new QTreeWidgetItem({"空条蕉太狼"});
        auto item213 = new QTreeWidgetItem({"阿强"});
        auto item214 = new QTreeWidgetItem({"卖鱼强"});
        auto item215 = new QTreeWidgetItem({"那个无敌的男人"});

        item2->addChild(item21);
        item21->addChildren({item211, item212, item213, item214, item215});
        
        m_treeWidget->addTopLevelItem(item1);
        m_treeWidget->addTopLevelItem(item2);

        m_treeWidget->expandAll();
        m_treeWidget->setHeaderHidden(true);

        setFixedSize(300, 380);

        //if (bEnableCheck)
        //{
         //   auto iter = QTreeWidgetItemIterator(m_treeWidget);
          //  while )
          //  {
          //  }
        //}
    }


  private:
    FluTreeWidget* m_treeWidget;
};
