/********************************************************************************
** Form generated from reading UI file 'EmailLoginDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMAILLOGINDIALOG_H
#define UI_EMAILLOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_emailLoginDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userInput;
    QLineEdit *passwordInput;
    QLabel *label_3;

    void setupUi(QDialog *emailLoginDialog)
    {
        if (emailLoginDialog->objectName().isEmpty())
            emailLoginDialog->setObjectName(QString::fromUtf8("emailLoginDialog"));
        emailLoginDialog->resize(400, 300);
        layoutWidget = new QWidget(emailLoginDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 250, 351, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        spacerItem = new QSpacerItem(131, 31, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(spacerItem);

        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        hboxLayout->addWidget(okButton);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        formLayoutWidget = new QWidget(emailLoginDialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(50, 80, 291, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        userInput = new QLineEdit(formLayoutWidget);
        userInput->setObjectName(QString::fromUtf8("userInput"));

        formLayout->setWidget(0, QFormLayout::FieldRole, userInput);

        passwordInput = new QLineEdit(formLayoutWidget);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));

        formLayout->setWidget(1, QFormLayout::FieldRole, passwordInput);

        label_3 = new QLabel(emailLoginDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 30, 141, 16));

        retranslateUi(emailLoginDialog);
        QObject::connect(okButton, SIGNAL(clicked()), emailLoginDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), emailLoginDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(emailLoginDialog);
    } // setupUi

    void retranslateUi(QDialog *emailLoginDialog)
    {
        emailLoginDialog->setWindowTitle(QApplication::translate("emailLoginDialog", "Dialog", nullptr));
        okButton->setText(QApplication::translate("emailLoginDialog", "Login", nullptr));
        cancelButton->setText(QApplication::translate("emailLoginDialog", "Cancel", nullptr));
        label->setText(QApplication::translate("emailLoginDialog", "User", nullptr));
        label_2->setText(QApplication::translate("emailLoginDialog", "Password", nullptr));
        label_3->setText(QApplication::translate("emailLoginDialog", "Gmail SMTP Connection", nullptr));
    } // retranslateUi

};

namespace Ui {
    class emailLoginDialog: public Ui_emailLoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMAILLOGINDIALOG_H
