/********************************************************************************
** Form generated from reading UI file 'TravelProfileWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELPROFILEWINDOW_H
#define UI_TRAVELPROFILEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TravelProfileWindow
{
public:
    QWidget *centralwidget;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *departureLocation;
    QLabel *label_2;
    QLabel *arrivalLocation;
    QLabel *label_3;
    QLabel *departureTime;
    QLabel *arrivalTime;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *cost;
    QPushButton *backButton;

    void setupUi(QMainWindow *TravelProfileWindow)
    {
        if (TravelProfileWindow->objectName().isEmpty())
            TravelProfileWindow->setObjectName(QString::fromUtf8("TravelProfileWindow"));
        TravelProfileWindow->setEnabled(true);
        TravelProfileWindow->resize(601, 447);
        TravelProfileWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        TravelProfileWindow->setDocumentMode(false);
        centralwidget = new QWidget(TravelProfileWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(160, 90, 351, 191));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        departureLocation = new QLabel(formLayoutWidget);
        departureLocation->setObjectName(QString::fromUtf8("departureLocation"));

        formLayout->setWidget(0, QFormLayout::FieldRole, departureLocation);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        arrivalLocation = new QLabel(formLayoutWidget);
        arrivalLocation->setObjectName(QString::fromUtf8("arrivalLocation"));

        formLayout->setWidget(1, QFormLayout::FieldRole, arrivalLocation);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        departureTime = new QLabel(formLayoutWidget);
        departureTime->setObjectName(QString::fromUtf8("departureTime"));

        formLayout->setWidget(2, QFormLayout::FieldRole, departureTime);

        arrivalTime = new QLabel(formLayoutWidget);
        arrivalTime->setObjectName(QString::fromUtf8("arrivalTime"));

        formLayout->setWidget(3, QFormLayout::FieldRole, arrivalTime);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_6);

        cost = new QLabel(formLayoutWidget);
        cost->setObjectName(QString::fromUtf8("cost"));

        formLayout->setWidget(4, QFormLayout::FieldRole, cost);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));
        backButton->setGeometry(QRect(210, 300, 75, 23));
        TravelProfileWindow->setCentralWidget(centralwidget);

        retranslateUi(TravelProfileWindow);

        QMetaObject::connectSlotsByName(TravelProfileWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TravelProfileWindow)
    {
        TravelProfileWindow->setWindowTitle(QApplication::translate("TravelProfileWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("TravelProfileWindow", "Departure Location", nullptr));
        departureLocation->setText(QApplication::translate("TravelProfileWindow", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("TravelProfileWindow", "Arrival Location", nullptr));
        arrivalLocation->setText(QApplication::translate("TravelProfileWindow", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("TravelProfileWindow", "Departure Time", nullptr));
        departureTime->setText(QApplication::translate("TravelProfileWindow", "TextLabel", nullptr));
        arrivalTime->setText(QApplication::translate("TravelProfileWindow", "TextLabel", nullptr));
        label_5->setText(QApplication::translate("TravelProfileWindow", "Arrival Time", nullptr));
        label_6->setText(QApplication::translate("TravelProfileWindow", "Cost", nullptr));
        cost->setText(QApplication::translate("TravelProfileWindow", "TextLabel", nullptr));
        backButton->setText(QApplication::translate("TravelProfileWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TravelProfileWindow: public Ui_TravelProfileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELPROFILEWINDOW_H
