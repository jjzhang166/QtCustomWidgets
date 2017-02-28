CONFIG      += plugin
TARGET      = $$qtLibraryTarget(customwidgetlistplugin)
TEMPLATE    = lib

HEADERS     += colorprogressbarplugin.h \
    roundprogressbarplugin.h \
    customwidgetlist.h \
    circlewaitplugin.h \
    donutwaitplugin.h \
    linewaitplugin.h \
    piewaitplugin.h \
    taichiwaitplugin.h \
    zoomcirclewaitplugin.h \
    rotatecircleplugin.h \
    slidenavigationplugin.h \
    imageviewerplugin.h \
    curvechartplugin.h
SOURCES     += colorprogressbarplugin.cpp \
    roundprogressbarplugin.cpp \
    customwidgetlist.cpp \
    circlewaitplugin.cpp \
    donutwaitplugin.cpp \
    linewaitplugin.cpp \
    piewaitplugin.cpp \
    taichiwaitplugin.cpp \
    zoomcirclewaitplugin.cpp \
    rotatecircleplugin.cpp \
    slidenavigationplugin.cpp \
    imageviewerplugin.cpp \
    curvechartplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(../ColorProgressBar/ColorProgressBar.pri)
include(../CurveChart/CurveChart.pri)
include(../DynamicProgressBar/DynamicProgressBar.pri)
include(../RotateCircle/RotateCircle.pri)
include(../RoundProgressBar/RoundProgressBar.pri)
include(../SlideNavigation/SlideNavigation.pri)
include(../ImageViewer/ImageViewer.pri)

CONFIG += release
MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj
DESTDIR = bin

DEFINES += MSC
