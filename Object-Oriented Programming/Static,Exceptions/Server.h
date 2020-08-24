#ifndef SERVER_H
#define SERVER_H
#include <iostream>
#include<string>

using namespace std;

class Server
{
public:
	Server(string str_name);
	static int getTurn();
	void serveTask();
	static bool stillOpen();

private:
	static int turn;
	static int lastServed;
	static bool nowOpen;
	string strName;
};


#endif // !SERVER_H
