#-------------------------------------------------
#
# Project created by QtCreator 2017-02-23T11:14:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageViewer
TEMPLATE = app


SOURCES += main.cpp \
    imageviewertest.cpp

HEADERS  += imageviewertest.h

FORMS += \
    imageviewertest.ui

CONFIG += release
MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR = bin

include(../../ImageViewer.pri)
