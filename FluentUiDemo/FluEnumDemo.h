#pragma once

#include <QWidget>
#include <QObject>

namespace EnumDemoNameSpace
{
Q_NAMESPACE
enum EnumDemo
{
    E1,
    E2,
    E3,
};

Q_ENUM_NS(EnumDemo)
}  // namespace EnumDemoNameSpace

class FluEnumDemo : public QWidget
{
  public:
    FluEnumDemo(QWidget* parent = nullptr);

  private:
};
