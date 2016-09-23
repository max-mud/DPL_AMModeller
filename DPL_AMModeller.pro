#-------------------------------------------------
#
# Project created by QtCreator 2011-11-15T13:29:30
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = opengl1
TEMPLATE = app


SOURCES += main.cpp\
    Scene.cpp \
    SceneObject.cpp \
    MainWindow.cpp \
    Template_MainWindow.cpp

HEADERS  += \
    Scene.h \
    SceneObject.h \
    MainWindow.h \
    Template_MainWindow.h

FORMS    += \
    Template_MainWindow.ui

RESOURCES += \
    shaders.qrc \
    icons.qrc
