#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"room.h"
#include"player.h"
#include"world.h"
#include"exit.h"
using namespace std;

int World::checkImput()
{
	char userinput[25];
	printf("What do you wanna do?\n");
	gets_s(userinput);
	if (strcmp("go north", userinput) == 0)
	{
		moveNorth();
		return 0;
	}
	else if (strcmp("go south", userinput) == 0)
	{
		moveSouth();
		return 0;
	}
	else if (strcmp("go east", userinput) == 0)
	{
		moveEast();
		return 0;
	}
	else if (strcmp("go west", userinput) == 0)
	{
		moveWest();
		return 0;
	}
	else if (strcmp("look", userinput) == 0)
	{
		lookRooms();
		return 0;
	}
	else if (strcmp("help", userinput) == 0)
	{
		giveHelp();
		return 0;
	}
	else if (strcmp("quit", userinput) == 0)
	{
		return 1;
	}
	else if (strcmp("open", userinput) == 0)
	{
		openDoor();
		return 0;
	}
	else if (strcmp("close", userinput) == 0)
	{
		closeDoor();
		return 0;
	}
	else if (strcmp("talk parsel", userinput) == 0)
	{
		talkParsel();
		return 0;
	}
	else
	{
		printf("\nWrong command.Type 'help' if you need it.\n");
		return 0;
	}
}

void World::moveNorth(){
	if (my_player[0].situation == floor3)
	{
		my_player[0].situation = my_exits[floor3].destiny2;
		printf("\n%s%s\n\n", my_rooms[requirements].name, my_rooms[requirements].description);
		return;
	}
	else if (my_player[0].situation == floor2)
	{
		my_player[0].situation = my_exits[floor2].destiny;
		printf("\n%s%s\n", my_rooms[floor3].name, my_rooms[floor3].description);
		return;
	}
	else if (my_player[0].situation == floor1)
	{
		my_player[0].situation = my_exits[floor1].destiny;
		printf("\n%s%s\n", my_rooms[floor2].name, my_rooms[floor2].description);
		return;
	}
	else if (my_player[0].situation == lowlevel)
	{
		my_player[0].situation = my_exits[lowlevel].destiny;
		printf("\n%s%s\n", my_rooms[floor1].name, my_rooms[floor1].description);
		return;
	}
	else if (my_player[0].situation == secrets)
	{
		my_player[0].situation = my_exits[secrets].destiny;
		printf("\n%s%s\n", my_rooms[bathroom].name, my_rooms[bathroom].description);
		return;
	}
	else
	{
		printf("\nThere is a high wall you can't climb.\n\n");
		return;
	}
}

void World::moveSouth()
{
	if (my_player[0].situation == floor3)
	{
		my_player[0].situation = my_exits[floor3].destiny4;
		printf("\n%s%s\n", my_rooms[floor2].name, my_rooms[floor2].description);
		return;
	}
	else if (my_player[0].situation == requirements)
	{
		my_player[0].situation = my_exits[requirements].destiny;
		printf("\n%s%s\n", my_rooms[floor3].name, my_rooms[floor3].description);
		return;
	}
	else if (my_player[0].situation == floor2)
	{
		my_player[0].situation = my_exits[floor2].destiny2;
		printf("\n%s%s\n", my_rooms[floor1].name, my_rooms[floor1].description);
		return;
	}
	else if (my_player[0].situation == floor1)
	{
		my_player[0].situation = my_exits[floor1].destiny2;
		printf("\n%s%s\n", my_rooms[lowlevel].name, my_rooms[lowlevel].description);
		return;
	}
	else if (my_player[0].situation == bathroom)
	{
		if (openfountain == 1){
			my_player[0].situation = my_exits[bathroom].destiny;
			printf("\n%s%s\n", my_rooms[secrets].name, my_rooms[secrets].description);
			return;
		}
		if (openfountain == 0){
			printf("\nThere is a high wall you can't climb.\n\n");
			return;
		}
	}
	else
	{
		printf("\nThere is a high wall you can't climb.\n\n");
		return;
	}
	
}

void World::moveEast()
{
	if (my_player[0].situation == starting)
	{
		my_player[0].situation = my_exits[starting].destiny;
		printf("\n%s%s\n", my_rooms[floor3].name, my_rooms[floor3].description);
		return;
	}
	else if (my_player[0].situation == floor3)
	{
		if (door==1)
		{
			my_player[0].situation = my_exits[floor3].destiny3;
			printf("\n%s%s\n", my_rooms[darkarts].name, my_rooms[darkarts].description);
			return;
		}
		else if (door == 0)
		{
			printf("\nThe door is closed.\n");
		}
	}
	else if (my_player[0].situation == darkarts)
	{
		my_player[0].situation = my_exits[darkarts].destiny2;
		printf("\n%s%s\n", my_rooms[darkwizard].name, my_rooms[darkwizard].description);
		return;
	}
	else if (my_player[0].situation == floor2)
	{
		my_player[0].situation = my_exits[floor2].destiny3;
		printf("\n%s%s\n", my_rooms[bathroom].name, my_rooms[bathroom].description);
		return;
	}
	else if (my_player[0].situation == lowlevel)
	{
		my_player[0].situation = my_exits[lowlevel].destiny2;
		printf("\n%s%s\n", my_rooms[transformation].name, my_rooms[transformation].description);
		return;
	}
	else
	{
		printf("\nThere is a high wall you can't climb.\n\n");
		return;
	}
}
void World::moveWest()
{
	if (my_player[0].situation == floor3)
	{
		my_player[0].situation = my_exits[floor3].destiny;
		printf("\n%s%s\n", my_rooms[starting].name, my_rooms[starting].description);
		return;
	}
	else if (my_player[0].situation == darkarts)
	{
		if (door == 1)
		{
			my_player[0].situation = my_exits[darkarts].destiny;
			printf("\n%s%s\n", my_rooms[floor3].name, my_rooms[floor3].description);
			return;
		}
		else if (door == 0)
		{
			printf("\nThe door is closed.\n");
			return;
		}
	}
	
	else if (my_player[0].situation == darkwizard)
	{
		my_player[0].situation = my_exits[darkwizard].destiny;
		printf("\n%s%s\n", my_rooms[darkarts].name, my_rooms[darkarts].description);
		return;
	}
	else if (my_player[0].situation == bathroom)
	{
		my_player[0].situation = my_exits[bathroom].destiny2;
		printf("\n%s%s\n", my_rooms[floor2].name, my_rooms[floor2].description);
		return;
	}
	else if (my_player[0].situation == transformation)
	{
		my_player[0].situation = my_exits[transformation].destiny;
		printf("\n%s%s\n", my_rooms[lowlevel].name, my_rooms[lowlevel].description);
		return;
	}
	else
	{
		printf("\nThere is a high wall you can't climb.\n\n");
		return;
	}
}

void World::lookRooms()
{
	if (my_player[0].situation == starting) printf("\n%s\n", my_exits[starting].description); 
	else if (my_player[0].situation == floor3) printf("\n%s\n", my_exits[floor3].description); 
	else if (my_player[0].situation == transformation) printf("\n%s\n", my_exits[transformation].description); 
	else if (my_player[0].situation == darkarts) printf("\n%s\n", my_exits[darkarts].description); 
	else if (my_player[0].situation == darkwizard) printf("\n%s\n", my_exits[darkwizard].description); 
	else if (my_player[0].situation == floor2) printf("\n%s\n", my_exits[floor2].description); 
	else if (my_player[0].situation == floor1) printf("\n%s\n", my_exits[floor1].description); 
	else if (my_player[0].situation == lowlevel) printf("\n%s\n", my_exits[lowlevel].description); 
	else if (my_player[0].situation == requirements) printf("\n%s\n", my_exits[requirements].description); 
	else if (my_player[0].situation == bathroom) printf("\n%s\n", my_exits[bathroom].description); 
	else if (my_player[0].situation == secrets) printf("\n%s\n", my_exits[secrets].description); 
}

void World::giveHelp()
{
	system("cls");
	printf("\nUse command 'go north' to move North.\n");
	printf("\nUse command 'go south' to move South.\n");
	printf("\nUse command 'go east' to move East.\n");
	printf("\nUse command 'go west' to move West.\n");
	printf("\nUse command 'look' get info of the room you are in.\n");
	printf("\nUse command 'help' to get help.\n");
	printf("\nUse command 'open' to open closed doors.\n");
	printf("\nUse command 'close' to close the door you oppened.\n\n");
}

void World::openDoor()
{
	if (my_player[0].situation == floor3&&door==0)
	{
		printf("Door opened.\n");
		door = 1;
		
	}
	else if (my_player[0].situation == darkarts&&door==0)
	{
		printf("Door opened.\n");
		door = 1;

	}
	else
	{
		printf("\nAll doors are opened.\n");
		
	}
}

void World::closeDoor()
{
	if (my_player[0].situation == darkarts&&door==1){
		printf("The door is closed.\n");
		door = 0;
		
	}
	else if (my_player[0].situation == floor3&&door==1)
	{
		printf("The door is closed.\n");
		door = 0;

	}
	else
	{
		printf("\nYou can't close any door.\n");
		
	}
}

void World::talkParsel()
{
	if (my_player[0].situation==bathroom)
	{
		if (openfountain == 0){
			printf("\nThe fountain is moving...A door just opened on the fountain\n");
			openfountain = 1;
		}
		else
		{
			printf("\nNothing happened\n\n");
		}
	}
	else
	{
		printf("\nNothing happened\n\n");
	}
}