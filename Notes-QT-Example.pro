QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webenginewidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CodeEditor/AceEditorWindow.cpp \
    CodeEditor/jscript.cpp \
    main.cpp \
    mainwindow.cpp \
    progressbar.cpp \
    window/dialogchildwindow.cpp \
    window/dialogwindowinteractive.cpp

HEADERS += \
    CodeEditor/AceEditorWindow.h \
    CodeEditor/jscript.h \
    mainwindow.h \
    progressbar.h \
    window/dialogchildwindow.h \
    window/dialogwindowinteractive.h

FORMS += \
    CodeEditor/AceEditorWindow.ui \
    mainwindow.ui \
    progressbar.ui \
    window/dialogchildwindow.ui \
    window/dialogwindowinteractive.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ace.qrc
