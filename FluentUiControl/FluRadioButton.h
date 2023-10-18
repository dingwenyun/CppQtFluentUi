#pragma once

#include <QRadioButton>
#include <QFile>

class FluRadioButton : public QRadioButton
{
	Q_OBJECT
public:
	FluRadioButton(QWidget* parent = nullptr);
	FluRadioButton(QString text, QWidget* parent = nullptr);
};

