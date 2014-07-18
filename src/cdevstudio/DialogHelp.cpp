#include "DialogHelp.h"

DialogHelp::DialogHelp(QWidget *parent, QString helptext) : QDialog(parent)
{
	setupUi(this);
	
	textEditHelp->setText(helptext);
}
