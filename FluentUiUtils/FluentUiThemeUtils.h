#pragma once

#include <QObject>

enum class FluentUiThemeUtilsDarkMode
{
    Light = 0,
    Dark = 1
};

class FluentUiThemeUtils : public QObject
{
    Q_OBJECT
  public:
    FluentUiThemeUtils();

    static FluentUiThemeUtils* getInstance()
    {
        static FluentUiThemeUtils utils;
        return &utils;
    }

  public:
    Q_SIGNAL void darkModeChanged(FluentUiThemeUtilsDarkMode darkMode);
    FluentUiThemeUtilsDarkMode getDarkMode()
    {
        return m_darkMode;
    }

    void setDarkMode(FluentUiThemeUtilsDarkMode darkMode)
    {
        m_darkMode = darkMode;
        emit darkModeChanged(m_darkMode);
    }

  private:
    FluentUiThemeUtilsDarkMode m_darkMode;
};
