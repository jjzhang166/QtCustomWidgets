#-------------------------------------------------
#
# Project created by QtCreator 2017-02-09T16:23:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColorProgressBar
TEMPLATE = app


SOURCES += main.cpp\
    colorprogressbartest.cpp

HEADERS  += colorprogressbartest.h

FORMS += \
    colorprogressbartest.ui

CONFIG += release
MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR = bin

include(../../ColorProgressBar/ColorProgressBar.pri)
