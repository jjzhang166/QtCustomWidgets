#-------------------------------------------------
#
# Project created by QtCreator 2017-02-28T20:06:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TreeNavigationBar
TEMPLATE = app


SOURCES += main.cpp\
    treenavigationbartest.cpp

HEADERS  += treenavigationbartest.h

FORMS += \
    treenavigationbartest.ui

CONFIG += release
MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR = bin

include(../../TreeNavigationBar/TreeNavigationBar.pri)
