#include <QApplication>
#include "../FluentUiControl/FluRadioButton.h"
#include <QVBoxLayout>

class FluRadioButtonDemo : public QWidget
{
  public:
    FluRadioButtonDemo(QWidget* parent = nullptr) : QWidget(parent)
    {
        QVBoxLayout* layout = new QVBoxLayout(this);

        FluRadioButton* btn1 = new FluRadioButton("option 1", this);
        FluRadioButton* btn2 = new FluRadioButton("option 2", this);
        FluRadioButton* btn3 = new FluRadioButton("option 3", this);
        layout->addWidget(btn1);
        layout->addWidget(btn2);
        layout->addWidget(btn3);
    }
};

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    FluRadioButtonDemo demo;
    demo.show();

    return app.exec();
}