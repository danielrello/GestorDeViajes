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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
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
    QPushButton *travelManagerB;
    QPushButton *exitButton;
    QPushButton *employeeManagerB;
    QPushButton *importEmployeeButton;
    QPushButton *importTravelsButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *employeeCountLabel;
    QLabel *employeeCountLabel_2;

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
        travelManagerB = new QPushButton(gridLayoutWidget);
        travelManagerB->setObjectName(QString::fromUtf8("travelManagerB"));

        mainMenu->addWidget(travelManagerB, 2, 0, 1, 1);

        exitButton = new QPushButton(gridLayoutWidget);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));

        mainMenu->addWidget(exitButton, 5, 0, 1, 1);

        employeeManagerB = new QPushButton(gridLayoutWidget);
        employeeManagerB->setObjectName(QString::fromUtf8("employeeManagerB"));

        mainMenu->addWidget(employeeManagerB, 1, 0, 1, 1);

        importEmployeeButton = new QPushButton(gridLayoutWidget);
        importEmployeeButton->setObjectName(QString::fromUtf8("importEmployeeButton"));

        mainMenu->addWidget(importEmployeeButton, 3, 0, 1, 1);

        importTravelsButton = new QPushButton(gridLayoutWidget);
        importTravelsButton->setObjectName(QString::fromUtf8("importTravelsButton"));

        mainMenu->addWidget(importTravelsButton, 4, 0, 1, 1);

        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(210, 310, 160, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        employeeCountLabel = new QLabel(formLayoutWidget);
        employeeCountLabel->setObjectName(QString::fromUtf8("employeeCountLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, employeeCountLabel);

        employeeCountLabel_2 = new QLabel(formLayoutWidget);
        employeeCountLabel_2->setObjectName(QString::fromUtf8("employeeCountLabel_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, employeeCountLabel_2);

        GestordeViajesClass->setCentralWidget(centralWidget);

        retranslateUi(GestordeViajesClass);

        QMetaObject::connectSlotsByName(GestordeViajesClass);
    } // setupUi

    void retranslateUi(QMainWindow *GestordeViajesClass)
    {
        GestordeViajesClass->setWindowTitle(QApplication::translate("GestordeViajesClass", "GestordeViajes", nullptr));
        travelManagerB->setText(QApplication::translate("GestordeViajesClass", "Travels", nullptr));
        exitButton->setText(QApplication::translate("GestordeViajesClass", "Exit", nullptr));
        employeeManagerB->setText(QApplication::translate("GestordeViajesClass", "Employees", nullptr));
        importEmployeeButton->setText(QApplication::translate("GestordeViajesClass", "Import Employees", nullptr));
        importTravelsButton->setText(QApplication::translate("GestordeViajesClass", "Import Travels", nullptr));
        label_2->setText(QApplication::translate("GestordeViajesClass", "Travel Count", nullptr));
        label->setText(QApplication::translate("GestordeViajesClass", "Employee Count", nullptr));
        employeeCountLabel->setText(QApplication::translate("GestordeViajesClass", "TextLabel", nullptr));
        employeeCountLabel_2->setText(QApplication::translate("GestordeViajesClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestordeViajesClass: public Ui_GestordeViajesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTORDEVIAJES_H
