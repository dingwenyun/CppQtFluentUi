#pragma once

#include <QWidget>
#include <QLabel>
#include <QFont>
#include "FluentUiControlGlobal.h"
#include "../FluentUiUtils/FluentUiThemeUtils.h"
#include "../FluentUiUtils/FluentUiFontUtils.h"

class FluLabelBase : public QLabel
{
    Q_OBJECT
    // Q_PROPERTY(QColor lightColor READ getLightColor WRITE setLightColor)
    // Q_PROPERTY(QColor darkColor READ getDarkColor WRITE setDarkColor)
    // Q_PROPERTY(int pixelFontSize READ getPixelFontSize WRITE setPixelFontSize)
    // Q_PROPERTY(bool strikeOut READ getStrikeOut WRITE setStrikeOut)
    // Q_PROPERTY(bool underline READ getUnderline WRITE setUnderline)

  public:
    FluLabelBase(QWidget* parent = nullptr);
    FluLabelBase(QString text, QWidget* parent = nullptr);

  public:
    QFont _getFont();

    void _setTextColor(QColor light = QColor(0, 0, 0), QColor dark = QColor(255, 255, 255));

    QColor getLightColor()
    {
        return m_lightColor;
    }

    void setLightColor(QColor color)
    {
        m_lightColor = color;
    }

    QColor getDarkColor()
    {
        return m_darkColor;
    }

    void setDarkColor(QColor color)
    {
        m_darkColor = color;
    }

    int getPixelFontSize()
    {
        return font().pixelSize();
    }

    void setPixelFontSize(int size)
    {
        QFont tmpfont = font();
        tmpfont.setPixelSize(size);
        setFont(tmpfont);
    }

    bool getStrikeOut()
    {
        return font().strikeOut();
    }

    void setStrikeOut(bool bStrikeOut)
    {
        QFont tmpFont = font();
        tmpFont.setStrikeOut(bStrikeOut);
        setFont(tmpFont);
    }

    bool getUnderline()
    {
        return font().underline();
    }

    void setUnderline(bool bbUnderline)
    {
        QFont tmpFont = font();
        tmpFont.setUnderline(bbUnderline);
        setFont(tmpFont);
    }

  private:
    QColor m_lightColor;
    QColor m_darkColor;
};

class FluCaptionLabel : public FluLabelBase
{
    // Q_OBJECT
  public:
    FluCaptionLabel(QWidget* parent = nullptr) : FluLabelBase(parent)
    {
        setFont(_getFont());
    }

    FluCaptionLabel(QString text, QWidget* parent = nullptr) : FluCaptionLabel(parent)
    {
        setText(text);
    }

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(12);
    }
};

class FluBodyLabel : public FluLabelBase
{
  public:
    FluBodyLabel(QWidget* parent = nullptr) : FluLabelBase(parent)
    {
        setFont(_getFont());
    }

    FluBodyLabel(QString text, QWidget* parent = nullptr) : FluBodyLabel(parent)
    {
        setText(text);
    }

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(14);
    }
};

class FluStrongBodyLabel : public FluLabelBase
{
  public:
    FluStrongBodyLabel(QWidget* parent = nullptr) : FluLabelBase(parent)
    {
        setFont(_getFont());
    }

    FluStrongBodyLabel(QString text, QWidget* parent = nullptr) : FluStrongBodyLabel(parent)
    {
        setText(text);
    }

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(14, QFont::DemiBold);
    }
};

class FluSubTitleLabel : public FluLabelBase
{
  public:
    FluSubTitleLabel(QWidget* parent = nullptr) : FluLabelBase(parent)
    {
        setFont(_getFont());
    }

    FluSubTitleLabel(QString text, QWidget* parent = nullptr) : FluSubTitleLabel(parent)
    {
        setText(text);
    }

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(20, QFont::DemiBold);
    }
};

class FluTitleLabel : public FluLabelBase
{
  public:
    FluTitleLabel(QWidget* parent = nullptr) : FluLabelBase(parent)
    {
        setFont(_getFont());
    }

    FluTitleLabel(QString text, QWidget* parent = nullptr) : FluTitleLabel(parent)
    {
        setText(text);
    }

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(28, QFont::DemiBold);
    }
};

class FluLargeTitleLabel : public FluLabelBase
{
  public:
    FluLargeTitleLabel(QWidget* parent = nullptr) : FluLabelBase(parent)
    {
        setFont(_getFont());
    }

    FluLargeTitleLabel(QString text, QWidget* parent = nullptr) : FluLargeTitleLabel(parent)
    {
        setText(text);
    }

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(40, QFont::DemiBold);
    }
};

class FluDisplayLabel : public FluLabelBase
{
  public:
    FluDisplayLabel(QWidget* parent = nullptr) : FluLabelBase(parent)
    {
        setFont(_getFont());
    }

    FluDisplayLabel(QString text, QWidget* parent = nullptr) : FluDisplayLabel(parent)
    {
        setText(text);
    }

    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(68, QFont::DemiBold);
    }
};
