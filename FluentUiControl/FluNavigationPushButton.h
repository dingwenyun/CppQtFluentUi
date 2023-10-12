#pragma once

#include "FluNavigationWidget.h"
#include "../FluentUiUtils/FluentUiThemeUtils.h"
#include <QPainter>
#include <QMargins>

class FluNavigationPushButton : public FluNavigationWidget
{
	Q_OBJECT
public:
	FluNavigationPushButton(QPixmap icon, QString text, bool bSelectable, QWidget* parent = nullptr)
		: FluNavigationWidget(bSelectable, parent)
	{
		m_icon = icon;
		m_text = text;
		//setFont(this);
	}

	QString getText()
	{
		return m_text;
	}

	void setText(QString text)
	{
		m_text = text;
		update();
	}

	QPixmap getIcon()
	{
		return m_icon;
	}

	void setIcon(QPixmap icon)
	{
		m_icon = icon;
		update();
	}

	QMargins _margins()
	{
		return QMargins(0, 0, 0, 0);
	}

	bool _canDrawIndicator()
	{
		return getSelected();
	}

protected:
	void paintEvent(QPaintEvent* event) override
	{
		QPainter painter(this);
		painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing | QPainter::SmoothPixmapTransform);
		painter.setPen(Qt::NoPen);

		if (getPressed())// 鼠标按下
			painter.setOpacity(0.7);

		if (!isEnabled())// 窗口是否被禁用
			painter.setOpacity(0.4);

		QColor normalCorlor;
		QColor enterColor;
		QColor fontColor;
		QMargins tmpMargins = _margins();
		int nMarginLeft = tmpMargins.left();
		int nMarginRight = tmpMargins.right();

		QRect globalRect = QRect(mapToGlobal(QPoint()), size());

		if (FluentUiThemeUtils::getInstance()->getDarkMode() == FluentUiThemeUtilsDarkMode::Light)
		{
			normalCorlor = QColor(0, 0, 0, 6);
			enterColor = QColor(0, 0, 0, 10);
			fontColor = QColor(0, 0, 0);
		}

		if (FluentUiThemeUtils::getInstance()->getDarkMode() == FluentUiThemeUtilsDarkMode::Dark)
		{
			normalCorlor = QColor(255, 255, 255, 6);
			enterColor = QColor(255, 255, 255, 10);
			fontColor = QColor(255, 255, 255);
		}

		// 是否绘制指示器
		if (_canDrawIndicator())
		{
			// 绘制背景
			painter.setBrush(normalCorlor);
			if (getEnter())
			{
				painter.setBrush(enterColor);
			}

			painter.drawRoundedRect(rect(), 5, 5);// 绘制背景
			// 指示器暂时以蓝色为准
			//painter.setBrush(m_themeColor); // mark it!(仅仅是标记代码作用，方便查找代码)
			// 绘制指示器(竖线)
			painter.setBrush(Qt::blue);
			painter.drawRoundedRect(0 + nMarginLeft, 10, 3, 16, 1.5, 1.5);
		}

		if (!getSelected() && getEnter() && isEnabled())
		{
			painter.setBrush(enterColor);
			painter.drawRoundedRect(rect(), 5, 5);// 绘制背景
		}

		// 绘制icon
		painter.drawPixmap(QRect(11 + nMarginLeft, 10, 16, 16), m_icon);

		// 非压缩状态下绘制文字信息
		if (!getCompacted())
		{
			painter.setFont(FluNavigationPushButton::font());
			painter.setPen(fontColor);
			painter.drawText(QRect(44 + nMarginLeft, 0, width() - 57 - (nMarginLeft + nMarginRight), height()), Qt::AlignVCenter, getText());
		}
	}

private:
	QPixmap m_icon;
	QString m_text;
};

