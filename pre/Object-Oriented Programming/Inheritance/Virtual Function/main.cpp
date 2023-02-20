#include<iostream>
#include<string>
#include<fstream>
#include"Shape.h"
#include"Triangle.h"
#include"Prism.h"
#define NUM_SHAPES 2

using namespace std;

int main()
{
	cout << "\n=====\n";
	cout << "Step 0: ... :" << '\n';
	Shape* pShapes[NUM_SHAPES];
	Triangle tri;
	Prism pri;
	cout << "\n=====\n";
	cout << "Step 1: ... " << '\n';
	tri=Triangle(Position(1, 2), 3, 4, RED, "Traingle");
	pri = Prism(Position(4, 5), 6, 7, 8, BLUE, "Prism");
	cout << "\n=====\n";
	cout << "Step 2: ..." << '\n';
	pShapes[0] = &tri;
	pShapes[1] = &pri;
	cout << "\n=====\n";
	cout << "Step 3: ..." << '\n';
	for (int i = 0; i < NUM_SHAPES; i++)
	{
		pShapes[i]->draw();
	}

}