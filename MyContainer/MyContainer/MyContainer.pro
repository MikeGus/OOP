TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    base_iterator.h \
    exceptions.h \
    matrix_iterator.h \
    const_matrix_iterator.h
