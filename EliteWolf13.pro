QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commondata.cpp \
    contestant.cpp \
    main.cpp \
    mainwindow.cpp \
    notation.cpp \
    phototoplayer.cpp \
    playbutton.cpp \
    rectbutton.cpp \
    sceneofvote.cpp \
    triangle.cpp \
    vote.cpp \
    welcome.cpp

HEADERS += \
    commondata.h \
    contestant.h \
    mainwindow.h \
    notation.h \
    phototoplayer.h \
    playbutton.h \
    rectbutton.h \
    sceneofvote.h \
    triangle.h \
    vote.h \
    welcome.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    mushroom.qrc
