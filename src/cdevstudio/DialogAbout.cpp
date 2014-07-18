#include "DialogAbout.h"

DialogAbout::DialogAbout(QWidget *parent, QString abouttext, QString licensetext, QString thankstotext) : QDialog(parent)
{
	setupUi(this);
	
	textBrowserAbout->setText(abouttext);
	textBrowserLicense->setText(licensetext);
	textBrowserThanksTo->setText(thankstotext);
}
