#-------------------------------------------------
#
# Project created by QtCreator 2018-01-09T10:18:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mode
TEMPLATE = app

INCLUDEPATH += ../include/

SOURCES += main.cpp\
        mainwindow.cpp \
    ../src/AnalyticHeightField.cpp \
    ../src/Array.cpp \
    ../src/Box.cpp \
    ../src/HeightField.cpp \
    ../src/Image.cpp \
    ../src/LayerField.cpp \
    ../src/Maillage.cpp \
    ../src/main.cpp \
    ../src/Noise.cpp \
    ../src/Render.cpp \
    ../src/Results.cpp \
    ../src/ScalarField.cpp \
    ../src/Vector.cpp

HEADERS  += mainwindow.h \
    ../include/AnalyticHeightField.h \
    ../include/Array.h \
    ../include/Box.h \
    ../include/HeightField.h \
    ../include/Image.h \
    ../include/LayerField.h \
    ../include/Maillage.h \
    ../include/Noise.h \
    ../include/Render.h \
    ../include/Results.h \
    ../include/ScalarField.h \
    ../include/Vector.h

FORMS    += mainwindow.ui
