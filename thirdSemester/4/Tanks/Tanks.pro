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
    window.cpp \
    Network/connectserverdialog.cpp \
    Network/networkclient.cpp \
    Network/networkcore.cpp \
    Network/networkserver.cpp \
    Input/controller.cpp \
    Input/keyboardcontroller.cpp \
    Input/networkcontroller.cpp \
    Input/observercontroller.cpp \
    Game/bigshell.cpp \
    Game/explosion.cpp \
    Game/gamecore.cpp \
    Game/landscape.cpp \
    Game/shell.cpp \
    Game/tank.cpp

HEADERS  += \
    window.h \
    Network/connectserverdialog.h \
    Network/networkclient.h \
    Network/networkcore.h \
    Network/networkserver.h \
    Input/controller.h \
    Input/keyboardcontroller.h \
    Input/networkcontroller.h \
    Input/observercontroller.h \
    Game/bigshell.h \
    Game/explosion.h \
    Game/gamecore.h \
    Game/landscape.h \
    Game/shell.h \
    Game/tank.h
