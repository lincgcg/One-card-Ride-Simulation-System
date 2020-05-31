#-------------------------------------------------
#
# Project created by QtCreator 2020-05-19T22:51:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test4
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    identitywindow.cpp \
    studentsignindialog.cpp \
    teachersignindialog.cpp \
    teacherfamilysignindialog.cpp \
    data.cpp \
    functionselectionwindow.cpp \
    people.cpp \
    rechargewindows.cpp \
    logonmainwindow.cpp \
    bus.cpp \
    buswindow.cpp

HEADERS += \
        mainwindow.h \
    bus.h \
    people.h \
    identitywindow.h \
    identitywindow.h \
    studentsignindialog.h \
    teachersignindialog.h \
    teacherfamilysignindialog.h \
    data.h \
    functionselectionwindow.h \
    rechargewindows.h \
    logonmainwindow.h \
    buswindow.h

FORMS += \
        mainwindow.ui \
    identitywindow.ui \
    studentsignindialog.ui \
    teachersignindialog.ui \
    teacherfamilysignindialog.ui \
    functionselectionwindow.ui \
    rechargewindows.ui \
    logonmainwindow.ui \
    buswindow.ui
