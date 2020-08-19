#ifndef TRIANGLE_H
#define TRIANGLE_H


#include<string>
#include"Shape.h"
using namespace std;

class Triangle : public Shape
{
	friend ostream& operator<<(ostream&, Triangle&);
public:
	Triangle();
	Triangle(Position pos, int b, int h, COLORS clr, string name);
	Triangle(Triangle& tr);
	~Triangle();
	double getArea();
	void draw();
	int getBase() { return base; };
	int getHeight() { return height; };
	void setBase(int b) { base = b; };
	void setHeight(int h) { height = h; };
protected:
	int base;
	int height;
};

#endif // !TRIANGLE_H
