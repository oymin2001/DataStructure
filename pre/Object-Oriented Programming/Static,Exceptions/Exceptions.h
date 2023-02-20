#ifndef EXCEPTIONS_H
#define EXCEPTOONS_H

#include<string>
using namespace std;

class RuntimeException {
private:
	string errorMsg;
public:
	RuntimeException(const string& err) { errorMsg = err; }
	string getMessage() const { return errorMsg; }
};

class IndexOutOfBounds : public RuntimeException
{
public:
	IndexOutOfBounds(const string& err):RuntimeException(err){}
private:
};

class StackEmpty :public RuntimeException
{
public:
	StackEmpty(const string& err):RuntimeException(err){}
private:

};

class MathExecption : public RuntimeException
{
public:
	MathExecption(const string& err) :RuntimeException(err) {};
};
#endif 
