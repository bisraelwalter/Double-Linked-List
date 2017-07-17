//****Brandon Walter*****
#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <ostream>
#endif

using namespace std;

class Exception
{
private:
	char *m_msg;

public:
	Exception();
	Exception(char *msg);
	Exception(const Exception &copy);
	~Exception();
	Exception &operator=(const Exception &rhs);
	const char* getMessage();
	void setMessage(char *msg);
	friend ostream &operator<<(ostream &stream, const Exception &except);
};
