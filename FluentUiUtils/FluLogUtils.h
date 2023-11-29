#pragma once

#include <QDebug>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QMessageLogContext>
#include <qlogging.h>

// 日志格式统一规范
// [时间] [等级] [文件名] [函数名] [行数] [内容]
class FluLogUtils
{
  public:
    enum LogLevel
    {
        Debug,
        Info,
        Waring,
        Err,
    };

  public:
    FluLogUtils()
    {
    }

    static QString getTime();

    static QString getFileName(const char* file);

    static void init();
    static void exit();

    static void myMessageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg);

  public:
    static QFile* gFileLog;
    static QtMessageHandler gDefaultHandler;
};

#define LogFunc LogDebug << "called.";

#define LogDebug                                                                     \
    qDebug().nospace() << "[" << FluLogUtils::getTime().toStdString().c_str() << "]" \
                       << "["                                                        \
                       << "debug"                                                    \
                       << "]"                                                        \
                       << "[" << FluLogUtils::getFileName(__FILE__).toStdString().c_str() << "][" << __FUNCTION__ << "][" << __LINE__ << "] "

#define LogInfo                                                                      \
    qDebug().nospace() << "[" << FluLogUtils::getTime().toStdString().c_str() << "]" \
                       << "["                                                        \
                       << "info"                                                     \
                       << "]"                                                        \
                       << "[" << FluLogUtils::getFileName(__FILE__).toStdString().c_str() << "][" << __FUNCTION__ << "][" << __LINE__ << "] "

#define LogWarn                                                                      \
    qDebug().nospace() << "[" << FluLogUtils::getTime().toStdString().c_str() << "]" \
                       << "["                                                        \
                       << "warn"                                                     \
                       << "]"                                                        \
                       << "[" << FluLogUtils::getFileName(__FILE__).toStdString().c_str() << "][" << __FUNCTION__ << "][" << __LINE__ << "] "

#define LogErr                                                                       \
    qDebug().nospace() << "[" << FluLogUtils::getTime().toStdString().c_str() << "]" \
                       << "["                                                        \
                       << "err"                                                      \
                       << "]"                                                        \
                       << "[" << FluLogUtils::getFileName(__FILE__).toStdString().c_str() << "][" << __FUNCTION__ << "][" << __LINE__ << "] "
