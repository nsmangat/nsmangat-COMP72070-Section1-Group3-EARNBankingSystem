QT       += core gui
QT       += network

INCLUDEPATH += "../EARNNetworkAPI"
DEFINES += _CRT_SECURE_NO_WARNINGS
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../EARNNetworkAPI/DataTypes.cpp \
    ../EARNNetworkAPI/EARNStructs.cpp \
    ../EARNNetworkAPI/Packet.cpp \
    ../EARNNetworkAPI/EARNLogger.cpp \
    main.cpp \
    clientapp.cpp

HEADERS += \
    ../EARNNetworkAPI/DataTypes.h \
    ../EARNNetworkAPI/EARNLogger.h \
    ../EARNNetworkAPI/EARNStructs.h \
    ../EARNNetworkAPI/Packet.h \
    ../EARNNetworkAPI/EARNLogger.h \
    ../EARNNetworkAPI/EARNStructs.h \
    clientapp.h

FORMS += \
    clientapp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
