CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(customwidgetlistplugin)
TEMPLATE    = lib

HEADERS     = colorprogressbarplugin.h roundprogressbarplugin.h customwidgetlist.h
SOURCES     = colorprogressbarplugin.cpp roundprogressbarplugin.cpp customwidgetlist.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include($$PWD/../ColorProgressBar/colorprogressbar.pri)
include($$PWD/../RoundProgressBar/roundprogressbar.pri)

MOC_DIR = temp/moc
RCC_DIR = temp/rcc
UI_DIR = temp/ui
OBJECTS_DIR = temp/obj
