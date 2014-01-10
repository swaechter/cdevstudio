#ifndef DIALOGREPLACETEXT_H
#define DIALOGREPLACETEXT_H

#include <QtWidgets/QDialog>

#include "ui_DialogReplaceText.h"

class DialogReplaceText : public QDialog, Ui::DialogReplaceText
{
	Q_OBJECT
	
public:
	DialogReplaceText(QWidget *parent);
};

#endif // DIALOGREPLACETEXT_H
