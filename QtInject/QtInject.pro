QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gameapp.cpp \
    inject.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    gameapp.h \
    inject.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    inject.ui

win32: LIBS += -L'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64' -lUser32
    INCLUDEPATH += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64'DEPENDPATH += 'C:/Program Files (x86)/Windows Kits/10/Lib/10.0.19041.0/um/x64'
