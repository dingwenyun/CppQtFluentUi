#pragma once

#include <QDesktopServices>
#include <QPushButton>
#include <QUrl>
#include "../FluentUiUtils/FluentUiStyleSheetUitls.h"
#include "../FluentUiUtils/FluentUiFontUtils.h"


class FluHyperLinkLabel : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(bool underlineVisible READ getUnderlineVisible WRITE setUnderlineVisble)
    Q_PROPERTY(QUrl url READ getUrl WRITE setUrl)
  public:
    FluHyperLinkLabel(QWidget* parent = nullptr) : QPushButton(parent)
    {
        m_url = QUrl();
        FluentUiFontUtils::setFont(this, 14);
        setUnderlineVisble(true);
        setCursor(Qt::PointingHandCursor);

        connect(this, &QPushButton::clicked, [=] {
            if (m_url.isValid())
                QDesktopServices::openUrl(m_url);
        });

        QString qss = FluentUiStyleSheetUitls::getQssByFileName("../StyleSheet/FluHyperLinkLabel.qss");
        setStyleSheet(qss);

        // setAttribute(Qt::WA_StyledBackground);
    }

    FluHyperLinkLabel(QString text, QWidget* parent = nullptr) : FluHyperLinkLabel(parent)
    {
        setText(text);
    }

    FluHyperLinkLabel(QString url, QString text, QWidget* parent = nullptr) : FluHyperLinkLabel(parent)
    {
        setText(text);
        m_url = QUrl(url);
    }

    void setUrl(QUrl url)
    {
        m_url = url;
    }

    QUrl getUrl()
    {
        return m_url;
    }

    bool getUnderlineVisible()
    {
        return m_bUnderlineVisible;
    }

    void setUnderlineVisble(bool bVisible)
    {
        m_bUnderlineVisible = bVisible;
        setProperty("underline", bVisible);
        // setStyle();
    }

  private:
    QUrl m_url;
    bool m_bUnderlineVisible;
};