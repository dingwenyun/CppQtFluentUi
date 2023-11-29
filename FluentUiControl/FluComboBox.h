#pragma once

#include <QPushButton>
#include "FluComboBoxBase.h"
#include "FluTranslateYAnimation.h"
#include "../FluentUiUtils/FluFontUtils.h"
#include "../FluentUiUtils/FluThemeUtils.h"
#include "../FluentUiUtils/FluIconUtils.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"

class FluComboBox : public FluComboBoxBase
{
    Q_OBJECT
  public:
    FluComboBox(QWidget* parent = nullptr) : FluComboBoxBase(parent)
    {
        m_arrowAni = new FluTranslateYAnimation(this);
        FluFontUtils::setFont(this);
        QString qss = FluStyleSheetUitls::getQssByFileName("../StyleSheet/FluComboBox.qss");
        setStyleSheet(qss);
    }

    void setPlaceholderText(QString text)
    {
        QPushButton::setText(text);
    }

  protected:
    void mouseReleaseEvent(QMouseEvent* e)
    {
        QPushButton::mouseReleaseEvent(e);
        _toggleComboMenu();
    }

    void paintEvent(QPaintEvent* e)
    {
        FluComboBoxBase::paintEvent(e);
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

  private:
    FluTranslateYAnimation* m_arrowAni;
};
