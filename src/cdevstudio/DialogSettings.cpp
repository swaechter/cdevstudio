#include "DialogSettings.h"

DialogSettings::DialogSettings(QWidget *parent) : QDialog(parent)
{
	setupUi(this);
}

void DialogSettings::addLanguage(const QString &language)
{
	comboBoxLanguage->addItem(language);
}

void DialogSettings::setSelectedLanguage(const QString &language)
{
	comboBoxLanguage->setCurrentText(language);
}

QString DialogSettings::getSelectedLanguage()
{
	return comboBoxLanguage->currentText();
}
