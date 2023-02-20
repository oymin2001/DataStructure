#include<iostream>
#include"Server.h"
using namespace std;

int Server::turn = 0;
int Server::lastServed = 0;
bool Server::nowOpen = true;

int main()
{
	Server s1("server_A"), s2("server_B");
	int num, cnt;
	do {
		cout << "Number of persons in your group?";
		cin >> num;
		cout << "Your turns ard: ";
		for (cnt = 0; cnt < num; cnt++)
			cout << Server::getTurn() << " ";
		cout << '\n';
		s1.serveTask();
		s2.serveTask();
	} while (Server::stillOpen());
	cout << "Now closing service ...\n";
	return 0;
}