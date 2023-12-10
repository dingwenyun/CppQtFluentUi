## QParallelAnimationGroup及QPropertyAnimation

>QParallelAnimationGroup是Qt中的一个类，用于管理和调度同时进行的多个动画。使用QParallelAnimationGroup，可以将多个动画组合在一起，并同时开始它们，以实现同时执行多个动画效果。
>
>而QPropertyAnimation是用于对QWidget或QObject属性进行动画化处理的类。它可以通过设置起始值和目标值，并指定动画持续的时间来实现属性动画。
>
>通过结合使用QParallelAnimationGroup和QPropertyAnimation，可以实现多个属性的同时动画处理。例如，可以通过QPropertyAnimation对一个对象的多个属性进行动画效果，并将这些动画放入QParallelAnimationGroup中，从而实现多个属性的同时动画处理。

>当您希望同时执行多个不同的属性动画时，可以使用QParallelAnimationGroup和QPropertyAnimation。下面是一个简单的示例，演示如何在Qt中使用这两个类来同时对多个属性进行动画处理：
>
>```
>#include <QApplication>
>#include <QWidget>
>#include <QPushButton>
>#include <QPropertyAnimation>
>#include <QParallelAnimationGroup>
>
>int main(int argc, char *argv[])
>{
>    QApplication a(argc, argv);
>
>    // 创建一个窗口和一个按钮
>    QWidget window;
>    window.resize(300, 200);
>    window.setWindowTitle("Parallel Animation Example");
>
>    QPushButton button("Animate me!", &window);
>    button.setGeometry(50, 50, 100, 50);
>
>    // 创建两个属性动画
>    QPropertyAnimation *posAnimation = new QPropertyAnimation(&button, "pos");
>    posAnimation->setDuration(1000); // 动画持续时间为1秒
>    posAnimation->setStartValue(QPoint(50, 50)); // 起始位置
>    posAnimation->setEndValue(QPoint(150, 100)); // 结束位置
>
>    QPropertyAnimation *sizeAnimation = new QPropertyAnimation(&button, "size");
>    sizeAnimation->setDuration(1000); // 动画持续时间为1秒
>    sizeAnimation->setStartValue(QSize(100, 50)); // 起始大小
>    sizeAnimation->setEndValue(QSize(200, 100)); // 结束大小
>
>    // 创建并管理并行动画组
>    QParallelAnimationGroup group;
>    group.addAnimation(posAnimation);
>    group.addAnimation(sizeAnimation);
>
>    // 开始执行动画
>    window.show();
>    group.start();
>
>    return a.exec();
>}
>```
>
>在上面的示例中，我们创建了一个窗口和一个按钮，并同时对按钮的位置和大小属性进行动画处理。我们使用QPropertyAnimation分别创建了位置和大小的属性动画，并将它们添加到QParallelAnimationGroup中。最后，通过调用group.start()来启动并行动画组的动画效果。当程序运行时，您将看到按钮同时在位置和大小上执行动画效果。

