#-------------------------------------------------
#
# Project created by QtCreator 2015-02-15T13:58:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Allproxy
TEMPLATE = app

QMAKE_CFLAGS += -std=gnu99

SOURCES += main.cpp\
        allproxy.cpp \
    cproxy.cpp \
    fproxy.cpp


HEADERS  += allproxy.h \
    constants.h \
    constants.h \
    cproxy.h \
    fproxy.h

FORMS    += allproxy.ui

