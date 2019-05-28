/********************************************************************************
** Form generated from reading UI file 'TravelWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELWINDOW_H
#define UI_TRAVELWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TravelWindowClass
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *addButton;
    QPushButton *modifyButton;
    QPushButton *deleteButton;
    QPushButton *backButton;

    void setupUi(QMainWindow *TravelWindowClass)
    {
        if (TravelWindowClass->objectName().isEmpty())
            TravelWindowClass->setObjectName(QString::fromUtf8("TravelWindowClass"));
        TravelWindowClass->resize(417, 482);
        centralwidget = new QWidget(TravelWindowClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 401, 241));
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

        backButton = new QPushButton(verticalLayoutWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setEnabled(true);

        verticalLayout->addWidget(backButton);

        TravelWindowClass->setCentralWidget(centralwidget);

        retranslateUi(TravelWindowClass);

        QMetaObject::connectSlotsByName(TravelWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *TravelWindowClass)
    {
        TravelWindowClass->setWindowTitle(QApplication::translate("TravelWindowClass", "Travel Management", nullptr));
        addButton->setText(QApplication::translate("TravelWindowClass", "Crear", nullptr));
        modifyButton->setText(QApplication::translate("TravelWindowClass", "Modificar", nullptr));
        deleteButton->setText(QApplication::translate("TravelWindowClass", "Eliminar", nullptr));
        backButton->setText(QApplication::translate("TravelWindowClass", "Atras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TravelWindowClass: public Ui_TravelWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELWINDOW_H
