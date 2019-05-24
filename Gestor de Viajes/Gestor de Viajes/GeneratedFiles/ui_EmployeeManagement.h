/********************************************************************************
** Form generated from reading UI file 'EmployeeManagement.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEMANAGEMENT_H
#define UI_EMPLOYEEMANAGEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeManagementClass
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addButton;
    QPushButton *modifyButton;
    QPushButton *deleteButton;
    QPushButton *addTravelButton;
    QPushButton *backButton;
    QLabel *label;
    QLabel *selectedEmployeeL;

    void setupUi(QMainWindow *EmployeeManagementClass)
    {
        if (EmployeeManagementClass->objectName().isEmpty())
            EmployeeManagementClass->setObjectName(QString::fromUtf8("EmployeeManagementClass"));
        EmployeeManagementClass->resize(417, 482);
        centralwidget = new QWidget(EmployeeManagementClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(80, 60, 256, 192));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(140, 280, 160, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        addButton = new QPushButton(verticalLayoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        verticalLayout->addWidget(addButton);

        modifyButton = new QPushButton(verticalLayoutWidget);
        modifyButton->setObjectName(QString::fromUtf8("modifyButton"));
        modifyButton->setEnabled(false);

        verticalLayout->addWidget(modifyButton);

        deleteButton = new QPushButton(verticalLayoutWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        deleteButton->setEnabled(false);

        verticalLayout->addWidget(deleteButton);

        addTravelButton = new QPushButton(verticalLayoutWidget);
        addTravelButton->setObjectName(QString::fromUtf8("addTravelButton"));
        addTravelButton->setEnabled(false);

        verticalLayout->addWidget(addTravelButton);

        backButton = new QPushButton(verticalLayoutWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setEnabled(true);

        verticalLayout->addWidget(backButton);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 290, 101, 16));
        selectedEmployeeL = new QLabel(centralwidget);
        selectedEmployeeL->setObjectName(QString::fromUtf8("selectedEmployeeL"));
        selectedEmployeeL->setGeometry(QRect(20, 330, 47, 13));
        EmployeeManagementClass->setCentralWidget(centralwidget);

        retranslateUi(EmployeeManagementClass);

        QMetaObject::connectSlotsByName(EmployeeManagementClass);
    } // setupUi

    void retranslateUi(QMainWindow *EmployeeManagementClass)
    {
        EmployeeManagementClass->setWindowTitle(QApplication::translate("EmployeeManagementClass", "EmployeeManagment", nullptr));
        addButton->setText(QApplication::translate("EmployeeManagementClass", "Crear", nullptr));
        modifyButton->setText(QApplication::translate("EmployeeManagementClass", "Modificar", nullptr));
        deleteButton->setText(QApplication::translate("EmployeeManagementClass", "Eliminar", nullptr));
        addTravelButton->setText(QApplication::translate("EmployeeManagementClass", "A\303\261adir Viaje", nullptr));
        backButton->setText(QApplication::translate("EmployeeManagementClass", "Atras", nullptr));
        label->setText(QApplication::translate("EmployeeManagementClass", "Selected Employee", nullptr));
        selectedEmployeeL->setText(QApplication::translate("EmployeeManagementClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeManagementClass: public Ui_EmployeeManagementClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEMANAGEMENT_H
