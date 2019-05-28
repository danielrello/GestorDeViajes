/********************************************************************************
** Form generated from reading UI file 'EmployeeProfileWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEEPROFILEWINDOW_H
#define UI_EMPLOYEEPROFILEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeeProfileWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *nameOutput;
    QLabel *label_2;
    QLabel *surnameOutput;
    QLabel *label_3;
    QLabel *emailOutput;
    QLabel *residentLabel;
    QPushButton *exportButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QTableWidget *tableWidget;
    QPushButton *backButton;

    void setupUi(QMainWindow *EmployeeProfileWindow)
    {
        if (EmployeeProfileWindow->objectName().isEmpty())
            EmployeeProfileWindow->setObjectName(QString::fromUtf8("EmployeeProfileWindow"));
        EmployeeProfileWindow->setEnabled(true);
        EmployeeProfileWindow->resize(601, 447);
        EmployeeProfileWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        EmployeeProfileWindow->setDocumentMode(false);
        centralwidget = new QWidget(EmployeeProfileWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(200, 80, 221, 81));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nameOutput = new QLabel(formLayoutWidget);
        nameOutput->setObjectName(QString::fromUtf8("nameOutput"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameOutput);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        surnameOutput = new QLabel(formLayoutWidget);
        surnameOutput->setObjectName(QString::fromUtf8("surnameOutput"));

        formLayout->setWidget(1, QFormLayout::FieldRole, surnameOutput);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        emailOutput = new QLabel(formLayoutWidget);
        emailOutput->setObjectName(QString::fromUtf8("emailOutput"));

        formLayout->setWidget(2, QFormLayout::FieldRole, emailOutput);

        residentLabel = new QLabel(formLayoutWidget);
        residentLabel->setObjectName(QString::fromUtf8("residentLabel"));

        formLayout->setWidget(3, QFormLayout::FieldRole, residentLabel);

        exportButton = new QPushButton(centralwidget);
        exportButton->setObjectName(QString::fromUtf8("exportButton"));
        exportButton->setGeometry(QRect(430, 80, 167, 23));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(120, 180, 391, 211));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        tableWidget = new QTableWidget(verticalLayoutWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        backButton = new QPushButton(verticalLayoutWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        verticalLayout->addWidget(backButton);

        EmployeeProfileWindow->setCentralWidget(centralwidget);

        retranslateUi(EmployeeProfileWindow);

        QMetaObject::connectSlotsByName(EmployeeProfileWindow);
    } // setupUi

    void retranslateUi(QMainWindow *EmployeeProfileWindow)
    {
        EmployeeProfileWindow->setWindowTitle(QApplication::translate("EmployeeProfileWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("EmployeeProfileWindow", "Name:", nullptr));
        nameOutput->setText(QApplication::translate("EmployeeProfileWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("EmployeeProfileWindow", "Surname:", nullptr));
        surnameOutput->setText(QApplication::translate("EmployeeProfileWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("EmployeeProfileWindow", "Email:", nullptr));
        emailOutput->setText(QApplication::translate("EmployeeProfileWindow", "TextLabel", nullptr));
        residentLabel->setText(QApplication::translate("EmployeeProfileWindow", "TextLabel", nullptr));
        exportButton->setText(QApplication::translate("EmployeeProfileWindow", "Export to PDF", nullptr));
        label_4->setText(QApplication::translate("EmployeeProfileWindow", "Employee Travels", nullptr));
        backButton->setText(QApplication::translate("EmployeeProfileWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeeProfileWindow: public Ui_EmployeeProfileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEEPROFILEWINDOW_H
