#-------------------------------------------------
#
# Project created by QtCreator 2015-11-14T13:11:56
#
#-------------------------------------------------

QT       += core

QT       -= gui

QT      += testlib
QMAKE_CXXFLAGS += -std=c++0x

TARGET = 1
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    computer.cpp \
    network.cpp \
    ivirus.cpp \
    goodvirus.cpp \
    killervirus.cpp \
    standartvirus.cpp

HEADERS += \
    network.h \
    computer.h \
    computertest.h \
    networktest.h \
    ivirus.h \
    goodvirus.h \
    killervirus.h \
    standartvirus.h
