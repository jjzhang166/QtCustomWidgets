#-------------------------------------------------
#
# Project created by QtCreator 2017-02-16T23:55:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RotateCircle
TEMPLATE = app


SOURCES += main.cpp\
        rotatecircle.cpp \
    rotatecircletest.cpp

HEADERS  += rotatecircle.h \
    rotatecircletest.h

FORMS += \
    rotatecircletest.ui

MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR = bin

