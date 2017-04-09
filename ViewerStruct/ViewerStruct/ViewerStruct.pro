#-------------------------------------------------
#
# Project created by QtCreator 2017-03-12T13:27:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ViewerStruct
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    actions.cpp \
    transformations.cpp \
    rotation.cpp \
    action_load.cpp \
    point.cpp \
    isometric.cpp \
    data_blueprint.cpp \
    data_real.cpp \
    form_scene.cpp \
    action_to_projection.cpp \
    deg_to_rad.cpp

HEADERS  += mainwindow.h \
    errors.h \
    actions.h \
    point.h \
    transformations.h \
    rotation.h \
    action_load.h \
    isometric.h \
    data_blueprint.h \
    data_real.h \
    form_scene.h \
    action_to_projection.h \
    data_move.h \
    data_scale.h \
    data_rotate.h \
    data_projection.h \
    deg_to_rad.h

FORMS    += mainwindow.ui
