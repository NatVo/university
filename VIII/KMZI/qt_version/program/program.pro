#-------------------------------------------------
#
# Project created by QtCreator 2018-05-04T10:47:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = program
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    rsawindow.cpp \
    vernamwindow.cpp \
    blockcipherwindow.cpp \
    sequencewindow.cpp

HEADERS  += mainwindow.h \
    rsawindow.h \
    vernamwindow.h \
    blockcipherwindow.h \
    sequencewindow.h

FORMS    += mainwindow.ui \
    rsawindow.ui \
    vernamwindow.ui \
    blockcipherwindow.ui \
    sequencewindow.ui
