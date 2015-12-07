QT += core sql
QT -= gui

TARGET = Skilaverkefni1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    menu.cpp \
    sqlitehandler.cpp \
    computer.cpp \
    person.cpp


HEADERS +=\
    person.h \
    menu.h \
    sqlitehandler.h \
    computer.h


