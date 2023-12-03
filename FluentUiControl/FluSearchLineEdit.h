#pragma once

#include "FluLineEdit.h"
#include "FluLineEditButton.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include <QString>

class FluSearchLineEdit : public FluLineEdit
{
    Q_OBJECT
  public:
    FluSearchLineEdit(QWidget* parent = nullptr) : FluLineEdit(parent)
    {
        m_searchButton = new FluLineEditButton(FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Search), this);
        m_hBoxLayout->addWidget(m_searchButton, 0, Qt::AlignRight);
        setClearButtonEnabled(true);
       // setTextMargins(0, 0, 59, 0);
       m_searchButton->setObjectName("lineEditButton");
    }

    void setClearButtonEnabled(bool bEnable)
    {
        m_bClearButtonEnable = bEnable;
        if (bEnable)
        {
            setTextMargins(0, 0, 28 + 30, 0);
        }
        else
        {
            setTextMargins(0, 0, 0 + 30, 0);
        }
    }

  signals:
    void searchSigal(QString str);
    void clearSignal();

public slots:
   void search()
  {
       QString searchText = text();
      if (!searchText.isEmpty())
       {
          emit searchSigal(searchText);
           return;
       }

      emit clearSignal();
  }
  private:
    FluLineEditButton* m_searchButton;
};
