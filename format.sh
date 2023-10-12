clang-format --version
find FluentUiControl FluentUiDemo FluentUiExample FluentUiUtils -name *.h -o -name *.cpp -exec unix2dos {} \;
find FluentUiControl FluentUiDemo FluentUiExample FluentUiUtils -name *.h -o -name *.cpp|xargs clang-format -i -style=file