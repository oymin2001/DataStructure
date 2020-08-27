#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include<string>
using namespace std;

class RuntimeException {
private:
	string errorMsg;
public:
	RuntimeException(const string& err) { errorMsg = err; }
	string getMessage() const { return errorMsg; }
};

class StackEmpty :public RuntimeException
{
public:
	StackEmpty(const string&err):RuntimeException(err){}
private:

};
class StackFull :public RuntimeException
{
public:
	StackFull(const string&err):RuntimeException(err){}
private:

};
class DequeEmpty :public RuntimeException
{
public:
	DequeEmpty(const string& err) :RuntimeException(err) {}
private:

};

#endif // !EXCEPTIONS_H
#pragma once
