@REM 删除所有文件
rd /s /q E:\CodeLibraries\CppQtFluentUi\FluentUiGalleryWin64Msvc2019\
mkdir E:\CodeLibraries\CppQtFluentUi\FluentUiGalleryWin64Msvc2019\package
@REM 拷贝所有文件
cp -r E:\CodeLibraries\CppQtFluentUi\res							E:\CodeLibraries\CppQtFluentUi\FluentUiGalleryWin64Msvc2019
cp -r E:\CodeLibraries\CppQtFluentUi\StyleSheet						E:\CodeLibraries\CppQtFluentUi\FluentUiGalleryWin64Msvc2019
cp E:\CodeLibraries\CppQtFluentUi\x64\Release\bin\FluentUiGallery.exe 				E:\CodeLibraries\CppQtFluentUi\FluentUiGalleryWin64Msvc2019\package
cp E:\CodeLibraries\CppQtFluentUi\third_party\install\bin\release\FramelessHelperCore64.dll 		E:\CodeLibraries\CppQtFluentUi\FluentUiGalleryWin64Msvc2019\package
cp E:\CodeLibraries\CppQtFluentUi\third_party\install\bin\release\FramelessHelperQuick64.dll 		E:\CodeLibraries\CppQtFluentUi\FluentUiGalleryWin64Msvc2019\package
cp E:\CodeLibraries\CppQtFluentUi\third_party\install\bin\release\FramelessHelperWidgets64.dll 	E:\CodeLibraries\CppQtFluentUi\FluentUiGalleryWin64Msvc2019\package
C:\Qt\6.5.1\msvc2019_64\bin\windeployqt.exe E:\CodeLibraries\CppQtFluentUi\FluentUiGalleryWin64Msvc2019\package
pause