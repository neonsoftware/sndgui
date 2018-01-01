#-------------------------------------------------
#
# Project created by QtCreator 2017-10-10T21:33:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets svg

TARGET = sndgui
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


INCLUDEPATH = ../sndwch/include/

unix:LIBS += -L../sndwch/build/src -L/usr/local/opt/libyaml/lib/ -lSndwch -lxml2 -lyaml

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    loaddialog.cpp \
    editdialog.cpp \
    BasicXMLSyntaxHighlighter.cpp \
    style.cpp

HEADERS += \
        mainwindow.h \
    loaddialog.h \
    editdialog.h \
    BasicXMLSyntaxHighlighter.h \
    style.h

FORMS += \
        mainwindow.ui
