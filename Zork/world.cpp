#include<stdio.h>
#include<string.h>
#include"room.h"
#include"player.h"
#include"world.h"
#include"exit.h"
#include"entity.h"
#include"mystring.h"
using namespace std;


//constructor&&deconstructor
World::World(const char* str1,const char* str2) :Entity(str1,str2)
{

} 
World::World()
{

}

World::~World()
{
}

//createworld
void World::createWorld()
{
	//player
	player.push_back(new Player("Unknown", "As you would know you are at Hogwarts, School of Witchcraft and Wizary.We found you unconscious last night on the top of the north tower's steps, we don't know what happened to you..\n You are at the sickroom, you must investigate what happened to you, maybe a dark wizard is in the castle..",0));
	
	
	//rooms
	rooms.push_back(new Room("Starting Room.\n", "You can see a room when you look at east.There is a broom."));
	rooms.push_back(new Room("3rd Floor.\n", "There are stair going down on south and a closed room east, it seems very cold.\n"));
	rooms.push_back(new Room("2nd floor.\n", "You can go east to the bathroom and south downstairs to 1st floor.\nThere is a lantern on the floor.\n"));
	rooms.push_back(new Room("Dark arts room.\n", "There is an old painting of Salazar Slytherin. You can also see a wand over the table and a heavy layer behind the door.\n"));
	rooms.push_back(new Room("1st floor.\n", "There is a layer on the floor. The only way you can go is south, straight to the low level.\n"));
	rooms.push_back(new Room("Low Level.\n", "You can only go east, to the transformation room.\n"));
	rooms.push_back(new Room("Room of requirements.\n", "Wait..Where are you? You can see a book over a table."));
	rooms.push_back(new Room("Bathroom\n", "You found your friend Arnau. There is an old fountain with what seem snakes \narround it.\n"));
	rooms.push_back(new Room("Chamber of Secrets.\n", "There is a BASILISK.There is also a book on the floor.\n"));
	rooms.push_back(new Room("Transformation room.\n", "There is a sword next to the table.\n"));
	rooms.push_back(new Room("Dark wizard room.\n", "Is there a room here? Since when? A wizard is staring at you with his wand on \nthe right hand.\n"));

	
	 //exits
	exits.push_back(new Exit("", "East to 3rd Floor.\n", 1, 11, 11, 11));//starting 0
	exits.push_back(new Exit("", "East to Dark arts room, south to 2nd Floor, west to the Starting Room.\n",3, 0, 6, 2));//3rdFloor 1
	exits.push_back(new Exit("", "East to Bathroom, south to 1st Floor, north to 3rd Floor.\n", 7, 11, 1, 4));//2ndFloor 2
	exits.push_back(new Exit("", "West to 3rd Floor.\n",10 ,1 ,11 ,11 ));//darkarts 3
	exits.push_back(new Exit("", "South to Low Level, north to 2nd Floor.\n", 11, 11, 2, 5 ));//1stFloor 4
	exits.push_back(new Exit("", "East to the Transformation room, north to 1st Floor.\n", 9,11 ,4 ,11 ));//lowlevel 5
	exits.push_back(new Exit("", "South to 3rd Floor.\n", 11, 11,11 ,1 ));//requirements 6
	exits.push_back(new Exit("", "West to 2nd Floor.\n",11 ,2 , 11, 8));//bathroom 7
	exits.push_back(new Exit("", "North to Bathroom.\n",11 ,11 ,7 ,11 ));//secrets 8
	exits.push_back(new Exit("", "West to Low Level.\n", 11,5 ,11 ,11 )); //transformations 6
	exits.push_back(new Exit("", "West to Dark Arts room",11 ,3 ,11 ,11 ));//darkwizard 10
	
		
		
}


//checkimput

int World::checkImput()
{
	mString userinput;
	printf("What do you wanna do?\n");
	userinput.get_str();
	if (userinput == "go north" || userinput == "north" || userinput == "n")
	{
		moveNorth();
		return 0;
	}
	else if (userinput == "go south" || userinput == "south" || userinput == "n")
	{
		moveSouth();
		return 0;
	}
	else if (userinput == "go east" || userinput == "east" || userinput=="e")
	{
		moveEast();
		return 0;
	}
	else if (userinput == "go west" || userinput== "west" || userinput=="w")
	{
		moveWest();
		return 0;
	}
	else if (userinput=="look")
	{
		lookRooms();
		return 0;
	}
	else if (userinput=="look north")
	{
		lookRoomsNorth();
		return 0;
	}
	else if (userinput=="look south")
	{
		lookRoomsSouth();
		return 0;
	}
	else if (userinput=="look east")
	{
		lookRoomsEast();
		return 0;
	}
	else if (userinput=="look west")
	{
		lookRoomsWest();
		return 0;
	}
	else if (userinput=="help")
	{
		giveHelp();
		return 0;
	}
	else if (userinput=="quit")
	{
		return 1;
	}
	else if (userinput=="open")
	{
		openDoor();
		return 0;
	}
	else if (userinput=="close")
	{
		closeDoor();
		return 0;
	}
	else if (userinput=="talk parsel")
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

//movement

void World::moveNorth(){
	if (player[0]->situation == 1) //it should be 1
	{
		player[0]->situation = exits[1]->destiny3;
		printf("\n%s\n", rooms[6]->Get_Name());
		printf("\n%s\n", rooms[6]->Get_Description());
		return;
	}
	else if (player[0]->situation == 2)
	{
		player[0]->situation = exits[2]->destiny3;
		printf("\n%s\n", rooms[1]->Get_Name());
		printf("\n%s\n", rooms[1]->Get_Description());
		return;
	}
	else if (player[0]->situation == 4)
	{
		player[0]->situation = exits[4]->destiny3;
		printf("\n%s\n", rooms[2]->Get_Name());
		printf("\n%s\n", rooms[2]->Get_Description());
		return;
	}
	else if (player[0]->situation == 5)
	{
		player[0]->situation = exits[5]->destiny3;
		printf("\n%s\n", rooms[4]->Get_Name());
		printf("\n%s\n", rooms[4]->Get_Description());
		return;
	}
	else if (player[0]->situation == 8)
	{
		player[0]->situation = exits[8]->destiny3;
		printf("\n%s\n", rooms[7]->Get_Name());
		printf("\n%s\n", rooms[7]->Get_Description());
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
	if (player[0]->situation == 1)
	{
		player[0]->situation = exits[1]->destiny4;
		printf("\n%s%s\n", rooms[2]->Get_Name(), rooms[2]->Get_Description());
		return;
	}
	else if (player[0]->situation == 6)
	{
		player[0]->situation = exits[6]->destiny4;
		printf("\n%s\n", rooms[1]->Get_Name());
		printf("\n%s\n", rooms[1]->Get_Description());
		return;
	}
	else if (player[0]->situation == 2)
	{
		player[0]->situation = exits[2]->destiny4;;
		printf("\n%s\n", rooms[4]->Get_Name());
		printf("\n%s\n", rooms[4]->Get_Description());
		return;
	}
	else if (player[0]->situation == 4)
	{
		player[0]->situation = exits[4]->destiny4;
		printf("\n%s\n", rooms[5]->Get_Name());
		printf("\n%s\n", rooms[5]->Get_Description());
		return;
	}
	else if (player[0]->situation == 7)
	{
		if (rooms[7]->openfountain == 1){
			player[0]->situation = exits[7]->destiny4;
			printf("\n%s\n", rooms[8]->Get_Name());
			printf("\n%s\n", rooms[8]->Get_Description());
			return;
		}
		if (rooms[7]->openfountain == 0){
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
	if (player[0]->situation == 0)
	{
		player[0]->situation = exits[0]->destiny2;
		printf("\n%s\n", rooms[1]->Get_Name());
		printf("\n%s\n", rooms[1]->Get_Description());
		return;
	}
	else if (player[0]->situation == 1)
	{
		if (rooms[1]->door == 1)
		{
			player[0]->situation = exits[1]->destiny2;
			printf("\n%s\n", rooms[3]->Get_Name());
			printf("\n%s\n", rooms[3]->Get_Description());
			return;
		}
		else if (rooms[1]->door == 0)
		{
			printf("\nThe door is closed.\n");
		}
	}
	else if (player[0]->situation == 3)
	{
		player[0]->situation = exits[3]->destiny2;
		printf("\n%s\n", rooms[10]->Get_Name());
		printf("\n%s\n", rooms[10]->Get_Description());
		return;
	}
	else if (player[0]->situation == 2)
	{
		player[0]->situation = exits[2]->destiny2;
		printf("\n%s\n", rooms[7]->Get_Name());
		printf("\n%s\n", rooms[7]->Get_Description());
		return;
	}
	else if (player[0]->situation == 5)
	{
		player[0]->situation = exits[5]->destiny2;
		printf("\n%s\n", rooms[9]->Get_Name());
		printf("\n%s\n", rooms[9]->Get_Description());
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
	if (player[0]->situation == 1)
	{
		player[0]->situation = exits[1]->destiny2;
		printf("\n%s\n", rooms[0]->Get_Name());
		printf("\n%s\n", rooms[0]->Get_Description());
		return;
	}
	else if (player[0]->situation == 3)
	{
		if (rooms[3]->door == 1)
		{
			player[0]->situation = exits[3]->destiny2;
			printf("\n%s\n", rooms[1]->Get_Name());
			printf("\n%s\n", rooms[1]->Get_Description());
			return;
		}
		else if (rooms[3]->door == 0)
		{
			printf("\nThe door is closed.\n");
			return;
		}
	}

	else if (player[0]->situation == 10)
	{
		player[0]->situation = exits[10]->destiny2;
		printf("\n%s\n", rooms[3]->Get_Name());
		printf("\n%s\n", rooms[3]->Get_Description());
		return;
	}
	else if (player[0]->situation == 7)
	{
		player[0]->situation = exits[7]->destiny2;
		printf("\n%s\n", rooms[2]->Get_Name());
		printf("\n%s\n", rooms[2]->Get_Description());
		return;
	}
	else if (player[0]->situation == 9)
	{
		player[0]->situation = exits[9]->destiny2;
		printf("\n%s\n", rooms[5]->Get_Name());
		printf("\n%s\n", rooms[5]->Get_Description());
		return;
	}
	else
	{
		printf("\nThere is a high wall you can't climb.\n\n");
		return;
	}
}

//other

void World::lookRooms()
{
	if (player[0]->situation == 0) printf("\n%s\n", exits[0]->Get_Description());
	else if (player[0]->situation == 1) printf("\n%s\n", exits[1]->Get_Description());
	else if (player[0]->situation == 9) printf("\n%s\n", exits[9]->Get_Description());
	else if (player[0]->situation == 3) printf("\n%s\n", exits[3]->Get_Description());
	else if (player[0]->situation == 10) printf("\n%s\n", exits[10]->Get_Description());
	else if (player[0]->situation == 2) printf("\n%s\n", exits[2]->Get_Description());
	else if (player[0]->situation == 4) printf("\n%s\n", exits[1]->Get_Description());
	else if (player[0]->situation == 5) printf("\n%s\n", exits[5]->Get_Description());
	else if (player[0]->situation == 6) printf("\n%s\n", exits[6]->Get_Description());
	else if (player[0]->situation == 7) printf("\n%s\n", exits[7]->Get_Description());
	else if (player[0]->situation == 8) printf("\n%s\n", exits[8]->Get_Description());
}

void World::giveHelp() const
{
	system("cls");
	printf("\nUse command 'go north' or 'n' or 'north' to move North.\n");
	printf("\nUse command 'go south' or 's' or 'south' to move South.\n");
	printf("\nUse command 'go east' or 'e' or 'east' to move East.\n");
	printf("\nUse command 'go west' or 'w' or 'west' to move West.\n");
	printf("\nUse command 'look' get info of the room you are in.\n");
	printf("\nUse command 'look' + 'north','south','east','west' to get info.\n");
	printf("\nUse command 'help' to get help.\n");
	printf("\nUse command 'open' to open closed doors.\n");
	printf("\nUse command 'close' to close the door you oppened.\n\n");
}

void World::openDoor()
{
	if (player[0]->situation == 1 && rooms[1]->door == 0)
	{
		printf("Door opened.\n");
		rooms[1]->door= 1;

	}
	else if (player[0]->situation == 3 && rooms[3]->door == 0)
	{
		printf("Door opened.\n");
		rooms[1]->door = 1;

	}
	else
	{
		printf("\nAll doors are opened.\n");

	}
}

void World::closeDoor()
{
	if (player[0]->situation == 3 && rooms[3]->door == 1){
		printf("The door is closed.\n");
		rooms[1]->door = 0;

	}
	else if (player[0]->situation == 1 && rooms[1]->door == 1)
	{
		printf("The door is closed.\n");
		rooms[1]->door = 0;

	}
	else
	{
		printf("\nYou can't close any door.\n");

	}
}

void World::talkParsel()
{
	if (player[0]->situation == 7)
	{
		if (rooms[7]->openfountain == 0){
			printf("\nThe fountain is moving...A door just opened on the fountain\n");
			rooms[7]->openfountain = 1;
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

void World::lookRoomsNorth()
{

	if (player[0]->situation == 1)
	{
		printf("\nSeems like some time ago there was a door here.\n");
	}
	else if (player[0]->situation == 2)
	{
		printf("\nThere are some stairs going up.\n");
	}
	else if (player[0]->situation == 4)
	{
		printf("\nThere are some stairs going up.\n");
	}
	else if (player[0]->situation == 5)
	{
		printf("\nThere are some stairs going up.\n");
	}
	else if (player[0]->situation == 8)
	{
		printf("\nYou can see the fountain on the middle if the dark.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}
void World::lookRoomsSouth()
{
	if (player[0]->situation == 1)
	{
		printf("\nThere are a some stairs going down\n");
	}
	else if (player[0]->situation == 2)
	{
		printf("\nThere are a some stairs going down\n");
	}
	else if (player[0]->situation == 4)
	{
		printf("\nThere are a some stairs going down\n");
	}
	else if (player[0]->situation == 6)
	{
		printf("\nA very old door is standing in front of you.\n");
	}
	else if (player[0]->situation == 7)
	{
		printf("\nThere is only the fountain.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}

void World::lookRoomsEast()
{
	if (player[0]->situation == 0)
	{
		printf("\nThere is a door that leads to the 3rdFloor Rooms\n");
	}
	else if (player[0]->situation == 1)
	{
		printf("\nThere is a closed door.\n");
	}
	else if (player[0]->situation == 3)
	{
		printf("\nThere is an old painting.\n");
	}
	else if (player[0]->situation == 2)
	{
		printf("\nThe door of the bathroom is in front of you.\n");
	}
	else if (player[0]->situation == 5)
	{
		printf("\nThe door of the transformation room is there, watching you.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}

void World::lookRoomsWest()
{
	if (player[0]->situation == 1)
	{
		printf("\nYou started your search there.\n");
	}
	else if (player[0]->situation == 3)
	{
		printf("\nYou can go to the 3rdFloor stairs.\n");
	}
	else if (player[0]->situation == 10)
	{
		printf("\nThe dark arts room is there.\n");
	}
	else if (player[0]->situation == 7)
	{
		printf("\nYou can go to the 2ndFloor stairs.\n");
	}
	else if (player[0]->situation == 9)
	{
		printf("\nStraight to Low Level.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}
