`@pyqtProperty`是一个装饰器用于在PyQt中定义属性。

在PyQt中，可以使用`@pyqtProperty`装饰器为类定义自定义属性，以提供属性的读取和写入功能。这样可以方便地通过属性语法访问和修改属性的值，而不是直接访问和修改类的实例变量。

以下是一个使用`@pyqtProperty`装饰器的示例：

```
from PyQt5.QtCore import QObject, pyqtProperty

class MyClass(QObject):
    def __init__(self, value):
        super().__init__()
        self._value = value

    @pyqtProperty(int)
    def value(self):
        return self._value

    @value.setter
    def value(self, new_value):
        self._value = new_value
```

在这个例子中，`value`被定义为一个属性，类型为整数。`@pyqtProperty(int)`用于指定属性的类型。属性的读取和写入方法分别定义为`value`和`value.setter`。在外部代码中，可以通过以下方式访问和修改属性的值：

```
obj = MyClass(10)
print(obj.value)   # 输出 10

obj.value = 20
print(obj.value)   # 输出 20
```

通过使用`@pyqtProperty`装饰器，可以更方便地定义属性，并实现对属性的访问和修改。