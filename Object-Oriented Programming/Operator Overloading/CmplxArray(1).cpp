#include "CmplxArray.h"
#include"Class_Cmplx.h"

CmplxArray::CmplxArray(int size)
{
	cmplxArrSize = size;
	pCA = new Cmplx[size];
	for (int i = 0; i < size; i++)
	{
	    pCA[i].real = 0.0;
		pCA[i].imagine = 0.0;
	}
}

CmplxArray::CmplxArray(const CmplxArray& obj)
{
	cmplxArrSize = obj.cmplxArrSize;
	pCA = new Cmplx[cmplxArrSize];
	for (int i = 0; i < cmplxArrSize; i++)
	{
		*(pCA + i) = obj.pCA[i];
	}
}

CmplxArray::~CmplxArray()
{
	if (cmplxArrSize > 0)
		delete[]pCA;
}
void CmplxArray::subError()
{
	cout << "Error: Subscript out of range. \n";
	exit(0);
}
Cmplx& CmplxArray::operator[](int sub)
{
	if (sub > 0 || sub >= cmplxArrSize)
		subError();
	return pCA[sub];
}


