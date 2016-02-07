#-------------------------------------------------
#
# Project created by QtCreator 2015-12-22T15:52:06
#
#-------------------------------------------------

QT       += core gui
QT       += core network

QMAKE_CXXFLAGS += -std=c++0x
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tanks
TEMPLATE = app


SOURCES += main.cpp\
    landscape.cpp \
    tank.cpp \
    window.cpp \
    gamecore.cpp \
    shell.cpp \
    bigshell.cpp \
    explosion.cpp \
    controller.cpp \
    networkclient.cpp \
    networkcore.cpp \
    networkserver.cpp \
    connectserverdialog.cpp \
    keyboardcontroller.cpp \
    observercontroller.cpp \
    networkcontroller.cpp

HEADERS  += \
    landscape.h \
    tank.h \
    window.h \
    gamecore.h \
    shell.h \
    bigshell.h \
    explosion.h \
    controller.h \
    networkclient.h \
    networkcore.h \
    networkserver.h \
    connectserverdialog.h \
    keyboardcontroller.h \
    observercontroller.h \
    networkcontroller.h
