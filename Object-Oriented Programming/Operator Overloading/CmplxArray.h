#ifndef CMPLXRRAY_H
#define CMPLXARRAY_H

#include <iostream>
#include"Class_Cmplx.h"

using namespace std;

class CmplxArray
{
public:
	CmplxArray(int size);
	CmplxArray(const CmplxArray& obj);
	~CmplxArray();
	int size() { return cmplxArrSize; }
	Cmplx& operator[](int);

private:
	Cmplx* pCA;
	int cmplxArrSize;
	void subError();
};

#endif
