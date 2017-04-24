TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    tests.cpp \
    DSString.cpp \
    main.cpp \
    word.cpp

HEADERS += \
    catch.hpp \
    tests.h \
    DSString.h \
    DSvector.h \
    word.h

