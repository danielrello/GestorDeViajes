/********************************************************************************
** Form generated from reading UI file 'CreateTravelClass.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETRAVELCLASS_H
#define UI_CREATETRAVELCLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateTravelDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *vboxLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *spacerItem;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *departureLocation;
    QLabel *label_2;
    QLineEdit *arrivalLocation;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QDateTimeEdit *departureTime;
    QDateTimeEdit *arrivalTime;
    QLineEdit *costInput;

    void setupUi(QDialog *CreateTravelDialog)
    {
        if (CreateTravelDialog->objectName().isEmpty())
            CreateTravelDialog->setObjectName(QString::fromUtf8("CreateTravelDialog"));
        CreateTravelDialog->resize(468, 300);
        layoutWidget = new QWidget(CreateTravelDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(360, 20, 77, 106));
        vboxLayout = new QVBoxLayout(layoutWidget);
        vboxLayout->setSpacing(6);
        vboxLayout->setObjectName(QString::fromUtf8("vboxLayout"));
        vboxLayout->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        vboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        vboxLayout->addWidget(cancelButton);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        vboxLayout->addItem(spacerItem);

        formLayoutWidget = new QWidget(CreateTravelDialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 20, 321, 126));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        departureLocation = new QLineEdit(formLayoutWidget);
        departureLocation->setObjectName(QString::fromUtf8("departureLocation"));

        formLayout->setWidget(0, QFormLayout::FieldRole, departureLocation);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        arrivalLocation = new QLineEdit(formLayoutWidget);
        arrivalLocation->setObjectName(QString::fromUtf8("arrivalLocation"));

        formLayout->setWidget(1, QFormLayout::FieldRole, arrivalLocation);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        departureTime = new QDateTimeEdit(formLayoutWidget);
        departureTime->setObjectName(QString::fromUtf8("departureTime"));

        formLayout->setWidget(2, QFormLayout::FieldRole, departureTime);

        arrivalTime = new QDateTimeEdit(formLayoutWidget);
        arrivalTime->setObjectName(QString::fromUtf8("arrivalTime"));

        formLayout->setWidget(3, QFormLayout::FieldRole, arrivalTime);

        costInput = new QLineEdit(formLayoutWidget);
        costInput->setObjectName(QString::fromUtf8("costInput"));

        formLayout->setWidget(4, QFormLayout::FieldRole, costInput);


        retranslateUi(CreateTravelDialog);
        QObject::connect(okButton, SIGNAL(clicked()), CreateTravelDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), CreateTravelDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateTravelDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateTravelDialog)
    {
        CreateTravelDialog->setWindowTitle(QApplication::translate("CreateTravelDialog", "Create Travel", nullptr));
        okButton->setText(QApplication::translate("CreateTravelDialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("CreateTravelDialog", "Cancel", nullptr));
        label->setText(QApplication::translate("CreateTravelDialog", "Departure Location", nullptr));
        label_2->setText(QApplication::translate("CreateTravelDialog", "Arrival Location", nullptr));
        label_3->setText(QApplication::translate("CreateTravelDialog", "Departure Time", nullptr));
        label_4->setText(QApplication::translate("CreateTravelDialog", "Arrival Time", nullptr));
        label_5->setText(QApplication::translate("CreateTravelDialog", "Cost", nullptr));
        departureTime->setDisplayFormat(QApplication::translate("CreateTravelDialog", "yyyy/mm/dd HH:mm", nullptr));
        arrivalTime->setDisplayFormat(QApplication::translate("CreateTravelDialog", "yyyy/mm/dd HH:mm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateTravelDialog: public Ui_CreateTravelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETRAVELCLASS_H
