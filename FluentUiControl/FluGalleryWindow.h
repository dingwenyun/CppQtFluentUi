#pragma 

#include "FluFrameLessWindow.h"
#include <QWidget>
#include "FluHomeInterface.h"

class FluGalleryWindow : public FluFrameLessWindow
{
  public:
    FluGalleryWindow(QWidget* parent = nullptr);

    void initNavigation();
  private:
    FluHomeInterface* m_homeInterface;
};
