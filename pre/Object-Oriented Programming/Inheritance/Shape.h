#ifndef SHAPE_H
#define SHAPE_H


#include<string>
#include"Position.h"
using namespace std;
enum COLORS{RED,BLUE,BLACK,ORANGE};
extern const char* shapeColor[];

class Shape
{
	friend ostream& operator<<(ostream& S, Shape&);
public:
	Shape();
	Shape(Position p, COLORS color, string name);
	virtual ~Shape();
	void draw();
	Position getPosition() { return pos; }
	void setPosition(Position p)
	{
		pos.pos_x = p.pos_x;
		pos.pos_y = p.pos_y;
	}
	COLORS getColor() { return color; }
	void setColor(COLORS c) { color = c; }

protected:
	Position pos;
	COLORS color;
	string name;
};

#endif // !SHAPE_H
