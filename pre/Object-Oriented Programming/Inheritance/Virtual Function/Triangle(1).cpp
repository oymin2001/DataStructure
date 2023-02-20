#include<iostream>
#include"Triangle.h"

using namespace std;

Triangle::Triangle()
{
	cout << " Default constructor(Triangle).\n";
}

Triangle::Triangle(Position p, int b, int h, COLORS clr, string name)
	:Shape(p,clr,name),base(b),height(h)
{
	cout << " Constructor(Triangle).\n";
}
Triangle::Triangle(Triangle& tr)
	: Shape(tr.pos, tr.color, tr.name), base(tr.base), height(tr.height)
{
	cout << " Copy constructor(Triangle).\n";
}
Triangle::~Triangle()
{
	cout << " Destructor(Triangle).\n";
}
double Triangle::getArea()
{
	double a = 0.0;
	a = base*height / 2.0;
	return a;
}
void Triangle::draw() 
{
	cout << "Triangle:pos( " << pos.pos_x << ", " << pos.pos_y <<
		" ), base( " << base << " ), height( " << height;
	cout << " ), color( " << shapeColor[color] << " ), name( " << name <<
		"), area( " << getArea() << " )\n";
}
ostream& operator<<(ostream& ostr, Triangle& tr)
{
	ostr << "Triangle:pos( " << tr.pos.pos_x << ", " << tr.pos.pos_y <<
		" ), base( " << tr.base << " ), height( " << tr.height;
	ostr << " ), color( " << shapeColor[tr.color] << " ), name( " << tr.name <<
		"), area( " << tr.getArea() << " )"<<'\n';
	return ostr;
}
