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

    static QColor getThemeColor()
    {
        return getInstance()->m_themeColor;
    }

    static QColor getThemeColor(FluThemeColorMode colorMode)
    {
        QColor color = getThemeColor();

        float h, s, v, f;
        color.getHsvF(&h, &s, &v, &h);

        // h:色调
        // s:饱和度颜色的鲜艳程度
        // v:亮度

        if (isDarkMode())
        {
            switch (colorMode)
            {
                case FluThemeColorMode::DARK_EST:
                    break;
                case FluThemeColorMode::DARK_ER:
                    break;
                case FluThemeColorMode::DARK:
                    break;
                case FluThemeColorMode::NORMAL:
                    break;
                case FluThemeColorMode::LIGHT:
                    break;
                case FluThemeColorMode::LIGHT_ER:
                    break;
                case FluThemeColorMode::LIGHT_EST:
                    break;
            }
        }
        else
        {
            switch (colorMode)
            {
                case FluThemeColorMode::DARK_EST:  // dark3
                    break;
                case FluThemeColorMode::DARK_ER:  // dark2
                    break;
                case FluThemeColorMode::DARK:  // dark1
                    break;
                case FluThemeColorMode::NORMAL:  // pri
                    break;
                case FluThemeColorMode::LIGHT:  // light1
                    break;
                case FluThemeColorMode::LIGHT_ER:  // light2
                    break;
                case FluThemeColorMode::LIGHT_EST:  // light3
                    break;
            }
        }

        if (s > 1)
            s = 1.0;

        if (v > 1)
            v = 1.0;

        return QColor::fromHsvF(h, s, v);
    }

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
