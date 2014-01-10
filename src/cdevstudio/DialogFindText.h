#ifndef DIALOGFINDTEXT_H
#define DIALOGFINDTEXT_H

#include <QtWidgets/QDialog>

#include "ui_DialogFindText.h"

class DialogFindText : public QDialog, Ui::DialogFindText
{
	Q_OBJECT
	
public:
	DialogFindText(QWidget *parent);
};

#endif // DIALOGFINDTEXT_H
