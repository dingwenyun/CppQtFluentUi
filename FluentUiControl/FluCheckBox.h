#pragma once

#include <QCheckBox>

#include "FluDef.h"
#include "../FluentUiUtils/FluStyleSheetUitls.h"
#include <QPainter>
#include <QStyleOptionButton>
#include "../FluentUiUtils/FluIconUtils.h"

class FluCheckBox : public QCheckBox
{
    Q_OBJECT
  public:
    FluCheckBox(QWidget* parent = nullptr) : QCheckBox(parent)
    {
        QString qss = FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluCheckBox.qss");
        setStyleSheet(qss);
    }

    FluCheckBox(QString text, QWidget* parent)
    {
        QString qss = FluStyleSheetUitls::getThemeQssByFileName("../StyleSheet/FluCheckBox.qss");
        setStyleSheet(qss);
        setText(text);
    }

  protected:
    void paintEvent(QPaintEvent* event)
    {
        QCheckBox::paintEvent(event);

        QPainter painter(this);

        if (!isEnabled())
            painter.setOpacity(0.8);

        auto opt = QStyleOptionButton();
        opt.initFrom(this);
        auto rect = style()->subElementRect(QStyle::SE_CheckBoxIndicator, &opt, this);

        if (checkState() == Qt::Checked)
            painter.drawPixmap(rect, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Accept));
        else if (checkState() == Qt::PartiallyChecked)
            painter.drawPixmap(rect, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Remove));
    }
};
