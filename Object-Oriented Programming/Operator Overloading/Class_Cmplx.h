#ifndef CLASS_Cmplx_H
#define CLASS_Cmplx_H
#include <iostream>

using namespace std;

class Cmplx {
	friend ostream & operator << (ostream &, const Cmplx&);
	friend istream& operator >> (istream&, Cmplx&);
	friend class CmplxArray;
public:
	Cmplx(double real=0.0 ,double imagin=0.0);
	const Cmplx operator + (const Cmplx&);
	const Cmplx operator - (const Cmplx&);
	const Cmplx operator * (const Cmplx&);
	const Cmplx operator / (const Cmplx&);
	
private:
	double real;
	double imagine;
};
// 출력
ostream& operator<<(ostream& output, const Cmplx& c)
{
	output << "Complex(" << c.real << ", " << c.imagine << ")" << '\n';
	return output;
}
// 입력
istream& operator>>(istream& input, Cmplx& c)
{
	input >> c.real;
	input >> c.imagine;
	return input;
}




const Cmplx Cmplx:: operator + (const Cmplx&c) {
	Cmplx result;

	result.real = real + c.real;
	result.imagine = imagine + c.imagine;

	return result;
}
const Cmplx Cmplx:: operator - (const Cmplx& c) {
	Cmplx result;

	result.real = real - c.real;
	result.imagine = imagine - c.imagine;

	return result;
}
const Cmplx Cmplx:: operator * (const Cmplx& c) {
	Cmplx result;

	result.real = (real * c.real)-(imagine*c.imagine);
	result.imagine = (real * c.imagine) + (imagine * c.real);

	return result;
}
const Cmplx Cmplx:: operator / (const Cmplx& c) {
	Cmplx result;
	double denom;

	denom = c.real * c.real + c.imagine * c.imagine;
	result.real = ((real * c.real) + (imagine * c.imagine))/denom;
	result.imagine = ((real * c.imagine) - (imagine * c.real))/denom;

	return result;
}

#endif

