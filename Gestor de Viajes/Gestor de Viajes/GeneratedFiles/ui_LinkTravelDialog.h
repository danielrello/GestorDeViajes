/********************************************************************************
** Form generated from reading UI file 'LinkTravelDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINKTRAVELDIALOG_H
#define UI_LINKTRAVELDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LinkTravelDialog
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
    QLabel *nameOutput;
    QLabel *label_2;
    QLabel *surnameOutput;
    QLabel *label_3;
    QLabel *emailOutput;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QComboBox *comboBox;

    void setupUi(QDialog *LinkTravelDialog)
    {
        if (LinkTravelDialog->objectName().isEmpty())
            LinkTravelDialog->setObjectName(QString::fromUtf8("LinkTravelDialog"));
        LinkTravelDialog->resize(400, 300);
        layoutWidget = new QWidget(LinkTravelDialog);
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

        formLayoutWidget = new QWidget(LinkTravelDialog);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(100, 30, 160, 101));
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

        formLayoutWidget_2 = new QWidget(LinkTravelDialog);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(30, 160, 321, 41));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        comboBox = new QComboBox(formLayoutWidget_2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboBox);


        retranslateUi(LinkTravelDialog);
        QObject::connect(okButton, SIGNAL(clicked()), LinkTravelDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), LinkTravelDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LinkTravelDialog);
    } // setupUi

    void retranslateUi(QDialog *LinkTravelDialog)
    {
        LinkTravelDialog->setWindowTitle(QApplication::translate("LinkTravelDialog", "Link Travel", nullptr));
        okButton->setText(QApplication::translate("LinkTravelDialog", "OK", nullptr));
        cancelButton->setText(QApplication::translate("LinkTravelDialog", "Cancel", nullptr));
        label->setText(QApplication::translate("LinkTravelDialog", "Name", nullptr));
        nameOutput->setText(QApplication::translate("LinkTravelDialog", "TextLabel", nullptr));
        label_2->setText(QApplication::translate("LinkTravelDialog", "Surname", nullptr));
        surnameOutput->setText(QApplication::translate("LinkTravelDialog", "TextLabel", nullptr));
        label_3->setText(QApplication::translate("LinkTravelDialog", "Email", nullptr));
        emailOutput->setText(QApplication::translate("LinkTravelDialog", "TextLabel", nullptr));
        label_4->setText(QApplication::translate("LinkTravelDialog", "Select Travel to link", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LinkTravelDialog: public Ui_LinkTravelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINKTRAVELDIALOG_H
