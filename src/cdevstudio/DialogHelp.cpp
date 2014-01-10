#include "DialogHelp.h"

DialogHelp::DialogHelp(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
	textBrowserHelp->setText(Utils::getResourceText(":/data/text/help.html"));
}
