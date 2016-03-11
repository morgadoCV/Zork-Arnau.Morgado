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
	my_exits = new Exit[12];

} 
World::~World()
{
	delete[]my_player;
	delete[]my_exits;
	delete[]my_rooms;

}
void World::createWorld()
	{
		//player
		strcpy_s(my_player[0].name, "Unknown");
	    strcpy_s(my_player[0].description, "As you would know you are at Hogwarts, School of Witchcraft and Wizary. We found you unconscious last night on the top of the north tower's steps, we don't know what happened to you..\n You are at the sickroom, you must investigate what happened to you, maybe a dark wizard is in the castle..");
		
		//rooms
		strcpy_s(my_rooms[starting].name, "Starting Room.\n");
		strcpy_s(my_rooms[starting].description, "You can see a room when you look at east.There is a broom.\n");
		strcpy_s(my_rooms[floor3].name, "3rd Floor.\n");
		strcpy_s(my_rooms[floor3].description, "There are stair going down on south and a closed room east, it seems very cold.\n");
		strcpy_s(my_rooms[floor2].name, "2nd floor.\n");
		strcpy_s(my_rooms[floor2].description, "You can go east to the bathroom and south downstairs to 1st floor.There is a lantern on the floor.\n");
		strcpy_s(my_rooms[floor1].name, "1st floor.\n");
		strcpy_s(my_rooms[floor1].description, "There is a layer on the floor. The only way you can go is south, straight to the low level.\n");
		strcpy_s(my_rooms[lowlevel].name, "Low Level.\n");
		strcpy_s(my_rooms[lowlevel].description, "You can only go east, to the transformation room.\n");
		strcpy_s(my_rooms[requirements].name, "Room of requirements.\n");
		strcpy_s(my_rooms[requirements].description, "Wait..Where are you? You can see a book over a table.");
		strcpy_s(my_rooms[darkarts].name, "Dark arts room.\n ");
		strcpy_s(my_rooms[darkarts].description, "There is an old painting of Salazar Slytherin. You can also see a wand over the table and a heavy layer behind the door.\n");
		strcpy_s(my_rooms[darkwizard].name, "Dark wizard room.\n");
		strcpy_s(my_rooms[darkwizard].description, "Is there a room here? Since when? A wizard is staring at you with his wand on the right hand.\n");
		strcpy_s(my_rooms[bathroom].name, "Bathroom");
		strcpy_s(my_rooms[bathroom].description, "You found your friend Arnau. There is an old fountain with what seem snakes arround it.\n");
		strcpy_s(my_rooms[secrets].name, "Chamber of Secrets.\n");
		strcpy_s(my_rooms[secrets].description, "There is a BASILISK.There is also a book on the floor.\n");
		strcpy_s(my_rooms[transformation].name, "Transformation room.\n ");
		strcpy_s(my_rooms[transformation].description, "There is a sword next to the table.\n");


		//exits
		strcpy_s(my_exits[starting].description, "East to 3rd Floor.\n");
		strcpy_s(my_exits[floor3].description, "East to Dark arts room, south to 2nd Floor, west to the Starting Room.\n");
		strcpy_s(my_exits[floor2].description, "East to Bathroom, south to 1st Floor, north to 3rd Floor.\n");
		strcpy_s(my_exits[darkarts].description, "West to 3rd Floor.\n");
		strcpy_s(my_exits[floor1].description, "South to Low Level, north to 2nd Floor.\n");
		strcpy_s(my_exits[lowlevel].description, "East to the Transformation room, north to 1st Floor.\n");
		strcpy_s(my_exits[requirements].description, "South to 3rd Floor.\n");
		strcpy_s(my_exits[darkarts].description, "West to 3rd Floor.\n");
		strcpy_s(my_exits[darkwizard].description, "West to Dark Arts room.\n");
		strcpy_s(my_exits[bathroom].description, "West to 2nd Floor.\n");
		strcpy_s(my_exits[secrets].description, "West to Bathroom.\n");
		strcpy_s(my_exits[transformation].description, "West to Low Level.\n");
		
		//destiny of every room
		my_exits[starting].destiny = floor3;
		my_exits[floor3].destiny = starting;
		my_exits[floor3].destiny2 = transformation;
		my_exits[floor3].destiny3 = darkarts;
		my_exits[floor3].destiny4 = floor2;
		my_exits[requirements].destiny = floor3;
		my_exits[darkarts].destiny = floor3;
		my_exits[darkarts].destiny2 = darkwizard;
		my_exits[darkwizard].destiny = darkarts;
		my_exits[floor2].destiny = floor3;
		my_exits[floor2].destiny2 = floor1;
		my_exits[floor2].destiny3 = bathroom;
		my_exits[bathroom].destiny = secrets;
		my_exits[bathroom].destiny = floor2;
		my_exits[secrets].destiny = bathroom;
		my_exits[floor1].destiny = floor2;
		my_exits[floor1].destiny2 = lowlevel;
		my_exits[lowlevel].destiny = floor1;
		my_exits[lowlevel].destiny2 = transformation;
		my_exits[transformation].destiny = lowlevel;
	}



