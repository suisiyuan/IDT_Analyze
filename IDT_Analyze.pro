#-------------------------------------------------
#
# Project created by QtCreator 2016-10-24T20:51:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IDT_Analyze
TEMPLATE = app

INCLUDEPATH +=  src

SOURCES +=  src/main.cpp\
            src/MainWindow.cpp

HEADERS +=  src/MainWindow.h\
			src/app.h

FORMS   +=  ui/main.ui


RESOURCES += res.qrc
RC_FILE = res.rc


CONFIG(release, debug|release) {
    UI_DIR = release
    RCC_DIR = release
    MOC_DIR = release
    OBJECTS_DIR = release
} else {
    UI_DIR = debug
    RCC_DIR = debug
    MOC_DIR = debug
    OBJECTS_DIR = debug
}
