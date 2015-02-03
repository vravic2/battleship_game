#-------------------------------------------------
#
# Project created by QtCreator 2014-02-07T20:41:53
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CS440CodingProject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamerules.cpp \
    oneplayergame.cpp \
    signin.cpp \
    player.cpp \
    login.cpp

HEADERS  += mainwindow.h \
    gamerules.h \
    oneplayergame.h \
    signin.h \
    player.h \
    login.h

FORMS    += mainwindow.ui \
    gamerules.ui \
    oneplayergame.ui \
    signin.ui \
    login.ui

RESOURCES += \
    files.qrc
