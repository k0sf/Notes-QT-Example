QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webenginewidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CodeEditor/AceEditorWindow.cpp \
    CodeEditor/MonacoEditorWindow.cpp \
    CodeEditor/jscript.cpp \
    inputs/comboboxdialog.cpp \
    item/listview/customlistviewdelegate.cpp \
    item/listview/dialoglistview.cpp \
    item/listwidget/dialoglistwidget.cpp \
    item/tableview/customtableviewmodel.cpp \
    item/tableview/dialogtableview.cpp \
    item/tableview/tableviewmodel.cpp \
    main.cpp \
    mainwindow.cpp \
    progressbar.cpp \
    window/dialogchildwindow.cpp \
    window/dialogwindowinteractive.cpp

HEADERS += \
    CodeEditor/AceEditorWindow.h \
    CodeEditor/MonacoEditorWindow.h \
    CodeEditor/jscript.h \
    inputs/comboboxdialog.h \
    item/listview/customlistviewdelegate.h \
    item/listview/dialoglistview.h \
    item/listwidget/dialoglistwidget.h \
    item/tableview/customtableviewmodel.h \
    item/tableview/dialogtableview.h \
    item/tableview/tableviewmodel.h \
    mainwindow.h \
    progressbar.h \
    window/dialogchildwindow.h \
    window/dialogwindowinteractive.h

FORMS += \
    CodeEditor/AceEditorWindow.ui \
    CodeEditor/MonacoEditorWindow.ui \
    inputs/comboboxdialog.ui \
    item/listview/dialoglistview.ui \
    item/listwidget/dialoglistwidget.ui \
    item/tableview/dialogtableview.ui \
    mainwindow.ui \
    progressbar.ui \
    window/dialogchildwindow.ui \
    window/dialogwindowinteractive.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ace.qrc \
    monaco.qrc
