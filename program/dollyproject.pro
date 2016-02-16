#-------------------------------------------------
#
# Project created by QtCreator 2015-11-16T19:59:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dollyproject
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    home.cpp \
    howto1.cpp

HEADERS  += widget.h \
    home.h \
    howto1.h

FORMS    += widget.ui \
    home.ui \
    howto1.ui

RESOURCES += \
    resource.qrc
