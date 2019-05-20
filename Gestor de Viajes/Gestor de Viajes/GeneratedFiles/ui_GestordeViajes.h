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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestordeViajesClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GestordeViajesClass)
    {
        if (GestordeViajesClass->objectName().isEmpty())
            GestordeViajesClass->setObjectName(QString::fromUtf8("GestordeViajesClass"));
        GestordeViajesClass->resize(600, 400);
        menuBar = new QMenuBar(GestordeViajesClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        GestordeViajesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GestordeViajesClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GestordeViajesClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GestordeViajesClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GestordeViajesClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GestordeViajesClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GestordeViajesClass->setStatusBar(statusBar);

        retranslateUi(GestordeViajesClass);

        QMetaObject::connectSlotsByName(GestordeViajesClass);
    } // setupUi

    void retranslateUi(QMainWindow *GestordeViajesClass)
    {
        GestordeViajesClass->setWindowTitle(QApplication::translate("GestordeViajesClass", "GestordeViajes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GestordeViajesClass: public Ui_GestordeViajesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTORDEVIAJES_H
