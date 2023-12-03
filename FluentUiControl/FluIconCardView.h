#pragma once
#include "FluLabel.h"
#include <QWidget>
#include "FluLineEdit.h"
#include "FluSmoothScrollArea.h"
#include "FluIconInfoPanel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "FluFlowLayout.h"

class FluIconCardView : public QWidget
{
    Q_OBJECT
  public:
    FluIconCardView(QWidget* parent = nullptr) : QWidget(parent)
    {
        m_iconLibrary = new FluStrongBodyLabel("Flu Icons Library", this);
        m_lineEdit = new FluLineEdit(this);

        m_view = new QFrame(this);
        m_scrollArea = new FluSmoothScrollArea(m_view);
        m_scrollWidget = new QWidget(m_scrollArea);

        m_infoPanel = new FluIconInfoPanel(FluAwesomeType::More, this);

        m_vBoxLayout = new QVBoxLayout(this);
        m_hBoxLayout = new QHBoxLayout(m_view);
        m_flowLayout = new FluFlowLayout(m_scrollWidget); 
    }

  private:
    FluStrongBodyLabel* m_iconLibrary;
    FluLineEdit* m_lineEdit;

    QFrame* m_view;// 用于显示图像

    FluSmoothScrollArea* m_scrollArea;
    QWidget* m_scrollWidget;

    FluIconInfoPanel* m_infoPanel;

    QVBoxLayout* m_vBoxLayout;
    QHBoxLayout* m_hBoxLayout;
    FluFlowLayout* m_flowLayout;
};
