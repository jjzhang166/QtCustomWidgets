#-------------------------------------------------
#
# Project created by QtCreator 2017-02-08T15:54:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET      = progressbarcolor
TEMPLATE    = app

SOURCES += main.cpp\
        frmprogressbarcolor.cpp \
    flatui.cpp

HEADERS  += frmprogressbarcolor.h \
    flatui.h

FORMS    += frmprogressbarcolor.ui

CONFIG += release
MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR = bin

include(../../progressbarcolor.pri)
