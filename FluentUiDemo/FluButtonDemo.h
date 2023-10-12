#include "../FluentUiControl/FluTransparentToolButton.h"
#include "../FluentUiUtils/FluentUiIconUtils.h"
#include <QWidget>
#include "../FluentUiControl/FluButton.h"
#include <QGridLayout>

class FluPushButtonDemo : public QWidget
{
    Q_OBJECT
  public:
    FluPushButtonDemo(QWidget* parent = nullptr);

  private:
    QGridLayout* m_gridLayout;

    FluPushButton* m_pushBtn1;
    FluPushButton* m_pushBtn2;
    FluPrimaryPushButton* m_primaryBtn1;
    FluPrimaryPushButton* m_primaryBtn2;
};