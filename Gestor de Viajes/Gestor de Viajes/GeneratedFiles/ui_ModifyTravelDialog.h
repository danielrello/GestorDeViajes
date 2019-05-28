/********************************************************************************
** Form generated from reading UI file 'ModifyTravelDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYTRAVELDIALOG_H
#define UI_MODIFYTRAVELDIALOG_H

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

class Ui_ModifyTravelDialog
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
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *departureLocation;
    QLineEdit *arrivalLocation;
    QLineEdit *costInput;
    QDateTimeEdit *arrivalTime;
    QDateTimeEdit *departureTime;

    void setupUi(QDialog *ModifyTravelDialog)
    {
        if (ModifyTravelDialog->objectName().isEmpty())
            ModifyTravelDialog->setObjectName(QString::fromUtf8("ModifyTravelDialog"));
        ModifyTravelDialog->resize(400, 300);
        layoutWidget = new QWidget(ModifyTravelDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(300, 20, 77, 106));
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

        formLayoutWidget = new QWidget(ModifyTravelDialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(29, 19, 261, 221));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        departureLocation = new QLineEdit(formLayoutWidget);
        departureLocation->setObjectName(QString::fromUtf8("departureLocation"));

        formLayout->setWidget(0, QFormLayout::FieldRole, departureLocation);

        arrivalLocation = new QLineEdit(formLayoutWidget);
        arrivalLocation->setObjectName(QString::fromUtf8("arrivalLocation"));

        formLayout->setWidget(1, QFormLayout::FieldRole, arrivalLocation);

        costInput = new QLineEdit(formLayoutWidget);
        costInput->setObjectName(QString::fromUtf8("costInput"));

        formLayout->setWidget(4, QFormLayout::FieldRole, costInput);

        arrivalTime = new QDateTimeEdit(formLayoutWidget);
        arrivalTime->setObjectName(QString::fromUtf8("arrivalTime"));

        formLayout->setWidget(3, QFormLayout::FieldRole, arrivalTime);

        departureTime = new QDateTimeEdit(formLayoutWidget);
        departureTime->setObjectName(QString::fromUtf8("departureTime"));

        formLayout->setWidget(2, QFormLayout::FieldRole, departureTime);


        retranslateUi(ModifyTravelDialog);
        QObject::connect(okButton, SIGNAL(clicked()), ModifyTravelDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), ModifyTravelDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ModifyTravelDialog);
    } // setupUi

    void retranslateUi(QDialog *ModifyTravelDialog)
    {
        ModifyTravelDialog->setWindowTitle(QApplication::translate("ModifyTravelDialog", "Modify Travel", nullptr));
        okButton->setText(QApplication::translate("ModifyTravelDialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("ModifyTravelDialog", "Cancel", nullptr));
        label->setText(QApplication::translate("ModifyTravelDialog", "Departure Location", nullptr));
        label_2->setText(QApplication::translate("ModifyTravelDialog", "Arrival Location", nullptr));
        label_3->setText(QApplication::translate("ModifyTravelDialog", "Departure Time", nullptr));
        label_4->setText(QApplication::translate("ModifyTravelDialog", "Arrival Time", nullptr));
        label_5->setText(QApplication::translate("ModifyTravelDialog", "Cost", nullptr));
        arrivalTime->setDisplayFormat(QApplication::translate("ModifyTravelDialog", "yyyy/mm/dd HH:mm", nullptr));
        departureTime->setDisplayFormat(QApplication::translate("ModifyTravelDialog", "yyyy/mm/dd HH:mm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyTravelDialog: public Ui_ModifyTravelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYTRAVELDIALOG_H
