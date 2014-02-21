#ifndef CDEVSTUDIOACTION_H
#define CDEVSTUDIOACTION_H

#include <QtWidgets/QAction>

class CDevStudioAction : public QAction
{
	Q_OBJECT
	
public:
	CDevStudioAction(const QString &text, QWidget *parent);
	~CDevStudioAction();
};

#endif // CDEVSTUDIOACTION_H
