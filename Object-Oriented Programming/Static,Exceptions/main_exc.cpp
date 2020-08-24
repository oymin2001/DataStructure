#include<iostream>
#include"Exceptions.h"

using namespace std;

int main()
{
	try {
		throw IndexOutOfBounds("Index out of bounds");
	}
	catch (IndexOutOfBounds& idx)
	{
		cout << "Exception occured: " << idx.getMessage();
		cout << '\n';
	}
	try {
		throw StackEmpty("StackEmpty");
	}
	catch (StackEmpty& stk)
	{
		cout << "Exception occured: " << stk.getMessage();
		cout << '\n';
	}
	try {
		throw MathExecption("Math Exception ");
	}
	catch (MathExecption& math)
	{
		cout << "Exception occured: " << math.getMessage();
		cout << '\n';
	}
}