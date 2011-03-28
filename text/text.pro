CONFIG      += designer plugin debug_and_release
TARGET      = $$qtLibraryTarget(navyplugin)
TEMPLATE    = lib

HEADERS     = navyplugin.h
SOURCES     = navyplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(navy.pri)
