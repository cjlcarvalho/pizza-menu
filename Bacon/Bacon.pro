#-------------------------------------------------
#
# Project created by QtCreator 2018-02-21T12:35:28
#
#-------------------------------------------------

QT       -= gui

TARGET = bacon
TEMPLATE = lib
CONFIG += plugin

DEFINES += BACON_LIBRARY
DESTDIR = ../decorators

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        bacon.cpp

HEADERS += \
        bacon.h \
        bacon_global.h 

DISTFILES += bacon.json

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../pizza_lib/release/ -lPizzaCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../pizza_lib/debug/ -lPizzaCore
else:unix: LIBS += -L$$PWD/../pizza_lib/ -lPizzaCore

INCLUDEPATH += $$PWD/../pizza_lib
DEPENDPATH += $$PWD/../pizza_lib
