#include<iostream>
#include"Prism.h"
#include<string>

using namespace std;

Prism::Prism()
{
	cout << " Default constructor(Prism).\n";
}

Prism::Prism(Position p, int b, int tri_h,int pri_h, COLORS clr, string n)
	:Triangle(pos,b, tri_h, clr,n), prsm_h(pri_h)
{
	cout << " Constructor("<<name<<").\n";
}
Prism::Prism(Prism&pr)
	: Triangle(pr.pos, pr.color, pr.height,pr.color,pr.name),prsm_h(pr.prsm_h)
{
	cout << " Copy constructor(Prism).\n";
}
Prism::~Prism()
{
	cout << " Destructor(Prism).\n";
}

double Prism::getVolume()
{
	double v = 0.0;
	v = base * height * prsm_h / 2.0;
	return v;
}

void Prism::print()
{
	cout << "Prism:pos( " << pos.pos_x << ", " << pos.pos_y <<
		" ), base( " << base << " ), height( " << height;
	cout << " ), color( " << shapeColor[color] << " ), name( " << name <<
		"), volume( " << getVolume() << " )\n";
}

ostream& operator<<(ostream& ostr, Prism& pr)
{
	ostr << "Prism:pos( " << pr.pos.pos_x << ", " << pr.pos.pos_y <<
		" ), base( " << pr.base << " ), height( " << pr.height;
	ostr << " ), color( " << shapeColor[pr.color] << " ), name( " << pr.name <<
		"), volume( " << pr.getVolume() << " )\n";
	
	return ostr;
}
