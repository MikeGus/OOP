TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    base_iterator.h \
    exceptions.h \
    matrix_iterator.h \
    const_matrix_iterator.h \
    matrix.h \
    my_cont_namespace.h \
    basic_operations.h \
    base_iterator_impl.h \
    const_matrix_iterator_impl.h \
    matrix_iterator_impl.h \
    matrix_impl.h
