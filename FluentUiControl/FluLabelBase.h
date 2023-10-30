#pragma once
#include <QColor>
#include <QLabel>
#include <QWidget>

class FluLabelBase : public QLabel
{
    Q_OBJECT
    Q_PROPERTY(QColor lightColor READ getLightColor WRITE setLightColor)
    Q_PROPERTY(QColor darkColor READ getDarkColor WRITE setDarkColor)
    Q_PROPERTY(int pixelFontSize READ getPixelFontSize WRITE setPixelFontSize)
    Q_PROPERTY(bool strikeOut READ getStrikeOut WRITE setStrikeOut)
    Q_PROPERTY(bool underline READ getUnderline WRITE setUnderline)

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