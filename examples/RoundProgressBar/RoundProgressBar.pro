#-------------------------------------------------
#
# Project created by QtCreator 2017-02-08T23:05:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RoundProgressBar
TEMPLATE = app


SOURCES += main.cpp\
        roundprogressbar.cpp \
    roundprogressbartest.cpp

HEADERS  += roundprogressbar.h \
    roundprogressbartest.h

FORMS    += \
    roundprogressbartest.ui

CONFIG += release
MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR = bin
