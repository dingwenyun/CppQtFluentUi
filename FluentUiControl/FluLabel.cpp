#include "FluLabel.h"

FluLabelBase::FluLabelBase(QWidget* parent /*= nullptr*/) : QLabel(parent)
{
    // setFont(_getFont());
    _setTextColor();
}

FluLabelBase::FluLabelBase(QString text, QWidget* parent /*= nullptr*/) : FluLabelBase(parent)
{
    setText(text);
}

QFont FluLabelBase::_getFont()
{
    return QFont();
}

void FluLabelBase::_setTextColor(QColor light /*= QColor(0,0,0)*/, QColor dark /*= QColor(255, 255, 255)*/)
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
