#pragma once

#include "FluNavigationPushButton.h"
#include "FluNavigationTreeWidget.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"
#include <QPropertyAnimation>
#include <QMargins>

class FluNavigationTreeItem : public FluNavigationPushButton
{
	Q_OBJECT
		Q_PROPERTY(bool arrowAngle READ getArrowAngle WRITE setArrowAngle)
public:
	FluNavigationTreeItem(QPixmap icon, QString text, bool bSelectable, QWidget* parent = nullptr);

	void setExpanded(bool bExpanded);

	bool _canDrawIndicator();

	QMargins _margins();

	int getArrowAngle()
	{
		return m_nArrowAngle;
	}

	void setArrowAngle(int nArrowAngle)
	{
		m_nArrowAngle = nArrowAngle;
		update();
	}
signals:
	void itemClicked(bool bTrigger, bool bClickArrow);

protected:
	void paintEvent(QPaintEvent* event);

	void mouseReleaseEvent(QMouseEvent* event);
private:
	QPropertyAnimation* m_rotateAni;
	// 箭头旋转角度
	int m_nArrowAngle;
};

