#include "DialogAbout.h"

DialogAbout::DialogAbout(QWidget *parent, QString abouttext, QString licensetext, QString thankstotext) : QDialog(parent)
{
	setupUi(this);
}
