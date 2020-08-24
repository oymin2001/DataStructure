
#include"Server.h"


Server::Server(string str_name):strName(str_name)
{}

int Server::getTurn()
{
	turn++;
	return turn;
}

bool Server::stillOpen()
{
	return nowOpen;
}

void Server::serveTask()
{
	if (nowOpen && lastServed < turn)
	{
		lastServed++;
		cout << strName << " now serving " << lastServed << '\n';
	}
	if (lastServed >= turn) // everyone served
		nowOpen = false;
}