#-------------------------------------------------
#
# Project created by QtCreator 2016-11-23T15:01:38
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TAC
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vehicule.cpp \
    location.cpp \
    chauffeur.cpp \
    fenetre.cpp

HEADERS  += mainwindow.h \
    vehicule.h \
    location.h \
    chauffeur.h \
    fenetre.h

FORMS    += mainwindow.ui
