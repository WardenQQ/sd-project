#-------------------------------------------------
#
# Project created by QtCreator 2015-05-11T18:54:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = duck-interface
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../map.c \
    ../gene.c \
    ../genotype.c \
    ../population.c \
    mapwidget.cpp

HEADERS  += mainwindow.h \
    ../map.h \
    ../gene.h \
    ../genotype.h \
    ../population.h \
    mapwidget.h

FORMS    += mainwindow.ui \
    mapwidget.ui
