#-------------------------------------------------
#
# Project created by QtCreator 2015-06-09T13:47:29
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
DESTDIR   = $$PWD
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = finalgame
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bar.cpp \
    ball.cpp \
    rocks.cpp \
    easymusic.cpp

HEADERS  += mainwindow.h \
    bar.h \
    ball.h \
    rocks.h \
    easymusic.h

RESOURCES += \
    resource.qrc

DISTFILES +=
