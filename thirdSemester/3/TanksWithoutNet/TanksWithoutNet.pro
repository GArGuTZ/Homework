#-------------------------------------------------
#
# Project created by QtCreator 2015-12-29T15:16:23
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++0x
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TanksWithoutNet
TEMPLATE = app


SOURCES += main.cpp\
        window.cpp \
    bigshell.cpp \
    explosion.cpp \
    gamecore.cpp \
    landscape.cpp \
    shell.cpp \
    tank.cpp

HEADERS  += window.h \
    bigshell.h \
    explosion.h \
    gamecore.h \
    landscape.h \
    shell.h \
    tank.h
