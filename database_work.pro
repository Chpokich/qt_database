QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database_interface_for_user.cpp \
    database_interface_for_admin.cpp \
    input_user_name.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    database_interface_for_user.h \
    database_interface_for_admin.h \
    input_user_name.h \
    loginwindow.h \
    loginwindow.h \
    mainwindow.h

FORMS += \
    database_interface_for_user.ui \
    database_interface_for_admin.ui \
    input_user_name.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
