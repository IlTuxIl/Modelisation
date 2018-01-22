#-------------------------------------------------
#
# Project created by QtCreator 2018-01-05T15:11:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Modelisation
TEMPLATE = app

INCLUDEPATH += ../../include/

SOURCES += main.cpp\
        mainwindow.cpp \
    ../AnalyticHeightField.cpp \
    ../Array.cpp \
    ../Box.cpp \
    ../HeightField.cpp \
    ../Image.cpp \
    ../LayerField.cpp \
    ../Maillage.cpp \
    ../Noise.cpp \
    ../ScalarField.cpp \
    ../Vector.cpp \
    ../Foret.cpp \
    ../Veget.cpp

HEADERS  += mainwindow.h \
    ../../include/AnalyticHeightField.h \
    ../../include/Array.h \
    ../../include/Box.h \
    ../../include/HeightField.h \
    ../../include/Image.h \
    ../../include/LayerField.h \
    ../../include/Maillage.h \
    ../../include/Noise.h \
    ../../include/ScalarField.h \
    ../../include/Vector.h \
    ../../include/Veget.h \
    ../../include/Foret.h

FORMS    += mainwindow.ui

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x
