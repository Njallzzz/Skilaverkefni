#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T21:28:25
#
#-------------------------------------------------

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = skilaverkefni3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    person.cpp \
    sqlitehandler.cpp \
    computerwindow.cpp\
    personwindow.cpp

HEADERS  += mainwindow.h \
    computer.h \
    person.h \
    sqlitehandler.h \
    computerwindow.h \
    personwindow.h

FORMS    += mainwindow.ui \
    computerwindow.ui

FORMS    += mainwindow.ui \
    personwindow.ui
