#include<iostream>
#include"template_sort.cpp"

using namespace std;


int main() 
{
	int a[3] = { 2,1,3 };
	sort(a, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << a[i]<<' ';
	}
	cout << '\n';
	double b[3] = { 5.1,2.2,3.1 };
	sort(b, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << b[i] << ' ';
	}
	cout << '\n';
	char c[3] = { 'C','A','E' };
	sort(c, 3);
	for (int i = 0; i < 3; i++)
	{
		cout << c[i] << ' ';
	}
	cout << '\n';
}