#pragma once

#include <QDialog>
#include <QWidget>
#include <QHBoxLayout>
#include <QFrame>
#include "../FluentUiUtils/FluThemeUtils.h"
#include <QGraphicsDropShadowEffect>
#include <QEasingCurve>
#include <QPropertyAnimation>
#include <QCloseEvent>
#include "../FluentUiUtils/FluLogUtils.h"

class FluMaskDialog : public QDialog
{
    Q_OBJECT
  public:
    FluMaskDialog(QWidget* parent = nullptr) : QDialog(parent)
    {
        m_hBoxLayout = new QHBoxLayout(this);
        m_windowMask = new QWidget(this);

        m_widget = new QFrame(this);
        m_widget->setObjectName("centerWidget");
        setWindowFlags(Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        setGeometry(0, 0, parent->width(), parent->height());

        m_windowMask->resize(size());
        QString qss;
        if (FluThemeUtils::isDarkMode())
        {
            qss = "background:rgba(0, 0, 0, 0.6)";
        }
        else
        {
            qss = "background:rgba(255, 255, 255, 0.6)";
        }
        m_windowMask->setStyleSheet(qss);

        m_widget->setFixedSize(400, 180);
        m_hBoxLayout->addWidget(m_widget, 1, Qt::AlignCenter);
        setShadowEffect();
        window()->installEventFilter(this);
    }

    void setShadowEffect(int blurRadius = 60, QPoint offset = QPoint(0, 10), QColor color = QColor(0, 0, 0))
    {
        m_shadowEffect = new QGraphicsDropShadowEffect(m_widget);
        m_shadowEffect->setBlurRadius(blurRadius);
        m_shadowEffect->setOffset(offset);
        m_shadowEffect->setColor(color);
        m_widget->setGraphicsEffect(nullptr);
        m_widget->setGraphicsEffect(m_shadowEffect);
    }

    void setMaskColor(QColor color)
    {
        QString qss = QString::asprintf("background: rgba(%d, %d, %d, %d)", color.red(), color.green(), color.blue(), color.alpha());
        m_windowMask->setStyleSheet(qss);
    }

  protected:
    void showEvent(QShowEvent* event)
    {
        QDialog::showEvent(event);
        auto opacityEffect = new QGraphicsOpacityEffect(this);
        setGraphicsEffect(opacityEffect);
        auto opacityAni = new QPropertyAnimation(opacityEffect, "opacity", this);
        opacityAni->setStartValue(0);
        opacityAni->setEndValue(1);
        opacityAni->setDuration(200);
        opacityAni->setEasingCurve(QEasingCurve::InSine);
        connect(opacityAni, &QPropertyAnimation::finished, [=]() { opacityEffect->deleteLater(); });
        opacityAni->start();
    }

    void closeEvent(QCloseEvent* event)
    {
        m_widget->setGraphicsEffect(nullptr);
        auto opacityEffect = new QGraphicsOpacityEffect(this);
        setGraphicsEffect(opacityEffect);
        auto opacityAni = new QPropertyAnimation(opacityEffect, "opacity", this);
        opacityAni->setStartValue(1);
        opacityAni->setEndValue(0);
        opacityAni->setDuration(100);
        opacityAni->setEasingCurve(QEasingCurve::OutCubic);
        connect(opacityAni, &QPropertyAnimation::finished, [=]() { opacityEffect->deleteLater(); });
        opacityAni->start();
        event->ignore();
    }

    void resizeEvent(QResizeEvent* event)
    {
        LogDebug << "window mask resize:"
                 << "(" << size().width() << "," << size().height() << ")";
        LogDebug << "center Widget:"
                 << "(" << m_widget->width() << "," << m_widget->height() << ")";
        m_windowMask->resize(size());
    }

    bool eventFilter(QObject* obj, QEvent* event)
    {
        if (obj == window() && event->type() == QEvent::Resize)
        {
            QResizeEvent* resizeEvent = (QResizeEvent*)event;
            m_windowMask->resize(resizeEvent->size());
        }

        return QDialog::eventFilter(obj, event);
    }

  protected:
    QHBoxLayout* m_hBoxLayout;
    QWidget* m_windowMask;
    QFrame* m_widget;
    QGraphicsDropShadowEffect* m_shadowEffect;
};
