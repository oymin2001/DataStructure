#include<iostream>
#include"Shape.h"

using namespace std;
const char* shapeColor[] = {"RED","BLUE","BLACK","ORANGE" };
Shape::Shape()
{
	cout << " Default constructor (Shape).\n";
}
Shape::Shape(Position p, COLORS c, string n)
	:pos(p), color(c), name(n)
{
	cout << " Constructor (Shape).\n";
}
Shape::~Shape()
{
	cout << " Destructor (Shape).\n";
}
void Shape::draw()
{
	cout << " Draw Shape: pos( " << pos.pos_x << ", " << pos.pos_y << " ), color( " <<
		shapeColor[color] << " ), name( " << name << " )\n";
}
ostream& operator<<(ostream& ostr, Shape& S)
{
	ostr << " Draw Shape: pos( " << S.pos.pos_x << ", " << S.pos.pos_y << " ), color( " <<
		shapeColor[S.color] << " ), name( " << S.name << " )\n";
	return ostr;
}
