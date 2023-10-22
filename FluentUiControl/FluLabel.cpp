#include "FluDef.h"
#include "FluLabel.h"

FluLabelBase::FluLabelBase(QWidget *parent) : QLabel(parent)
{
    FluSetNameAndStypeSheet(FluLabelBase);
}

FluLabelBase::~FluLabelBase()
{
}
