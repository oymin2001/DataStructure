#include<iostream>
#include<cstdlib>
using namespace std;

class IntPair 
{
public:
	IntPair(int firstValue, int secondValue);
	IntPair operator ++(); //prefix, y=++x 
	IntPair operator ++(int); // postfix , y=x++
	void setFirst(int newValue);
	void setSecond(int newValue);
	int getFirst() const;
	int getSecond() const;

private:
	int first;
	int second;

};


IntPair::IntPair(int firstValue, int secondValue)
	:first(firstValue),second(secondValue)
{ }
IntPair IntPair::operator ++(int ignoreMe)
{
	int tmp1 = first;
	int tmp2 = second;
	first++;
	second++;
	return IntPair(tmp1, tmp2);
}
IntPair IntPair::operator++()
{
	first++;
	second++;
	return IntPair(first, second);
}


void IntPair::setFirst(int newValue)
{
	first = newValue;
}
void IntPair::setSecond(int newValue)
{
	second = newValue;
}
int IntPair::getFirst() const
{
	return first;
}
int IntPair::getSecond() const
{
	return second;
}




int main()
{
	IntPair a(1, 2);
	cout << "Start value of object a: ";
	cout << a.getFirst() << " " << a.getSecond() << '\n';
	cout << "After postfix b=a++;\n b= ";
	IntPair b = a++;
	cout << b.getFirst() << " " << b.getSecond() << '\n';
	cout << "a= ";
	cout << a.getFirst() << " " << a.getSecond() << '\n';


	a=IntPair(1, 2);
	cout << "Start value of object a: ";
	cout << a.getFirst() << " " << a.getSecond() << '\n';
	cout << "After prefix c=++a;\n c= ";
	IntPair c = ++a;
	cout << c.getFirst() << " " << c.getSecond() << '\n';
	cout << "a= ";
	cout << a.getFirst() << " " << a.getSecond() << '\n';
}