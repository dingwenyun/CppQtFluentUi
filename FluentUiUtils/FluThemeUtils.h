#pragma once

#include <QObject>
#include <QColor>

enum class FluThemeMode
{
    Light = 0,
    Dark = 1
};

enum class FluThemeColorMode
{
    DARK_EST,
    DARK_ER,
    DARK,
    NORMAL,
    LIGHT,
    LIGHT_ER,
    LIGHT_EST,
};

class FluThemeUtils : public QObject
{
    Q_OBJECT
  public:
    FluThemeUtils();

    static FluThemeUtils* getInstance();

  public:
    static FluThemeMode getThemeMode();
    static bool isDarkMode();  // 判断是否是黑色模式
    static void setThemeMode(FluThemeMode themeMode);

    static QColor getThemeColor();

    static QColor getThemeColorByColorMode(QColor color, FluThemeColorMode colorMode);
    static QColor getThemeColorByColorMode(FluThemeColorMode colorMode);
    static void setThemeColor(const QColor& color);
    static QString getThemeColorName();
  signals:
    void themeModeChanged(FluThemeMode themeMode);
    void themeColorChanged(QColor color);

  private:
    FluThemeMode m_themeMode;
    QColor m_themeColor;
    static FluThemeUtils* m_themeUtils;
};
