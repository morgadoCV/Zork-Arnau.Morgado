#include<stdio.h>
#include<string.h>
#include"room.h"
#include"player.h"
#include"world.h"
#include"exit.h"
using namespace std;

World::World(){
	my_player = new Player[1];
	my_rooms = new Room[12];
	my_exits = new Exit[44];

} 

void World::createWorld()
	{
		//player
		strcpy_s(my_player[0].name, "Unknown");
	    strcpy_s(my_player[0].description, "As you would know you are at Hogwarts, School of Witchcraft and Wizary. We found you unconscious last night on the top of the north tower's steps, we don't know what happened to you..\n You are at the sickroom, you must investigate what happened to you, maybe a dark wizard is in the castle..");
		//rooms
		strcpy_s(my_rooms[0].name, "Starting Room.\n");
		strcpy_s(my_rooms[0].description, "You can see a room when you look at east.\n");
		strcpy_s(my_rooms[1].name, "3rd Floor.\n");
		strcpy_s(my_rooms[1].description, "There are stair going down on south and a closed room east, it seems very cold.\n");
		strcpy_s(my_rooms[2].name, "2nd floor.\n");
		strcpy_s(my_rooms[2].description, "You can go east to the bathroom. South downstairs to 1st floor.\n");
		strcpy_s(my_rooms[3].name, "");
		strcpy_s(my_rooms[3].description, "");
		strcpy_s(my_rooms[4].name, "");
		strcpy_s(my_rooms[4].description, "");
		strcpy_s(my_rooms[5].name, "");
		strcpy_s(my_rooms[5].description, "");
		strcpy_s(my_rooms[6].name, "");
		strcpy_s(my_rooms[6].description, "");
		strcpy_s(my_rooms[7].name, "");
		strcpy_s(my_rooms[7].description, "");
		strcpy_s(my_rooms[8].name, "");
		strcpy_s(my_rooms[8].description, "");
		strcpy_s(my_rooms[9].name, "");
		strcpy_s(my_rooms[9].description, "");
		strcpy_s(my_rooms[10].name, "");
		strcpy_s(my_rooms[10].description, "");

	}



