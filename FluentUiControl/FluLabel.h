#pragma once

#include <QWidget>
#include <QLabel>
#include "FluentUiControlGlobal.h"
#include "../FluentUiUtils/FluentUiThemeUtils.h"
#include "../FluentUiUtils/FluentUiFontUtils.h"

class FluLabelBase : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(QColor lightColor READ getLightColor WRITE setLightColor)
    Q_PROPERTY(QColor darkColor READ getDarkColor WRITE setDarkColor)
    Q_PROPERTY(int pixelFontSize READ getPixelFontSize WRITE setPixelFontSize)
    Q_PROPERTY(bool pixelFontSize READ getStrikeOut WRITE setStrikeOut)
    Q_PROPERTY(bool underline READ getUnderline WRITE setUnderline)

  public:
    FluLabelBase(QWidget *parent = nullptr) : QLabel(this)
    {
        setFont(_getFont());
        _setTextColor();
    }

    FluLabelBase(QString text, QWidget* parent = nullptr) : FluLabelBase(parent)
    {
        setText(text);
    }

    ~FluLabelBase()
    {
    }

  public:
    virtual QFont _getFont() = 0;

    void _setTextColor(QColor light = QColor(0,0,0), QColor dark = QColor(255, 255, 255))
    {
        m_lightColor = light;
        m_darkColor = dark;
        
        QPalette tmpPalette = palette();
        QColor textColor;
        if (FluentUiThemeUtils::getInstance()->getDarkMode() == FluentUiThemeUtilsDarkMode::Dark)
        {
            textColor = m_darkColor;
        }
        else
        {
            textColor = m_lightColor;
        }
        tmpPalette.setColor(QPalette::WindowText, textColor);
        setPalette(tmpPalette);
    }

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
  public:
      QFont _getFont()
    {
          return FluentUiFontUtils::getFont(12);
    }
};

class FluBodyLabel : public FluLabelBase
{
  public:
    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(14);
    }
};


class FluStrongBodyLabel : public FluLabelBase
{
  public:
    QFont _getFont()
    {
          return FluentUiFontUtils::getFont(14, QFont::DemiBold);
    }
};

class FluSubtitleLabel : public FluLabelBase
{
  public:
    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(20, QFont::DemiBold);
    }
};

class FluTitleLabel : public FluLabelBase
{
  public:
    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(28, QFont::DemiBold);
    }
};

class FluLargeTitleLabel : public FluLabelBase
{
  public:
    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(40, QFont::DemiBold);
    }
};

class FluDisplayLabel : public FluLabelBase
{
  public:
    QFont _getFont()
    {
        return FluentUiFontUtils::getFont(68, QFont::DemiBold);
    }
};
