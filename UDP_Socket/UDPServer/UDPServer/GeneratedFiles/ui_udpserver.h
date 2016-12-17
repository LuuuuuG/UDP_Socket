/********************************************************************************
** Form generated from reading UI file 'udpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPSERVER_H
#define UI_UDPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UDPServerClass
{
public:

    void setupUi(QWidget *UDPServerClass)
    {
        if (UDPServerClass->objectName().isEmpty())
            UDPServerClass->setObjectName(QStringLiteral("UDPServerClass"));
        UDPServerClass->resize(600, 400);

        retranslateUi(UDPServerClass);

        QMetaObject::connectSlotsByName(UDPServerClass);
    } // setupUi

    void retranslateUi(QWidget *UDPServerClass)
    {
        UDPServerClass->setWindowTitle(QApplication::translate("UDPServerClass", "UDPServer", 0));
    } // retranslateUi

};

namespace Ui {
    class UDPServerClass: public Ui_UDPServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPSERVER_H
