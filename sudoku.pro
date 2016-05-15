#-------------------------------------------------
#
# Project created by QtCreator 2016-05-14T13:16:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sudoku
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    btn.cpp \
    ball.cpp \
    score.cpp \
    timecounter.cpp

HEADERS  += mainwindow.h \
    scene.h \
    btn.h \
    ball.h \
    score.h \
    timecounter.h

FORMS    += mainwindow.ui

RESOURCES += \
    pics.qrc
