TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    tests.cpp \
    origcity.cpp \
    destcity.cpp \
    flightplanner.cpp \
    flightpath.cpp \
    dsstring.cpp

DISTFILES += \
    Sprint2.pro.user \
    Sprint02.md

HEADERS += \
    catch.hpp \
    linkedlist.h \
    queue.h \
    stack.h \
    origcity.h \
    destcity.h \
    flightplanner.h \
    flightpath.h \
    DSString.h \
    DSvector.h

