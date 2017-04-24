TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    linkOp.c \
    linkseq.c \
    treeOp.c \
    linksearch.c \
    menu.c \
    fileOp.c \
    dataOp.c \
    treeseq.c \
    treesearch.c

HEADERS += \
    header.h \
    linkOp.h \
    treeOp.h \
    menu.h \
    fileOp.h

DISTFILES += \
    DATA/GTBL.dat

OTHER_FILES += \
    DATA/GTBL.dat
