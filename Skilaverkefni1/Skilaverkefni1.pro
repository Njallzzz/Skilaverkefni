QT += core
QT -= gui

TARGET = Skilaverkefni1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    xmlparser.cpp \
    sorter.cpp

HEADERS += \
    xmlparser.h \
    person.h \
    sorter.h

