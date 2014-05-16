#ifndef DIALOGABOUT_H
#define DIALOGABOUT_H

#include <QtWidgets/QDialog>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>

class DialogAbout : public QDialog
{
	Q_OBJECT
	
public:
	DialogAbout(QWidget *parent);
};

#endif // DIALOGABOUT_H
