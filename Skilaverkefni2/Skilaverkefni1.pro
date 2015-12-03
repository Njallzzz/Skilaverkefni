QT += core sql
QT -= gui

TARGET = Skilaverkefni1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    xmlparser.cpp \
    menu.cpp \
    sorter.cpp \
    sqlitehandler.cpp

    menu.cpp


HEADERS += \
    xmlparser.h \
    person.h \
    menu.h \
    sorter.h \
    sqlitehandler.h

    menu.h


