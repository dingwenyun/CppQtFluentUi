#pragma

#include "FluFrameLessWindow.h"
#include <QWidget>
#include "FluHomeInterface.h"
#include "FluIconInterface.h"
#include "FluSettingInterface.h"
#include "FluBasicInputInterface.h"
#include "FluDateTimeInterface.h"
#include "FluDialogInterface.h"
#include "FluLayoutInterface.h"
#include "FluMaterialInterface.h"
#include "FluMenuInterface.h"
#include "FluNavigationViewInterface.h"
#include "FluScrollInterface.h"
#include "FluStatusInfoInterface.h"
#include "FluTextInterface.h"
#include "FluViewInterface.h"

class FluGalleryWindow : public FluFrameLessWindow
{
  public:
    FluGalleryWindow(QWidget* parent = nullptr);

    void initNavigation();

  private:
    FluHomeInterface* m_homeInterface;
    FluIconInterface* m_iconInterface;

    FluBasicInputInterface* m_basicInputInterface;
    FluDateTimeInterface* m_dateTimeInterface;
    FluDialogInterface* m_dialogInterface;
    FluLayoutInterface* m_layoutInterface;
    FluMaterialInterface* m_materialInterface;
    FluMenuInterface* m_menuInterface;
    FluNavigationViewInterface* m_navigationViewInterface;
    FluScrollInterface* m_scrollInterface;
    FluStatusInfoInterface* m_statusInfoInterface;
    FluTextInterface* m_textInfterface;
    FluViewInterface* m_viewInterface;

    FluSettingInterface* m_settingInterface;
};
