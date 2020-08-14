#ifndef EXPANDABLE_ARRAY_CPP
#define EXPANDABLE_ARRPAY_CPP

#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

class ExpandableArray
{
public:
	ExpandableArray(const char name[]=""); // default constructor
	~ExpandableArray(); // default destructor
	int size() const { return n; }
	int capacity() const { return capa; }
	bool empty()const { return n == 0; }
	void print(ostream& fout);
	void reserve(int N);
	void insert(int i, double element);
	void erase(int i);
	double& at(int i);
	void set(int i, double element);
	const ExpandableArray operator=(const ExpandableArray rightSide);
	double& operator[](int i);
	void indexError(int wrongIndex);


private:
	char name[16];
	int capa;
	int n;
	double* dA;
};


#endif 

