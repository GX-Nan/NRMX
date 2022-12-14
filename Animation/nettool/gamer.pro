#-------------------------------------------------
#
# Project created by QtCreator 2016-09-19T13:33:20
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = gamer
TEMPLATE    = app
DESTDIR     = $$PWD/../bin
RC_FILE     = other/main.rc

SOURCES     += main.cpp
HEADERS     += head.h
RESOURCES   += other/main.qrc
CONFIG      += warn_off

INCLUDEPATH += $$PWD
INCLUDEPATH += $$PWD/api
INCLUDEPATH += $$PWD/form
INCLUDEPATH += $$PWD/Information

include ($$PWD/api/api.pri)
include ($$PWD/form/form.pri)
include(Information/Information.pro)
DISTFILES += \
    CallBack.py
INCLUDEPATH +=/usr/include/python3.7
INCLUDEPATH +=/usr/lib/python3/dist-packages
LIBS += -L/usr/lib/python3.7/config-3.7m-arm-linux-gnueabihf -lpython3.7

