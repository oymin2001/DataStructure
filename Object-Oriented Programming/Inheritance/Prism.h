#ifndef Prism_H
#define Prism_H

#include<string>
#include"Triangle.h"

using namespace std;

class Prism :public Triangle
{
	friend ostream& operator<<(ostream& ostr, Prism& pr);
public:
	Prism();
	Prism(Position pos, int b, int pri_h, int tri_h, COLORS clr, string n);
	Prism(Prism& pr );
	virtual ~Prism();
	double getVolume();
	void print();
protected:
	int prsm_h;
};

#endif
