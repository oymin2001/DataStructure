#include<iostream>
#include"Node.h"
#include"GenericDLinkedList.h"
#define NUM 10
using namespace std;


int main() 
{
	DLinkedList<int> dll_int;

	cout << "\n Current contents in the DLL: ";
	dll_int.printDLL();
	cout << '\n';

	for (int i = 0; i < NUM; i++)
	{
		dll_int.addFront(i);
		cout << "After addFront() : ";
		dll_int.printDLL();
	}
	cout << "\n Current contents in the DLL: ";
	dll_int.printDLL();
	cout << '\n';
	for (int i = 0; i < NUM; i++)
	{
		dll_int.removeFront();
		cout << "After removeFront() : ";
		dll_int.printDLL();
	}

}