QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminlogin.cpp \
    admintools.cpp \
    college.cpp \
    database.cpp \
    graph.cpp \
    main.cpp \
    mainwindow.cpp \
    parser.cpp \
    traversals.cpp

HEADERS += \
    adminlogin.h \
    admintools.h \
    college.h \
    database.h \
    graph.h \
    mainwindow.h \
    parser.h \
    traversals.h \
    unordered_map.h

FORMS += \
    adminlogin.ui \
    admintools.ui \
    mainwindow.ui \
    traversals.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
