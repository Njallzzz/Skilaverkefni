QT += core
QT -= gui

TARGET = Skilaverkefni1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    xmlparser.cpp

HEADERS += \
    xmlparser.h \
    person.h

