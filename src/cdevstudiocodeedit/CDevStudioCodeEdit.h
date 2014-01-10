#ifndef CDEVSTUDIOCODEEDIT_H
#define CDEVSTUDIOCODEEDIT_H

#include <QtWidgets/QTextEdit>

#include "CDevStudioCodeEditExport.h"

class CDEVSTUDIOCODEEDIT_API CDevStudioCodeEdit : public QTextEdit
{
	Q_OBJECT
	
public:
	CDevStudioCodeEdit(QWidget *parent);
	~CDevStudioCodeEdit();
	
private:
	struct Implementation;
	Implementation *implementation;
};

#endif // CDEVSTUDIOCODEEDIT_H
