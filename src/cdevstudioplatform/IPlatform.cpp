#include "IPlatform.h"

IPlatform *IPlatform::m_IPlatform = 0;

IPlatform::IPlatform(QObject *parent) : QObject(parent)
{
	m_IPlatform = this;
}

IPlatform::~IPlatform()
{
	m_IPlatform = 0;
}

IPlatform *IPlatform::getInstance()
{
	return m_IPlatform;
}
