#include "HelpDialog.h"

HelpDialog::HelpDialog(QWidget *parent, QString helptext) : QDialog(parent)
{
	setupUi(this);
	
	textEditHelp->setText(helptext);
}
