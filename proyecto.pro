#-------------------------------------------------
#
# Project created by QtCreator 2013-06-05T17:47:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = proyecto
TEMPLATE = app


SOURCES += main.cpp\
        sudoku.cpp \
    ventanaprincipal.cpp \
    guardarsudoku.cpp \
    cargarsudoku.cpp

HEADERS  += sudoku.h \
    ventanaprincipal.h \
    guardarsudoku.h \
    cargarsudoku.h

FORMS    += sudoku.ui \
    ventanaprincipal.ui \
    guardarsudoku.ui \
    cargarsudoku.ui
