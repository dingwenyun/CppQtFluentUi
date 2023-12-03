#pragma

#include "FluFrameLessWindow.h"
#include <QWidget>
#include "FluHomeInterface.h"
#include "FluIconInterface.h"

class FluGalleryWindow : public FluFrameLessWindow
{
  public:
    FluGalleryWindow(QWidget* parent = nullptr);

    void initNavigation();

  private:
    FluHomeInterface* m_homeInterface;
    FluIconInterface* m_iconInterface;
};
