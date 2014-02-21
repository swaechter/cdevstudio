#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include <QtWidgets/QDialog>

class DialogAbout : public QDialog
{
	Q_OBJECT
	
public:
	DialogAbout(QWidget *parent);
	void setAboutText(const QString &text);
	void setLicenseText(const QString &text);
	void setThankstoText(const QString &text);
};

#endif // DIALOGABOUT_H
