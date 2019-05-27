#include "ModifyDialogClass.h"


ModifyDialogClass::ModifyDialogClass(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(accept()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void ModifyDialogClass::reject()
{
}

void ModifyDialogClass::accept()
{
}
