#include<stdio.h>
#include<string.h>
#include"room.h"
#include"player.h"
#include"world.h"
#include"exit.h"
#include"entity.h"
#include"mystring.h"
using namespace std;

/*
//constructor&&deconstructor
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
	rooms.push_back(new Room("1st floor.\n", "There is a layer on the floor. The only way you can go is south, straight to the low level.\n"));
	rooms.push_back(new Room("Low Level.\n", "You can only go east, to the transformation room.\n"));
	rooms.push_back(new Room("Room of requirements.\n", "Wait..Where are you? You can see a book over a table."));
	rooms.push_back(new Room("Dark arts room.\n", "There is an old painting of Salazar Slytherin. You can also see a wand over the table and a heavy layer behind the door.\n"));
	rooms.push_back(new Room("Dark wizard room.\n", "Is there a room here? Since when? A wizard is staring at you with his wand on \nthe right hand.\n"));
	rooms.push_back(new Room("Bathroom\n", "You found your friend Arnau. There is an old fountain with what seem snakes \narround it.\n"));
	rooms.push_back(new Room("Chamber of Secrets.\n", "There is a BASILISK.There is also a book on the floor.\n"));
	rooms.push_back(new Room("Transformation room.\n", "There is a sword next to the table.\n"));

	
	 //exits
	exits.push_back(new Exit("", "East to 3rd Floor.\n", 3, 11, 11, 11));//starting 1
	exits.push_back(new Exit("", "East to Dark arts room, south to 2nd Floor, west to the Starting Room.\n",6, 0, 5, 2));//3rdFloor 2
	exits.push_back(new Exit("", "East to Bathroom, south to 1st Floor, north to 3rd Floor.\n", 8, 11, 3, 1));//2ndFloor 3
	exits.push_back(new Exit("", "West to 3rd Floor.\n",7 ,3 ,11 ,11 ));//darkarts 4
	exits.push_back(new Exit("", "South to Low Level, north to 2nd Floor.\n", 11, 11, 2,4 ));//1stFloor 5
	exits.push_back(new Exit("", "East to the Transformation room, north to 1st Floor.\n", 10,11 ,1 ,11 ));//lowlevel 6
	exits.push_back(new Exit("", "South to 3rd Floor.\n", 11, 11,11 ,3 ));//requirements 7
	exits.push_back(new Exit("", "West to 2nd Floor.\n",11 ,2 , 11, 9));//bathroom 8
	exits.push_back(new Exit("", "North to Bathroom.\n",11 ,11 ,8 ,11 ));//secrets 9
	exits.push_back(new Exit("", "West to Low Level.\n", 11,4 ,11 ,11 )); //transformations 10
	exits.push_back(new Exit("", "West to Dark Arts room",11 ,6 ,11 ,11 ));//darkwizard 11
	
		
		
}


//checkimput

int World::checkImput()
{
	mString userinput;
	printf("What do you wanna do?\n");
	userinput.get_str();
	if (userinput.give_str() == "go north" || userinput.give_str() == "north" || userinput.give_str()=="n")
	{
		moveNorth();
		return 0;
	}
	else if (userinput.give_str() == "go south" || userinput.give_str() == "south" || userinput.give_str() == "n")
	{
		moveSouth();
		return 0;
	}
	else if (userinput.give_str() == "go east" || userinput.give_str() == "east" || userinput.give_str()=="e")
	{
		moveEast();
		return 0;
	}
	else if (userinput.give_str() == "go west" || userinput.give_str() == "west" || userinput.give_str()=="w")
	{
		moveWest();
		return 0;
	}
	else if (userinput.give_str()=="look")
	{
		lookRooms();
		return 0;
	}
	else if (userinput.give_str()=="look north")
	{
		lookRoomsNorth();
		return 0;
	}
	else if (userinput.give_str()=="look south")
	{
		lookRoomsSouth();
		return 0;
	}
	else if (userinput.give_str()=="look east")
	{
		lookRoomsEast();
		return 0;
	}
	else if (userinput.give_str()=="look west")
	{
		lookRoomsWest();
		return 0;
	}
	else if (userinput.give_str()=="help")
	{
		giveHelp();
		return 0;
	}
	else if (userinput.give_str()=="quit")
	{
		return 1;
	}
	else if (userinput.give_str()=="open")
	{
		openDoor();
		return 0;
	}
	else if (userinput.give_str()=="close")
	{
		closeDoor();
		return 0;
	}
	else if (userinput.give_str()=="talk parsel")
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
	if (player[0]->situation == 2)
	{
		player[0]->situation = exits[2]->destiny3;
		printf("\n%s%s\n\n", rooms[7]->Get_Name(), rooms[7]->Get_Description());
		return;
	}
	else if (player[0]->situation == 3)
	{
		player[0]->situation = exits[3]->destiny3;
		printf("\n%s%s\n", rooms[2]->Get_Name(), rooms[2]->Get_Description());
		return;
	}
	else if (player[0]->situation == 5)
	{
		player[0]->situation = exits[5]->destiny3;
		printf("\n%s%s\n", rooms[3]->Get_Name(), rooms[3]->Get_Description());
		return;
	}
	else if (player[0]->situation == 6)
	{
		player[0]->situation = exits[6]->destiny3;
		printf("\n%s%s\n", rooms[5]->Get_Name(), rooms[5]->Get_Description());
		return;
	}
	else if (player[0]->situation == 9)
	{
		player[0]->situation = exits[9]->destiny3;
		printf("\n%s%s\n", rooms[8]->Get_Name(), rooms[8]->Get_Description());
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
	if (player[0]->situation == 2)
	{
		player[0]->situation = exits[2]->destiny4;
		printf("\n%s%s\n", rooms[3]->Get_Name(), rooms[3]->Get_Description());
		return;
	}
	else if (player[0]->situation == 7)
	{
		player[0]->situation = exits[7]->destiny4;
		printf("\n%s%s\n", rooms[3]->Get_Name(), rooms[3]->Get_Description());
		return;
	}
	else if (player[0]->situation == 3)
	{
		player[0]->situation = exits[3]->destiny4;;
		printf("\n%s%s\n", rooms[5]->Get_Name(), rooms[5]->Get_Description());
		return;
	}
	else if (player[0]->situation == 5)
	{
		player[0]->situation = exits[5]->destiny4;
		printf("\n%s%s\n", rooms[6]->Get_Name(), rooms[6]->Get_Description());
		return;
	}
	else if (player[0]->situation == 8)
	{
		if (openfountain == 1){
			player[0]->situation = exits[8]->destiny4;
			printf("\n%s%s\n", rooms[9]->Get_Name(), rooms[9]->Get_Description());
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

}*/
/*
void World::moveEast()
{
	if (player[0]->situation == 1)
	{
		player[0]->situation = exits[1]->destiny2;
		printf("\n%s%s\n", rooms[2]->Get_Name(), rooms[2]->Get_Description());
		return;
	}
	else if (player[0]->situation == 2)
	{
		if (door == 1)
		{
			player[0]->situation = exits[2]->destiny2;
			printf("\n%s%s\n", rooms[4]->Get_Name(), rooms[4]->Get_Description());
			return;
		}
		else if (door == 0)
		{
			printf("\nThe door is closed.\n");
		}
	}
	else if (player[0]->situation == 4)
	{
		player[0]->situation = exits[4]->destiny2;
		printf("\n%s%s\n", rooms[11]->Get_Name(), rooms[11]->Get_Description();
		return;
	}
	else if (player[0]->situation == 3)
	{
		player[0]->situation = exits[3]->destiny2;
		printf("\n%s%s\n", my_rooms[bathroom].name, my_rooms[bathroom].description);
		return;
	}
	else if (player[0]->situation == 6)
	{
		player[0]->situation = exits[6]->destiny2;
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

//other

void World::lookRooms() const
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
	if (my_player[0].situation == floor3&&door == 0)
	{
		printf("Door opened.\n");
		door = 1;

	}
	else if (my_player[0].situation == darkarts&&door == 0)
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
	if (my_player[0].situation == darkarts&&door == 1){
		printf("The door is closed.\n");
		door = 0;

	}
	else if (my_player[0].situation == floor3&&door == 1)
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
	if (my_player[0].situation == bathroom)
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

void World::lookRoomsNorth()const
{

	if (my_player[0].situation == floor3)
	{
		printf("\nSeems like some time ago there was a door here.\n");
	}
	else if (my_player[0].situation == floor2)
	{
		printf("\nThere are some stairs going up.\n");
	}
	else if (my_player[0].situation == floor1)
	{
		printf("\nThere are some stairs going up.\n");
	}
	else if (my_player[0].situation == lowlevel)
	{
		printf("\nThere are some stairs going up.\n");
	}
	else if (my_player[0].situation == secrets)
	{
		printf("\nYou can see the fountain on the middle if the dark.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}
void World::lookRoomsSouth()const
{
	if (my_player[0].situation == floor3)
	{
		printf("\nThere are a some stairs going down\n");
	}
	else if (my_player[0].situation == floor2)
	{
		printf("\nThere are a some stairs going down\n");
	}
	else if (my_player[0].situation == floor1)
	{
		printf("\nThere are a some stairs going down\n");
	}
	else if (my_player[0].situation == requirements)
	{
		printf("\nA very old door is standing in front of you.\n");
	}
	else if (my_player[0].situation == bathroom)
	{
		printf("\nThere is only the fountain.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}

void World::lookRoomsEast()const
{
	if (my_player[0].situation == starting)
	{
		printf("\nThere is a door that leads to the 3rdFloor Rooms\n");
	}
	else if (my_player[0].situation == floor3)
	{
		printf("\nThere is a closed door.\n");
	}
	else if (my_player[0].situation == darkarts)
	{
		printf("\nThere is an old painting.\n");
	}
	else if (my_player[0].situation == floor2)
	{
		printf("\nThe door of the bathroom is in front of you.\n");
	}
	else if (my_player[0].situation == lowlevel)
	{
		printf("\nThe door of the transformation room is there, watching you.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}

void World::lookRoomsWest()const
{
	if (my_player[0].situation == floor3)
	{
		printf("\nYou started your search there.\n");
	}
	else if (my_player[0].situation == darkarts)
	{
		printf("\nYou can go to the 3rdFloor stairs.\n");
	}
	else if (my_player[0].situation == darkwizard)
	{
		printf("\nThe dark arts room is there.\n");
	}
	else if (my_player[0].situation == bathroom)
	{
		printf("\nYou can go to the 2ndFloor stairs.\n");
	}
	else if (my_player[0].situation == transformation)
	{
		printf("\nStraight to Low Level.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}
*/