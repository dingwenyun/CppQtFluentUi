#pragma once

#include <QPushButton>
#include "FluComboBoxBase.h"
#include "FluTranslateYAnimation.h"
#include "../FluentUiUtils/FluentUiFontUtils.h"
#include "../FluentUiUtils/FluentUiThemeUtils.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"

class FluComboBox : public QPushButton, public FluComboBoxBase
{
	Q_OBJECT
  public:
    FluComboBox(QWidget* parent = nullptr) : QPushButton(parent)
    {
        m_arrowAni = new FluTranslateYAnimation(this);
        FluentUiFontUtils::setFont(parent);
    }

    void setPlaceholderText(QString text)
    {
        QPushButton::setText(text);
    }


  protected:
     void mouseReleaseEvent(QMouseEvent *e)
    {
         QPushButton::mouseReleaseEvent(e);
        _toggleComboMenu();
    }

     void paintEvent(QPaintEvent *e)
    {
         QPushButton::paintEvent(e);
        QPainter painter;
         painter.setRenderHints(QPainter::Antialiasing);
        if (m_bHover)
            painter.setOpacity(0.8);
        else if (m_bPressed)
            painter.setOpacity(0.7);

        QRect rect = QRect(width() - 22, height() / 2 - 5 + m_arrowAni->getY(), 10, 10);
        if (FluentUiThemeUtils::getInstance()->getDarkMode() == FluentUiThemeUtilsDarkMode::Dark)
        {
            painter.drawPixmap(rect, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::ArrowDown8));
        }
        else
        {
            painter.drawPixmap(rect, FluentUiIconUtils::GetFluentIconPixmap(FluAwesomeType::ArrowDown8));
        }
    }

  private:
    FluTranslateYAnimation* m_arrowAni;
};
