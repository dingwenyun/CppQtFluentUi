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

class FluGalleryWindow : public FluFrameLessWindow
{
  public:
    FluGalleryWindow(QWidget* parent = nullptr);

    void initNavigation();

  private:
    FluHomeInterface* m_homeInterface;
    FluIconInterface* m_iconInterface;
    FluSettingInterface* m_settingInterface;
    FluBasicInputInterface* m_basicInputInterface;
    FluDateTimeInterface* m_dateTimeInterface;
    FluDialogInterface* m_dialogInterface;
    FluLayoutInterface* m_layoutInterface;
};
