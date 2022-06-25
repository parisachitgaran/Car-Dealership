QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    buy_newcar.cpp \
    buy_usedcar.cpp \
    cancelbuy.cpp \
    findidcompany.cpp \
    insertcompany.cpp \
    insertcustomer.cpp \
    insertmanager.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    menureport.cpp \
    menusale.cpp \
    menuupdate.cpp \
    report_base_price.cpp \
    report_compani.cpp \
    report_customer.cpp \
    report_existingcar.cpp \
    report_manager.cpp \
    report_sale.cpp \
    sale.cpp \
    update_car.cpp \
    update_customer.cpp \
    update_manager.cpp

HEADERS += \
    buy_newcar.h \
    buy_usedcar.h \
    cancelbuy.h \
    findidcompany.h \
    insertcompany.h \
    insertcustomer.h \
    insertmanager.h \
    mainwindow.h \
    menu.h \
    menureport.h \
    menusale.h \
    menuupdate.h \
    report_base_price.h \
    report_compani.h \
    report_customer.h \
    report_existingcar.h \
    report_manager.h \
    report_sale.h \
    sale.h \
    update_car.h \
    update_customer.h \
    update_manager.h

FORMS += \
    buy_newcar.ui \
    buy_usedcar.ui \
    cancelbuy.ui \
    findidcompany.ui \
    insertcompany.ui \
    insertcustomer.ui \
    insertmanager.ui \
    mainwindow.ui \
    menu.ui \
    menureport.ui \
    menusale.ui \
    menuupdate.ui \
    report_base_price.ui \
    report_compani.ui \
    report_customer.ui \
    report_existingcar.ui \
    report_manager.ui \
    report_sale.ui \
    sale.ui \
    update_car.ui \
    update_customer.ui \
    update_manager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
