QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Assertion.cpp \
    CCheckBox.cpp \
    CClient.cpp \
    CCommunication.cpp \
    CE2Feedback.cpp \
    CExperimentData.cpp \
    CExperimentWidget.cpp \
    CFloatInput.cpp \
    CMessage.cpp \
    CParameterIdentificationData.cpp \
    CPlot.cpp \
    CPlotLine.cpp \
    CPushButton.cpp \
    CToggleButton.cpp \
    QCustomPlot.cpp \
    main.cpp \
    CMainWindow.cpp

HEADERS += \
    Assertion.h \
    CCheckBox.h \
    CClient.h \
    CCommunication.h \
    CE2Feedback.h \
    CExperimentData.h \
    CExperimentWidget.h \
    CFloatInput.h \
    CMainWindow.h \
    CMessage.h \
    CNulltype.h \
    CParameterIdentificationData.h \
    CPlot.h \
    CPlotLine.h \
    CPushButton.h \
    CToggleButton.h \
    EEvent.h \
    FrameworkConfiguration.h \
    Global.h \
    IEventCreator.h \
    QCustomPlot.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    TwoLink_DesktopApplication_V1.pro.user
