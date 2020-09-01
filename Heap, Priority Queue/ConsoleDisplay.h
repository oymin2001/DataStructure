#ifndef CONSOLE_DISPLAY_H
#define CONSOLE_DISPLAY_H
#include <Windows.h>
#include<iostream>

HANDLE consoleHandler;
HANDLE initConsoleHandler()
{
	HANDLE stdCnslHndlr;
	stdCnslHndlr =
		GetStdHandle(STD_OUTPUT_HANDLE);
	consoleHandler = stdCnslHndlr;
	return consoleHandler;
}
void closeConsoleHandler(HANDLE hndlr)
{
	CloseHandle(hndlr);
}
int gotoxy(HANDLE consoleHndlr, int x, int y) 
{
	if (consoleHndlr == INVALID_HANDLE_VALUE)
		return 0;
	COORD coords = { static_cast<short>(x),static_cast<short>(y) };
	SetConsoleCursorPosition(consoleHndlr, coords);
}

#endif // !CONSOLE_DISPLAY_H


#pragma once
