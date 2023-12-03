#include "FluGalleryWindow.h"
#include "FluHomeInterface.h"
#include "../FluentUiUtils/FluIconUtils.h"

FluGalleryWindow::FluGalleryWindow(QWidget* parent /*= nullptr*/) : FluFrameLessWindow(parent)
{
    m_homeInterface = new FluHomeInterface(this);
    m_iconInterface = new FluIconInterface(this);
    initNavigation();
}

void FluGalleryWindow::initNavigation()
{
    addSubInterface(m_homeInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Home), "主页");
    addSubInterface(m_iconInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Favicon), "图标");
}
