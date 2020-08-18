#include<iostream>
#include"Class_Cmplx.h"
#include"CmplxArray.h"

using namespace std;

int main()
{
	CmplxArray CMPLXES(4);

	cout << "\n Input real and imagine in double type: ";
	cin >> CMPLXES[0];
	cout << "CMPLXES[0]: " << CMPLXES[0] << '\n';

	cout << "\n Input real and imagine in double type: ";
	cin >> CMPLXES[1];
	cout << "CMPLXES[1]: " << CMPLXES[1] << '\n';

	CMPLXES[2] = CMPLXES[0] + CMPLXES[1];
	CMPLXES[3] = CMPLXES[0] - CMPLXES[1];

	cout << "CMPLXES[2]: " << CMPLXES[2] << '\n';
	cout << "CMPLXES[3]: " << CMPLXES[3] << '\n';


}