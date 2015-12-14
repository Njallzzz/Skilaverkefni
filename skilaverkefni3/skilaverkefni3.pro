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
    models/computer.cpp \
    models/person.cpp \
    repositories/sqlitehandler.cpp \
    services/interface.cpp \
    ui/computerwindow.cpp \
    ui/mainwindow.cpp \
    ui/personwindow.cpp \
    ui/aboutwindow.cpp

HEADERS  += models/computer.h \
    models/person.h \
    repositories/sqlitehandler.h \
    services/interface.h \
    ui/computerwindow.h \
    ui/mainwindow.h \
    ui/personwindow.h \
    ui/aboutwindow.h

FORMS    += ui/computerwindow.ui \
    ui/mainwindow.ui \
    ui/personwindow.ui \
    ui/aboutwindow.ui

RESOURCES += pictures.qrc

RC_FILE += app.rc
