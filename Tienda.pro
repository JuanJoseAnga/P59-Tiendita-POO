QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acerca.cpp \
    factura.cpp \
    main.cpp \
    principal.cpp \
    producto.cpp

HEADERS += \
    acerca.h \
    factura.h \
    principal.h \
    producto.h

FORMS += \
    acerca.ui \
    factura.ui \
    principal.ui

TRANSLATIONS += \
    principal_ca.ts \
    principal_it.ts \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Material.qrc

DISTFILES += \
    Material/klipartz.com (3).png \
    Material/klipartz.com (3).png
