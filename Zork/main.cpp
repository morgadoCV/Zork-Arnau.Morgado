#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"world.h"
#include"room.h"
#include"world.h"
#include"exit.h"
#include"player.h"
#include"entity.h"
#include"myvector.h"
#include"friend.h"
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;


int main()
{
	
	World w;
	Friend f;
	int exit = 1,flag=0,tiime=0, move=0;
	srand(time(NULL));
	w.createWorld();
	printf("Welcome to What happened last night\n");
	printf("As you would know you are at Hogwarts, School of Witchcraft and Wizary. We found you unconscious last night on the top of the north tower's steps, we don't know what happened to you.. You are at the sickroom, you must investigate what\n happened to you, maybe a dark wizard is in the castle..\n\n");
	
	while (exit == 1)
	{
		tiime = GetTickCount();
		if (f.istalking() == false && tiime >= (move + 5555))
		{
			move = tiime;
			int room = rand() % 10+1;
			w.friendmove(room);
		}
		if (_kbhit())
		{
			flag = w.checkImput();
			if (flag == 0){ continue; }
			else if (flag == 1){ printf("\nYou have quit.\n"); exit = 0; }
			else if (flag == 2){ exit = 0; }
		}
		
	}
	printf("\nYou have quit.\n");
	



	system("pause");
	return 0;
}
