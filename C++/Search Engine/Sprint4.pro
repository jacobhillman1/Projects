TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    treenode.cpp \
    tests.cpp \
    dsstring.cpp \
    searchengine.cpp

HEADERS += \
    avltree.h \
    treenode.h \
    catch.hpp \
    DSvector.h \
    avlnode.h \
    DSString.h \
    word.h \
    article.h \
    searchengine.h \
    linkedlist.h

