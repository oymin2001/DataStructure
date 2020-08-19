#include<iostream>
#include<string>
#include<fstream>
#include"Shape.h"
#include"Triangle.h"
#include"Prism.h"

using namespace std;

int main()
{
	ofstream fout;
	Shape s1(Position(1,2), BLACK, "Shape_s1");
	Triangle t1(Position(1, 2),3, 4, RED, "Traingle_t1"), t2;
	Prism p1(Position(4, 5), 6, 7, 8, BLUE, "Prism_p1"), p2;

	fout.open("Output.txt");
	if(fout.fail())
	{
		cout << "Fail to open an input file (Outfut.txt)\n";
		exit(1);
	}
	fout << s1;
	fout << t1;
	fout << p1;

	fout.close();
	return 0;

}