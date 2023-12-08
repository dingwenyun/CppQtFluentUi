#pragma once

#include "FluFrame.h"
#include "FluListWidget.h"

class FluListFrame : public FluFrame
{
  public:
    FluListFrame(QWidget* parent = nullptr) : FluFrame(parent)
    {
        m_listWidget = new FluListWidget(this);
        m_hBoxLayout->addWidget(m_listWidget);

        QList<QString> stands = {"白金之星", 
            "法皇之绿", "天堂制造", "绯红之王", "银色战车",
            "疯狂砖石", "金属制品", "败者食尘", "黑蚊子多", 
            "杀手皇后", "壮烈成人", "石之自由", "砸瓦鲁多", 
            "钢炼手指", "臭氧宝宝", "华丽挚爱", "隐者之紫",
            "黄金体验", "虚无之王", "纸月之王", "骇人恶兽"
        };

        for (auto stand : stands)
        {
            auto item = new QListWidgetItem(stand);
            m_listWidget->addItem(item);
        }

        setFixedSize(300, 380);
    }

  protected:
    FluListWidget* m_listWidget;
};
