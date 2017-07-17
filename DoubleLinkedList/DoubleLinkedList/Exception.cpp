//****Brandon Walter*****
#include "Exception.h"
#include <iostream>


using namespace std;

Exception::Exception()
{
	m_msg = nullptr;
}

Exception::Exception(char * msg)
{
	this->m_msg = msg;
}

Exception::Exception(const Exception & copy)
{
	if (copy.m_msg)
		this->m_msg = copy.m_msg;
}

Exception::~Exception()
{
}

Exception & Exception::operator=(const Exception & rhs)
{
	if (this == &rhs)
		return *this;

	delete[] this->m_msg;

	if (rhs.m_msg)
	{
		this->m_msg = rhs.m_msg;
	}

	return *this;
}

const char * Exception::getMessage()
{
	return this->m_msg;
}

void Exception::setMessage(char * msg)
{
	delete[] m_msg;
	this->m_msg = msg;
}

ostream & operator<<(ostream & stream, const Exception & except)
{
	stream << except.m_msg;
	return stream;
}