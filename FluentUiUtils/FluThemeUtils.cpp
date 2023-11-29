#include "FluThemeUtils.h"

FluThemeUtils* FluThemeUtils::m_themeUtils = nullptr;
FluThemeUtils::FluThemeUtils()
{
    m_themeMode = FluThemeMode::Light;
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

void FluThemeUtils::setThemeColor(const QColor& color)
{
    getInstance()->m_themeColor = color;
    getInstance()->themeColorChanged(color);
}

QString FluThemeUtils::getThemeColorName()
{
    return getThemeColor().name();
}
