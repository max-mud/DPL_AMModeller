#-------------------------------------------------
#
# Project created by QtCreator 2011-11-15T13:29:30
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = opengl1
TEMPLATE = app


SOURCES += main.cpp\
        Scene_template.cpp \
    Scene.cpp \
    SceneObject.cpp

HEADERS  += Scene_template.h \
    Scene.h \
    SceneObject.h

FORMS    += Scene_template.ui

RESOURCES += \
    shaders.qrc
