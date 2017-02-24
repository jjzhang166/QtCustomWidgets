#-------------------------------------------------
#
# Project created by QtCreator 2017-02-14T10:00:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SlideNavigation
TEMPLATE = app


SOURCES += main.cpp\
    slidenavigationtest.cpp

HEADERS  += \
    slidenavigationtest.h

FORMS += \
    slidenavigationtest.ui

CONFIG += release
MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR = bin

include(../../SlideNavigation/SlideNavigation.pri)
