/********************************************************************************
** Form generated from reading UI file 'database_interface.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASE_INTERFACE_H
#define UI_DATABASE_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_database_interface
{
public:
    QPushButton *pushButton;

    void setupUi(QDialog *database_interface)
    {
        if (database_interface->objectName().isEmpty())
            database_interface->setObjectName("database_interface");
        database_interface->resize(648, 430);
        pushButton = new QPushButton(database_interface);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(230, 150, 171, 111));

        retranslateUi(database_interface);

        QMetaObject::connectSlotsByName(database_interface);
    } // setupUi

    void retranslateUi(QDialog *database_interface)
    {
        database_interface->setWindowTitle(QCoreApplication::translate("database_interface", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("database_interface", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class database_interface: public Ui_database_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASE_INTERFACE_H
