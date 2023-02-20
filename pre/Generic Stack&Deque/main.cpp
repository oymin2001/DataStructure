#include<iostream>
#include"GenricArrayStack.h"
#include"GenericDLL.h"
#include"GenericLinkedDeque.h"
using namespace std;


int main()
{
	ArrayStack<int> int_stack;

	int_stack.push(7);
	int_stack.push(13);
	cout << int_stack.top() << '\n';
	cout << "Current status of int_stack: " << '\n'; 
	int_stack.print();
	cout << '\n';

	ArrayStack<string> str_stack;
	str_stack.push("Bob");
	str_stack.push("Alice");
	cout << str_stack.top() << '\n';
	str_stack.pop();
	str_stack.push("Eve");
	cout << "Current status of str_stack: " << '\n'; 
	str_stack.print();
	cout << '\n';
	cout << "\n";

	LinkedDeque<int> int_DeQ;
	int data;
	int num_data = 5;
	try {
		cout << "Testing int_Queue" << '\n';
		for (int i = 0; i < num_data; i++)
		{
			int_DeQ.insertBack(i);
			cout << "After insertBack (";
			cout << setw(3) << i << ") :";
			int_DeQ.printDeQ();
		}
		for (int i = 0; i < num_data; i++)
		{
			int_DeQ.insertFront(i + 10);
			cout << "After insertFront (";
			cout << setw(3) << i + 10 << ") :";
			int_DeQ.printDeQ();
		}
		cout << '\n';
		for (int i = 0; i < num_data; i++)
		{
			data = int_DeQ.front_DeQ();
			cout << "Remove ("<<data;
			cout << ") from front of Int_DeQ\n";
			int_DeQ.removeFront();
			cout << "After removeFront() :";
			int_DeQ.printDeQ();
		}
		for (int i = 0; i < num_data; i++)
		{
			data = int_DeQ.back_DeQ();
			cout << "Remove (" << data;
			cout << ") from back of Int_DeQ\n";
			int_DeQ.removeBack();
			cout << "After removeBack() :";
			int_DeQ.printDeQ();
		}
		cout << '\n';
	}
	catch (DequeEmpty& deQ_exception)
	{
		cout << "\n!! Exception occured: " << deQ_exception.getMessage();
		cout << '\n';
	}
}