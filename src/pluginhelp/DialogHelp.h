#ifndef DIALOGHELP_H
#define DIALOGHELP_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>

class DialogHelp : public QDialog
{
	Q_OBJECT
	
public:
	DialogHelp(QWidget *parent);
};

#endif // DIALOGHELP_H
