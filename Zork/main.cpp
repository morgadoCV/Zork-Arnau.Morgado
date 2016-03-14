#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"world.h"
#include"room.h"
#include"world.h"
#include"exit.h"
using namespace std;


int main()
{
	
	World w;
	int exit = 1;
	char userinput[25];
	w.createWorld();
	printf("Welcome to What happened last night\n");
	
	while (exit == 1)
	{
		w.checkImput();
	}


	system("pause");
	return 0;
}
