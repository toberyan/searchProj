#include(../../common/common.pri)

3RDPART_DIR = $$PWD/../3rdparty

HEADERS += \
    $$PWD/maincontroller/task/taskcommander.h \
    $$PWD/maincontroller/task/taskcommander_p.h \
    $$PWD/maincontroller/maincontroller.h \
    $$PWD/private/searchservice_p.h \
    $$3RDPART_DIR/fulltext/chineseanalyzer.h \
    $$3RDPART_DIR/fulltext/chinesetokenizer.h \
    $$PWD/searcher/fulltext/fulltextsearcher.h \
    $$PWD/searcher/fulltext/fulltextsearcher_p.h \
    $$PWD/searcher/abstractsearcher.h \
    $$PWD/utils/searchhelper.h \
    $$PWD/searchservice.h

SOURCES += \
    $$PWD/maincontroller/task/taskcommander.cpp \
    $$PWD/maincontroller/maincontroller.cpp \
    $$3RDPART_DIR/fulltext/chineseanalyzer.cpp \
    $$3RDPART_DIR/fulltext/chinesetokenizer.cpp \
    $$PWD/searcher/fulltext/fulltextsearcher.cpp \
    $$PWD/searcher/abstractsearcher.cpp \
    $$PWD/utils/searchhelper.cpp \
    $$PWD/searchservice.cpp

INCLUDEPATH += $$PWD/ \
                $$PWD/searcher

CONFIG += link_pkgconfig
PKGCONFIG += liblucene++ liblucene++-contrib docparser
LIBS += -lboost_system
