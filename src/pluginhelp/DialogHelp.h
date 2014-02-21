#ifndef DIALOGHELP_H
#define DIALOGHELP_H

#include <QtWidgets/QDialog>

class DialogHelp : public QDialog
{
	Q_OBJECT
	
public:
	DialogHelp(QWidget *parent);
	void setHelpText(const QString &text);
};

#endif // DIALOGHELP_H
