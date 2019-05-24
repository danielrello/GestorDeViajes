/********************************************************************************
** Form generated from reading UI file 'GestordeViajes.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTORDEVIAJES_H
#define UI_GESTORDEVIAJES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestordeViajesClass
{
public:
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *mainMenu;
    QPushButton *exitButton;
    QPushButton *travelManagerB;
    QPushButton *employeeManagerB;

    void setupUi(QMainWindow *GestordeViajesClass)
    {
        if (GestordeViajesClass->objectName().isEmpty())
            GestordeViajesClass->setObjectName(QString::fromUtf8("GestordeViajesClass"));
        GestordeViajesClass->resize(600, 400);
        centralWidget = new QWidget(GestordeViajesClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(140, 80, 301, 201));
        mainMenu = new QGridLayout(gridLayoutWidget);
        mainMenu->setSpacing(6);
        mainMenu->setContentsMargins(11, 11, 11, 11);
        mainMenu->setObjectName(QString::fromUtf8("mainMenu"));
        mainMenu->setContentsMargins(0, 0, 0, 0);
        exitButton = new QPushButton(gridLayoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        mainMenu->addWidget(exitButton, 3, 0, 1, 1);

        travelManagerB = new QPushButton(gridLayoutWidget);
        travelManagerB->setObjectName(QString::fromUtf8("travelManagerB"));

        mainMenu->addWidget(travelManagerB, 2, 0, 1, 1);

        employeeManagerB = new QPushButton(gridLayoutWidget);
        employeeManagerB->setObjectName(QString::fromUtf8("employeeManagerB"));

        mainMenu->addWidget(employeeManagerB, 1, 0, 1, 1);

        GestordeViajesClass->setCentralWidget(centralWidget);

        retranslateUi(GestordeViajesClass);

        QMetaObject::connectSlotsByName(GestordeViajesClass);
    } // setupUi

    void retranslateUi(QMainWindow *GestordeViajesClass)
    {
        GestordeViajesClass->setWindowTitle(QApplication::translate("GestordeViajesClass", "GestordeViajes", nullptr));
        exitButton->setText(QApplication::translate("GestordeViajesClass", "Exit", nullptr));
        travelManagerB->setText(QApplication::translate("GestordeViajesClass", "Travels", nullptr));
        employeeManagerB->setText(QApplication::translate("GestordeViajesClass", "Employees", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestordeViajesClass: public Ui_GestordeViajesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTORDEVIAJES_H
