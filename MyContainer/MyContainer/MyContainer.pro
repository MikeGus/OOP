TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    matrix.cpp \
    base_iterator.cpp \
    allocation.cpp

HEADERS += \
    matrix.h \
    base_iterator.h \
    allocation.h \
    exceptions.h
