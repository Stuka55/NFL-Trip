QT       += core gui sql multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clickablelabel.cpp \
    data.cpp \
    executetrip.cpp \
    graphalgorithmviewwidget.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    monke.cpp \
    spfileparser.cpp \
    stadium.cpp \
    team.cpp \
    tripplanner.cpp \
    tripsummary.cpp \
    user.cpp \
    team_souvenir.cpp

HEADERS += \
    AdjacencyList.h \
    clickablelabel.h \
    data.h \
    delegators.h \
    executetrip.h \
    graphalgorithmviewwidget.h \
    login.h \
    mainwindow.h \
    map.h \
    monke.h \
    spfileparser.h \
    stadium.h \
    team.h \
    tripplanner.h \
    tripsummary.h \
    user.h \
    team_souvenir.h

FORMS += \
    executetrip.ui \
    graphalgorithmviewwidget.ui \
    login.ui \
    mainwindow.ui \
    monke.ui \
    tripplanner.ui \
    tripsummary.ui

TRANSLATIONS += \
    sp_NFLProject_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    Resources.qrc
