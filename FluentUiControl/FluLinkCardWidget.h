#pragma once

#include <QWidget>
#include <QPixmap>
#include <QString>
#include <QUrl>
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include "FluImgWidget.h"
#include "../FluentUiUtils/FluIconUtils.h"

class FluLinkCardWidget : public QWidget
{
    Q_OBJECT
  public:
    FluLinkCardWidget(QWidget* parent = nullptr, QPixmap img = QPixmap(), QString title = "", QString content = "", QString url = "");

  protected:
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event);

  private:
    QVBoxLayout* m_vLayout;
    FluImgWidget* m_iconWidget;
    QLabel* m_titleLabel;
    QLabel* m_contentLabel;
    FluImgWidget* m_urlWidegt;
    QUrl m_url;
};
