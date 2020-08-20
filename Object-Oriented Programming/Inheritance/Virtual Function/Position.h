#ifndef POSITION_H
#define POSITION_H


typedef struct Position
{
	int pos_x;
	int pos_y;
	Position(int x, int y)
	{
		pos_x = x; pos_y = y;
	};
	Position() { pos_x = 0; pos_y = 0; };

}Position;




#endif // !POSITION_H
