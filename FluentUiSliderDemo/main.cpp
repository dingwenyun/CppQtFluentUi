#include <QApplication>
#include <QWidget>
#include "../FluentUiControl/FluSlider.h"

class FluSliderDemo : public QWidget
{
    //Q_OBJECT
  public:
    FluSliderDemo(QWidget* parent = nullptr) : QWidget(parent)
    {
        hSlider = new FluSlider(Qt::Horizontal, this);
        hSlider->setFixedWidth(150);
        hSlider->move(50, 30);

        vSlider = new FluSlider(Qt::Vertical, this);
        vSlider->setFixedHeight(150);
        vSlider->move(140, 80);
    }

  private:
    FluSlider* hSlider;
    FluSlider* vSlider;
};

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    FluSliderDemo demo;
    demo.show();
    return app.exec();
}