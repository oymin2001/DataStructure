#include<iostream>
#include<string.h>
#include"ExpandableArray.cpp"
#define NUM_EA 10
#define NUM_EB 5

using namespace std;




int main()
{
    int n;
    double d = 0;
    ExpandableArray eA("eA"), eB("eB"), eC("eC");

    for (int i = 0; i < NUM_EA; i++,d+=2)
    {
        eA.insert(i, d);
    }
    cout << "Contents of eA: ";
    eA.print(cout);
    cout << "Capacity of eA= " << eA.capacity() << '\n';
    cout << "Configuring eB with " << NUM_EB * 3 << " elements ..." << '\n';
    for (int i = 0,d=0.0; i < NUM_EB*3; i++,d+=2.2)
    {
        eB.insert(i, d);
    }
    eC = eA = eB;
    cout << "Capacity of after eA=eB: " << eA.capacity() << '\n';
    cout << "Contents of eA (after assignment): ";
    eA.print(cout);
    cout << "Capacity of after eC=eA=eB: " << eC.capacity() << '\n';
    cout << "Current size of eC = " << eC.size() << '\n';
    cout << "Contents of eC (after assignment): " << '\n';
    for (int i = 0; i < eC.size(); i++)
    {
        cout << eC[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < eC.size(); i++)
    {
        eC[i] *= 2;
    }
    eC.print(cout);
}

