#include "FluThemeUtils.h"

FluThemeUtils* FluThemeUtils::m_themeUtils = nullptr;
FluThemeUtils::FluThemeUtils()
{
    m_themeMode = FluThemeMode::Light;
    m_themeColor = QColor("#009faa");
}

FluThemeUtils* FluThemeUtils::getInstance()
{
    if (m_themeUtils == nullptr)
    {
        return new FluThemeUtils;
    }

    return m_themeUtils;
}

FluThemeMode FluThemeUtils::getThemeMode()
{
    return getInstance()->m_themeMode;
}

bool FluThemeUtils::isDarkMode()
{
    return getThemeMode() == FluThemeMode::Dark;
}

void FluThemeUtils::setThemeMode(FluThemeMode themeMode)
{
    getInstance()->m_themeMode = themeMode;
    // emit getInstance->themeModeChanged(themeMode));
    getInstance()->themeModeChanged(themeMode);
}

QColor FluThemeUtils::getThemeColor()
{
    return getThemeColorByColorMode(getInstance()->m_themeColor, FluThemeColorMode::NORMAL);
}

QColor FluThemeUtils::getThemeColorNormal()
{
    return getThemeColorByColorMode(getInstance()->m_themeColor, FluThemeColorMode::NORMAL);
}

QColor FluThemeUtils::getThemeColorLight()
{
    return getThemeColorByColorMode(getInstance()->m_themeColor, FluThemeColorMode::LIGHT);
}

QColor FluThemeUtils::getThemeColorLighter()
{
    return getThemeColorByColorMode(getInstance()->m_themeColor, FluThemeColorMode::LIGHT_ER);
}

QColor FluThemeUtils::getThemeColorLightest()
{
    return getThemeColorByColorMode(getInstance()->m_themeColor, FluThemeColorMode::LIGHT_EST);
}

QColor FluThemeUtils::getThemeColorDark()
{
    return getThemeColorByColorMode(getInstance()->m_themeColor, FluThemeColorMode::DARK);
}

QColor FluThemeUtils::getThemeColorDarker()
{
    return getThemeColorByColorMode(getInstance()->m_themeColor, FluThemeColorMode::DARK_ER);
}

QColor FluThemeUtils::getThemeColorDarkest()
{
    return getThemeColorByColorMode(getInstance()->m_themeColor, FluThemeColorMode::DARK_EST);
}

QColor FluThemeUtils::getThemeColorByColorMode(QColor color, FluThemeColorMode colorMode)
{
    // QColor color = getThemeColor();
    float h, s, v, f;
    color.getHsvF(&h, &s, &v, &f);

    // h:色调
    // s:饱和度颜色的鲜艳程度
    // v:亮度

    if (isDarkMode())
    {
        s *= 0.84;
        v = 1;
        switch (colorMode)
        {
            case FluThemeColorMode::DARK_EST:
                s *= 0.95;
                v *= 0.7;
                break;
            case FluThemeColorMode::DARK_ER:
                s *= 0.977;
                v *= 0.82;
                break;
            case FluThemeColorMode::DARK:
                v *= 0.9;
                break;
            case FluThemeColorMode::NORMAL:
                break;
            case FluThemeColorMode::LIGHT:
                s *= 0.92;
                break;
            case FluThemeColorMode::LIGHT_ER:
                s *= 0.78;
                break;
            case FluThemeColorMode::LIGHT_EST:
                s *= 0.65;
                break;
        }
    }
    else
    {
        switch (colorMode)
        {
            case FluThemeColorMode::DARK_EST:  // dark3
                s *= 1.1;
                v *= 0.4;
                break;
            case FluThemeColorMode::DARK_ER:  // dark2
                s *= 1.05;
                v *= 0.5;
                break;
            case FluThemeColorMode::DARK:  // dark1
                v *= 0.75;
                break;
            case FluThemeColorMode::NORMAL:  // pri
                break;
            case FluThemeColorMode::LIGHT:  // light1
                v *= 1.05;
                break;
            case FluThemeColorMode::LIGHT_ER:  // light2
                s *= 0.75;
                v *= 1.05;
                break;
            case FluThemeColorMode::LIGHT_EST:  // light3
                s *= 0.65;
                v *= 1.05;
                break;
        }
    }

    if (s > 1)
        s = 1.0;

    if (v > 1)
        v = 1.0;

    return QColor::fromHsvF(h, s, v);
}

QColor FluThemeUtils::getThemeColorByColorMode(FluThemeColorMode colorMode)
{
    return getThemeColorByColorMode(getInstance()->m_themeColor, colorMode);
}

void FluThemeUtils::setThemeColor(const QColor& color)
{
    getInstance()->m_themeColor = color;
    getInstance()->themeColorChanged(color);
}

QString FluThemeUtils::getThemeColorName()
{
    return getThemeColor().name();
}
