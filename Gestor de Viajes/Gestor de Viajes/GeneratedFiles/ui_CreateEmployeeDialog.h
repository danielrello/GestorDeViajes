/********************************************************************************
** Form generated from reading UI file 'CreateEmployeeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEEMPLOYEEDIALOG_H
#define UI_CREATEEMPLOYEEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateEmployeeDialog
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
    QLineEdit *nameInput;
    QLineEdit *surnameInput;
    QLineEdit *emailInput;
    QCheckBox *isResidentCBox;
    QLabel *mailError;

    void setupUi(QDialog *CreateEmployeeDialog)
    {
        if (CreateEmployeeDialog->objectName().isEmpty())
            CreateEmployeeDialog->setObjectName(QString::fromUtf8("CreateEmployeeDialog"));
        CreateEmployeeDialog->resize(468, 300);
        layoutWidget = new QWidget(CreateEmployeeDialog);
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

        formLayoutWidget = new QWidget(CreateEmployeeDialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(70, 20, 271, 111));
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

        nameInput = new QLineEdit(formLayoutWidget);
        nameInput->setObjectName(QString::fromUtf8("nameInput"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameInput);

        surnameInput = new QLineEdit(formLayoutWidget);
        surnameInput->setObjectName(QString::fromUtf8("surnameInput"));

        formLayout->setWidget(1, QFormLayout::FieldRole, surnameInput);

        emailInput = new QLineEdit(formLayoutWidget);
        emailInput->setObjectName(QString::fromUtf8("emailInput"));

        formLayout->setWidget(2, QFormLayout::FieldRole, emailInput);

        isResidentCBox = new QCheckBox(formLayoutWidget);
        isResidentCBox->setObjectName(QString::fromUtf8("isResidentCBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, isResidentCBox);

        mailError = new QLabel(CreateEmployeeDialog);
        mailError->setObjectName(QString::fromUtf8("mailError"));
        mailError->setEnabled(true);
        mailError->setGeometry(QRect(80, 150, 271, 16));
        mailError->setInputMethodHints(Qt::ImhEmailCharactersOnly);
        mailError->raise();
        layoutWidget->raise();
        formLayoutWidget->raise();

        retranslateUi(CreateEmployeeDialog);
        QObject::connect(okButton, SIGNAL(clicked()), CreateEmployeeDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), CreateEmployeeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CreateEmployeeDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateEmployeeDialog)
    {
        CreateEmployeeDialog->setWindowTitle(QApplication::translate("CreateEmployeeDialog", "Dialog", nullptr));
        okButton->setText(QApplication::translate("CreateEmployeeDialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("CreateEmployeeDialog", "Cancel", nullptr));
        label->setText(QApplication::translate("CreateEmployeeDialog", "Name", nullptr));
        label_2->setText(QApplication::translate("CreateEmployeeDialog", "Surname", nullptr));
        label_3->setText(QApplication::translate("CreateEmployeeDialog", "Email", nullptr));
        isResidentCBox->setText(QApplication::translate("CreateEmployeeDialog", "Is a resident employee?", nullptr));
        mailError->setText(QApplication::translate("CreateEmployeeDialog", "<html><head/><body><p><span style=\" color:#ff0000;\">TextLabel</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateEmployeeDialog: public Ui_CreateEmployeeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEEMPLOYEEDIALOG_H
