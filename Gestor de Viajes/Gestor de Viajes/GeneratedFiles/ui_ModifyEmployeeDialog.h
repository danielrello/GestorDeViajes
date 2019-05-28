/********************************************************************************
** Form generated from reading UI file 'ModifyEmployeeDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYEMPLOYEEDIALOG_H
#define UI_MODIFYEMPLOYEEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModifyEmployeeDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *vboxLayout;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QSpacerItem *spacerItem;
    QLineEdit *nameInput;
    QLabel *nameLabel;
    QLabel *surnameLabel;
    QLineEdit *surnameInput;
    QLabel *emailLabel;
    QLineEdit *emailInput;

    void setupUi(QDialog *ModifyEmployeeDialog)
    {
        if (ModifyEmployeeDialog->objectName().isEmpty())
            ModifyEmployeeDialog->setObjectName(QString::fromUtf8("ModifyEmployeeDialog"));
        ModifyEmployeeDialog->resize(400, 300);
        layoutWidget = new QWidget(ModifyEmployeeDialog);
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

        nameInput = new QLineEdit(ModifyEmployeeDialog);
        nameInput->setObjectName(QString::fromUtf8("nameInput"));
        nameInput->setGeometry(QRect(80, 20, 113, 20));
        nameLabel = new QLabel(ModifyEmployeeDialog);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(30, 20, 47, 13));
        surnameLabel = new QLabel(ModifyEmployeeDialog);
        surnameLabel->setObjectName(QString::fromUtf8("surnameLabel"));
        surnameLabel->setGeometry(QRect(30, 60, 47, 13));
        surnameInput = new QLineEdit(ModifyEmployeeDialog);
        surnameInput->setObjectName(QString::fromUtf8("surnameInput"));
        surnameInput->setGeometry(QRect(80, 60, 113, 20));
        emailLabel = new QLabel(ModifyEmployeeDialog);
        emailLabel->setObjectName(QString::fromUtf8("emailLabel"));
        emailLabel->setGeometry(QRect(30, 100, 47, 13));
        emailInput = new QLineEdit(ModifyEmployeeDialog);
        emailInput->setObjectName(QString::fromUtf8("emailInput"));
        emailInput->setGeometry(QRect(80, 100, 113, 20));

        retranslateUi(ModifyEmployeeDialog);
        QObject::connect(okButton, SIGNAL(clicked()), ModifyEmployeeDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), ModifyEmployeeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ModifyEmployeeDialog);
    } // setupUi

    void retranslateUi(QDialog *ModifyEmployeeDialog)
    {
        ModifyEmployeeDialog->setWindowTitle(QApplication::translate("ModifyEmployeeDialog", "Dialog", nullptr));
        okButton->setText(QApplication::translate("ModifyEmployeeDialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("ModifyEmployeeDialog", "Cancel", nullptr));
        nameInput->setInputMask(QString());
        nameInput->setText(QString());
        nameLabel->setText(QApplication::translate("ModifyEmployeeDialog", "<html><head/><body><p>Name:</p></body></html>", nullptr));
        surnameLabel->setText(QApplication::translate("ModifyEmployeeDialog", "<html><head/><body><p>Surname:</p></body></html>", nullptr));
        emailLabel->setText(QApplication::translate("ModifyEmployeeDialog", "<html><head/><body><p>Email:</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModifyEmployeeDialog: public Ui_ModifyEmployeeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYEMPLOYEEDIALOG_H
