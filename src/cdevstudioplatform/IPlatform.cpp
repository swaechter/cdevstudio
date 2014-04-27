#include "interfaces/IPlatform.h"

IPlatform *IPlatform::m_IPlatform = nullptr;

IPlatform::IPlatform(QObject *parent) : QObject(parent)
{
	qDebug() << "IPlatform::IPlatform";
	m_IPlatform = this;
}

IPlatform::~IPlatform()
{
	qDebug() << "IPlatform::I~Platform";
	m_IPlatform = nullptr;
}

IPlatform *IPlatform::getInstance()
{
	qDebug() << "IPlatform::getInstance";
	return m_IPlatform;
}
