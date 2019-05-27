/********************************************************************************
** Form generated from reading UI file 'EmployeeWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEWINDOW_H
#define UI_EMPLOYEEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeWindowClass
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

    void setupUi(QMainWindow *EmployeeWindowClass)
    {
        if (EmployeeWindowClass->objectName().isEmpty())
            EmployeeWindowClass->setObjectName(QString::fromUtf8("EmployeeWindowClass"));
        EmployeeWindowClass->resize(417, 482);
        centralwidget = new QWidget(EmployeeWindowClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 401, 241));
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

        EmployeeWindowClass->setCentralWidget(centralwidget);

        retranslateUi(EmployeeWindowClass);

        QMetaObject::connectSlotsByName(EmployeeWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *EmployeeWindowClass)
    {
        EmployeeWindowClass->setWindowTitle(QApplication::translate("EmployeeWindowClass", "EmployeeManagment", nullptr));
        addButton->setText(QApplication::translate("EmployeeWindowClass", "Crear", nullptr));
        modifyButton->setText(QApplication::translate("EmployeeWindowClass", "Modificar", nullptr));
        deleteButton->setText(QApplication::translate("EmployeeWindowClass", "Eliminar", nullptr));
        addTravelButton->setText(QApplication::translate("EmployeeWindowClass", "A\303\261adir Viaje", nullptr));
        backButton->setText(QApplication::translate("EmployeeWindowClass", "Atras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeWindowClass: public Ui_EmployeeWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEWINDOW_H
