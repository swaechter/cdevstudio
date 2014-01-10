#include "DialogAbout.h"

DialogAbout::DialogAbout(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
	textBrowserAbout->setText(Utils::getResourceText(":/data/text/about_about.html"));
	textBrowserLicense->setText(Utils::getResourceText(":/data/text/about_license.html"));
	textBrowserThanksto->setText(Utils::getResourceText(":/data/text/about_thanksto.html"));
}
