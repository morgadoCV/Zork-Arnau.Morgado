#include"exit.h"

Exit::Exit(const char* str1, const char*str2, int a, int b, int c, int d) :Entity(str1, str2)
{
	destiny = a;//east
	destiny2 = b;//west
	destiny3 = c;//north
	destiny4 = d;//south
}

Exit::~Exit()
{
}