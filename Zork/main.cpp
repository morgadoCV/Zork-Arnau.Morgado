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
	int exit = 1,flag=0;
	char userinput[25];
	w.createWorld();
	printf("Welcome to What happened last night\n");
	printf("As you would know you are at Hogwarts, School of Witchcraft and Wizary. We found you unconscious last night on the top of the north tower's steps, we don't know what happened to you.. You are at the sickroom, you must investigate what\n happened to you, maybe a dark wizard is in the castle..\n\n");
	
	while (exit == 1)
	{
		flag=w.checkImput();
		if (flag == 0){ continue; }
		else{ exit = 0; }
	}
	printf("\nYou have quit.\n");


	system("pause");
	return 0;
}
