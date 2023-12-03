#include "FluGalleryWindow.h"
#include "FluHomeInterface.h"
#include "../FluentUiUtils/FluIconUtils.h"

FluGalleryWindow::FluGalleryWindow(QWidget* parent /*= nullptr*/) : FluFrameLessWindow(parent)
{
    m_homeInterface = new FluHomeInterface(this);

    initNavigation();
}

void FluGalleryWindow::initNavigation()
{
    addSubInterface(m_homeInterface, FluIconUtils::GetFluentIconPixmap(FluAwesomeType::Home), "home");
}
