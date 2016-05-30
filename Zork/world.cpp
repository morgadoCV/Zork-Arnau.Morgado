#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"room.h"
#include"player.h"
#include"world.h"
#include"exit.h"
#include"entity.h"
#include"mystring.h"
#include"item.h"
#include"hole.h"
#include"basilisk.h"
#include"friend.h"
#include"wizard.h"
#include <Windows.h>
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
	delete[]input;
}

//createworld
void World::createWorld()
{
	//player
	/*0*/entities.push_back(new Player("Unknown", "As you would know you are at Hogwarts, School of Witchcraft and Wizary.We found you unconscious last night on the top of the north tower's steps, we don't know what happened to you..\n You are at the sickroom, you must investigate what happened to you, maybe a dark wizard is in the castle..",1,50,100));
	player = (Player*)entities[0];
	
	//rooms
	
	/*1*//*0*/entities.push_back(new Room("Starting Room.\n", "You can see a room when you look at east.There is a broom."));
	/*2*//*1*/entities.push_back(new Room("3rd Floor.\n", "There are stair going down on south and a closed room east, it seems very cold.\n"));
	/*3*//*2*/entities.push_back(new Room("2nd floor.\n", "You can go east to the bathroom and south downstairs to 1st floor.\nThere is a lantern on the floor.\n"));
	/*4*//*3*/entities.push_back(new Room("Dark arts room.\n", "There is an old painting of Salazar Slytherin. You can also see a wand over the table and a heavy layer behind the door.\n"));
	/*5*//*4*/entities.push_back(new Room("1st floor.\n", "There is a layer on the floor. The only way you can go is south, straight to the low level.\n"));
	/*6*//*5*/entities.push_back(new Room("Low Level.\n", "You can only go east, to the transformation room.\n"));
	/*7*//*6*/entities.push_back(new Room("Room of requirements.\n", "Wait..Where are you? You can see a book over a table."));
	/*8*//*7*/entities.push_back(new Room("Bathroom\n", "There is an old fountain with what seem snakes \narround it.\n"));
	/*9*//*8*/entities.push_back(new Room("Chamber of Secrets.\n", "There is a BASILISK.There is also a book on the floor.\n"));
	/*10*//*9*/entities.push_back(new Room("Transformation room.\n", "There is a sword next to the table.\n"));
	/*11*//*10*/entities.push_back(new Room("Dark wizard room.\n", "Is there a room here? Since when? A wizard is staring at you with his wand on \nthe right hand.\n"));
	
	
	 //exits
	/*12*/entities.push_back(new Exit("", "East to 3rd Floor.\n", 2, 12, 12, 12));//starting 0
	/*13*/entities.push_back(new Exit("", "East to Dark arts room, south to 2nd Floor, west to the Starting Room.\n", 4, 1, 7, 3));//3rdFloor 1
	/*14*/entities.push_back(new Exit("", "East to Bathroom, south to 1st Floor, north to 3rd Floor.\n", 8, 12, 2, 5));//2ndFloor 2
	/*15*/entities.push_back(new Exit("", "West to 3rd Floor.\n", 11, 2, 12, 12));//darkarts 3
	/*16*/entities.push_back(new Exit("", "South to Low Level, north to 2nd Floor.\n", 12, 12, 3, 6));//1stFloor 4
	/*17*/entities.push_back(new Exit("", "East to the Transformation room, north to 1st Floor.\n", 10, 12, 5, 12));//lowlevel 5
	/*18*/entities.push_back(new Exit("", "South to 3rd Floor.\n", 12, 12, 12, 2));//requirements 6
	/*19*/entities.push_back(new Exit("", "West to 2nd Floor.\n", 12, 3, 12, 9));//bathroom 7
	/*20*/entities.push_back(new Exit("", "North to Bathroom.\n", 12, 12, 8, 12));//secrets 8
	/*21*/entities.push_back(new Exit("", "West to Low Level.\n", 12, 6, 12, 12)); //transformations 6
	/*22*/entities.push_back(new Exit("", "West to Dark Arts room", 12, 4, 12, 12));//darkwizard 10
	
		
	//items
	/*23*/entities.push_back(new Item("Wand", "It seems really old."));
	((Room*)entities[4])->list.push_back(entities[23]);
	/*24*/entities.push_back(new Item("Instakill Book", "Seems like you can read it."));
	((Room*)entities[9])->list.push_back(entities[24]);
	/*25*/entities.push_back(new Item("Layer", "Maybe you can equip it."));
	((Room*)entities[5])->list.push_back(entities[25]);
	/*26*/entities.push_back(new Item("Time Turner", "It gives you the hability to teleport throw rooms you have been before."));
	/*27*/entities.push_back(new Item("Keys", "Just some keys."));
	((Room*)entities[10])->list.push_back(entities[27]);
	/*28*/entities.push_back(new Item("Lamp", "It will show you the light."));
	((Room*)entities[3])->list.push_back(entities[28]);
	/*29*/entities.push_back(new Item("Goddreic's Griffindor sword", "Some books say that it can kill magic creatures."));
	((Room*)entities[10])->list.push_back(entities[29]);
	/*30*/entities.push_back(new Item("Photo", "It is an old photo of you and your parents, what is it doing here?."));
	/*31*/entities.push_back(new Item("Broom", "An old Broom, maybe you can fly with it, who knows?"));
	((Room*)entities[1])->list.push_back(entities[31]);
	/*32*/entities.push_back(new Item("Heavy Layer", "Maybe you can equip it."));
	((Room*)entities[4])->list.push_back(entities[32]);
	/*33*/entities.push_back(new Item("Stun Book", "Just read it."));
	((Room*)entities[7])->list.push_back(entities[33]);


	//hole

	//34
	entities.push_back(new Entity("There is a hole", "Seems like you can put thinks into it",0));

	//NPCs
	/*35*/entities.push_back(new Basilisk("Basilisk", "A big snake is staring at you.", 50, 3000));
	/*36*/entities.push_back(new Friend("Friend", "Maybe he can give you something that help you", 0, 0,"Hi dude, how are you?, I just found something at the schoo'ls hall. Do you want it?\n","Ok, cya!\n",6));
	((Friend*)entities[36])->list.push_back(entities[26]);
	/*37*/entities.push_back(new Wizard("Dark Wizard", "Is that him? What did he do to you last night?", 100, 1000));
	

}


//checkimput
void World::getinput()
{
	input = new char[35];
	gets_s(input, 35);
}

int World::checkImput()
{
	mString comand;
	printf("What do you wanna do?\n");
	getinput();
	comand = input;
	//userinput.get_str();
	if (comand == "go north" || comand == "north" || comand == "n")
	{
		moveNorth();
		return 0;
	}
	else if (comand == "go south" || comand == "south" || comand == "s")
	{
		moveSouth();
		return 0;
	}
	else if (comand == "go east" || comand == "east" || comand == "e")
	{
		moveEast();
		return 0;
	}
	else if (comand == "go west" || comand == "west" || comand == "w")
	{
		moveWest();
		return 0;
	}
	else if (comand == "look")
	{
		lookRooms();
		return 0;
	}
	else if (comand == "look north")
	{
		lookRoomsNorth();
		return 0;
	}
	else if (comand == "look south")
	{
		lookRoomsSouth();
		return 0;
	}
	else if (comand == "look east")
	{
		lookRoomsEast();
		return 0;
	}
	else if (comand == "look west")
	{
		lookRoomsWest();
		return 0;
	}
	else if (comand == "help")
	{
		giveHelp();
		return 0;
	}
	else if (comand == "quit")
	{
		return 1;
	}
	else if (comand == "open")
	{
		openDoor();
		return 0;
	}
	else if (comand == "close")
	{
		closeDoor();
		return 0;
	}
	else if (comand == "talk parsel")
	{
		talkParsel();
		return 0;
	}
	else if (comand == "pick wand")
	{
		mList<Entity*>::mNode* i = ((Room*)entities[player->situation])->list.first;
		if (i != nullptr || i != nullptr){
			for (; i != nullptr; i = i->next)
			{

				if (i->data->Get_Name() == "Wand")
				{
					if (i != nullptr)
					{
						printf("You have picked the wand.\n");
						player->list.push_back(i->data);
						player->modifyattack(150);
						((Room*)entities[player->situation])->list.erase(i);
						return 0;
					}

				}

			}

		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
	}

	else if (comand == "pick instakill book")
	{
		
		mList<Entity*>::mNode* i = ((Room*)entities[player->situation])->list.first;
		if (i->next != nullptr || i != nullptr){
			for (; i != nullptr; i = i->next)
			{

				if (i->data->Get_Name() == "Instakill Book")
				{
					if (i != nullptr)
					{
						printf("You have picked the instakill book.\n");
						player->list.push_back(i->data);
						player->modifyattack(500);
						((Room*)entities[player->situation])->list.erase(i);
						return 0;
					}

				}

			}

		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
	}
		
		
	
	else if (comand == "pick layer")
	{

		mList<Entity*>::mNode* i = ((Room*)entities[player->situation])->list.first;
		if (i->next != nullptr || i != nullptr){
			for (; i != nullptr; i = i->next)
			{

				if (i->data->Get_Name() == "Layer")
				{
					if (i != nullptr)
					{
						printf("You have picked the layer.\n");
						player->list.push_back(i->data);
						player->modifydefense(300);
						((Room*)entities[player->situation])->list.erase(i);
						return 0;
					}

				}

			}

		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
	}

		
	else if (comand == "pick time turner")
	{

		mList<Entity*>::mNode* i = ((Room*)entities[player->situation])->list.first;
		if (i->next != nullptr || i != nullptr){
			for (; i != nullptr; i = i->next)
			{

				if (i->data->Get_Name() == "Time Turner")
				{
					if (i != nullptr)
					{
						printf("You have picked the time turner.\n");
						player->list.push_back(i->data);
						((Room*)entities[player->situation])->list.erase(i);
						return 0;
					}

				}

			}

		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
	}
			
	else if (comand == "pick keys")
	{
		mList<Entity*>::mNode* i = ((Room*)entities[player->situation])->list.first;
		if (i->next != nullptr || i != nullptr){
			for (; i != nullptr; i = i->next)
			{

				if (i->data->Get_Name() == "Keys")
				{
					if (i != nullptr)
					{
						printf("You have picked the keys.\n");
						player->list.push_back(i->data);
						((Room*)entities[player->situation])->list.erase(i);
						return 0;
					}

				}

			}

		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
	}
		
	else if (comand == "pick lamp")
	{

		mList<Entity*>::mNode* i = ((Room*)entities[player->situation])->list.first;
		if (i->next != nullptr||i!=nullptr){
			for (; i != nullptr; i = i->next)
			{

				if (i->data->Get_Name() == "Lamp")
				{
					if (i != nullptr)
					{
						printf("You have picked the lamp.\n");
						player->list.push_back(i->data);
						((Room*)entities[player->situation])->list.erase(i);
						return 0;
					}

				}

			}

		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
	}
		
	else if (comand == "pick sword")
	{

		mList<Entity*>::mNode* i = ((Room*)entities[player->situation])->list.first;
		if (i->next != nullptr || i != nullptr){
			for (; i != nullptr; i = i->next)
			{

				if (i->data->Get_Name() == "Goddreic's Griffindor sword")
				{
					if (i != nullptr)
					{
						printf("You have picked the sword.\n");
						player->list.push_back(i->data);
						((Room*)entities[player->situation])->list.erase(i);
						return 0;
					}

				}

			}

		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
	}
	else if (comand == "pick photo")
	{
		mList<Entity*>::mNode* i = ((Room*)entities[player->situation])->list.first;
		if (i->next != nullptr || i != nullptr){
			for (; i != nullptr; i = i->next)
			{

				if (i->data->Get_Name() == "Photo")
				{
					if (i != nullptr)
					{
						printf("You have picked the photo.\n");;
						player->list.push_back(i->data);
						((Room*)entities[player->situation])->list.erase(i);
						return 0;
					}

				}

			}

		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
	}
		
		
	else if (comand == "pick broom")
	{
		mList<Entity*>::mNode* i = ((Room*)entities[player->situation])->list.first;
		if (i->next != nullptr || i != nullptr){
			for (; i != nullptr; i = i->next)
			{

				if (i->data->Get_Name() == "Broom")
				{
					if (i != nullptr)
					{
						printf("This isn't the time to use that! Do you wanna fly into the school?\n");
						return 0;
					}

				}

			}

		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
	}
		
	else if (comand == "pick heavy layer")
	{
		mList<Entity*>::mNode* i = ((Room*)entities[player->situation])->list.first;
		if (i->next != nullptr||i!=nullptr){
			for (; i != nullptr; i = i->next)
			{

				if (i->data->Get_Name() == "Heavy Layer")
				{
					if (i != nullptr)
					{
						printf("It is to heavy!!");
						return 0;
					}

				}

			}

		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
	}
		
		
	else if (comand == "pick stun book")
	{

		mList<Entity*>::mNode* i = ((Room*)entities[player->situation])->list.first;
		if (i->next != nullptr || i != nullptr){
			for (; i != nullptr; i = i->next)
			{

				if (i->data->Get_Name() == "Stun Book")
				{
					if (i != nullptr)
					{
						printf("You have picked the stun book.\n");
						player->modifyattack(50);
						player->list.push_back(i->data);
						((Room*)entities[player->situation])->list.erase(i);
						return 0;
					}

				}

			}

		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
	}
	
	else if (comand == "drop wand")
	{

		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Wand")
			{
				printf("You have droped the wand.\n");
				player->modifyattack2(150);
				((Room*)entities[player->situation])->list.push_back(i->data);
				player->list.erase(i);
				return 0;
			}
		}
	}
	else if (comand == "drop instakill book")
	{
		
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Instakill Book")
			{
				printf("You have droped the isntakill book.\n");
				((Room*)entities[player->situation])->list.push_back(i->data);
				player->list.erase(i);
				player->modifyattack2(500);
				
				return 0;
			}
		}
	}
	else if (comand == "drop layer")
	{

		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Layer")
			{
				printf("You have droped the layer.\n");
				((Room*)entities[player->situation])->list.push_back(i->data);
				player->list.erase(i);
				player->modifydefense2(300);
				
				return 0;
			}
		}
	}
	
	else if (comand == "drop time turner")
	{

		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Time Turner")
			{
				printf("You have droped the time turner.\n");
				((Room*)entities[player->situation])->list.push_back(i->data);
				player->list.erase(i);
				
				return 0;
			}
		}
	}
	else if (comand == "drop keys")
	{

		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "keys")
			{
				printf("You have droped the keys.\n");
				((Room*)entities[player->situation])->list.push_back(i->data);
				player->list.erase(i);
				return 0;
			}
		}
	}
	else if (comand == "drop lamp")
	{

		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Lamp")
			{
				printf("You have droped the lamp.\n");
				((Room*)entities[player->situation])->list.push_back(i->data);
				player->list.erase(i);
				
				return 0;
			}
		}
	}
	else if (comand == "drop sword")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Goddreic's Griffindor sword")
			{
				printf("You have droped the sword.\n");
				((Room*)entities[player->situation])->list.push_back(i->data);
				player->list.erase(i);
				
				return 0;
			}
		}
	}
	else if (comand == "drop photo")
	{

		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Photo")
			{
				printf("You have droped the photo.\n");
				((Room*)entities[player->situation])->list.push_back(i->data);
				player->list.erase(i);
				
				return 0;
			}
		}
	}
	else if (comand == "drop stun book")
	{

		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Stun Book")
			{
				printf("You have droped the stun book.\n");
				((Room*)entities[player->situation])->list.push_back(i->data);
				player->modifyattack2(50);
				player->list.erase(i);
				
				return 0;
			}
		}
	}
	else if (comand == "i"||comand=="inventory"||comand=="inv")
	{
		printf("You inventory:\n");
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			printf("%s\n", i->data->Get_Name());
		}
		return 0;
	
	}
	
	else if (comand == "look wand")
	{ 
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Wand"){ printf("%s\n", i->data->Get_Description()); }	
		}
		mList<Entity*>::mNode* j = ((Room*)entities[player->situation])->list.first;
		for (; j != nullptr; j = j->next)
		{
			if (j->data->Get_Name() == "Wand"){ printf("%s\n", j->data->Get_Description()); }
		}
	}
	else if (comand == "look instakill book")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Instakill Book"){ printf("%s\n", i->data->Get_Description()); }
		}
		mList<Entity*>::mNode* j = ((Room*)entities[player->situation])->list.first;
		for (; j != nullptr; j = j->next)
		{
			if (j->data->Get_Name() == "Instakill Book"){ printf("%s\n", j->data->Get_Description()); }
		}
		return 0;
	}
	else if (comand == "look layer")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Layer"){ printf("%s\n", i->data->Get_Description()); }
		}
		mList<Entity*>::mNode* j = ((Room*)entities[player->situation])->list.first;
		for (; j != nullptr; j = j->next)
		{
			if (j->data->Get_Name() == "Layer"){ printf("%s\n", j->data->Get_Description()); }
		}
		return 0;
	}
	else if (comand == "look time turner")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Time Turner"){ printf("%s\n", i->data->Get_Description()); }
		}
		mList<Entity*>::mNode* j = ((Room*)entities[player->situation])->list.first;
		for (; j != nullptr; j = j->next)
		{
			if (j->data->Get_Name() == "Time Turner"){ printf("%s\n", j->data->Get_Description()); }
		}
		return 0;
	}
	else if (comand == "look keys")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Keys"){ printf("%s\n", i->data->Get_Description()); }
		}
		mList<Entity*>::mNode* j = ((Room*)entities[player->situation])->list.first;
		for (; j != nullptr; j = j->next)
		{
			if (j->data->Get_Name() == "Keys"){ printf("%s\n", j->data->Get_Description()); }
		}
		return 0;
	}
	else if (comand == "look lamp")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Lamp"){ printf("%s\n", i->data->Get_Description()); }
		}
		mList<Entity*>::mNode* j = ((Room*)entities[player->situation])->list.first;
		for (; j != nullptr; j = j->next)
		{
			if (j->data->Get_Name() == "Lamp"){ printf("%s\n", j->data->Get_Description()); }
		}
		return 0;
	}
	else if (comand == "look sword")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Instakill Book"){ printf("%s\n", i->data->Get_Description()); }
		}
		mList<Entity*>::mNode* j = ((Room*)entities[player->situation])->list.first;
		for (; j != nullptr; j = j->next)
		{
			if (j->data->Get_Name() == "Instakill Book"){ printf("%s\n", j->data->Get_Description()); }
		}
		return 0;
	}
	else if (comand == "look photo")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Photo"){ printf("%s\n", i->data->Get_Description()); }
		}
		mList<Entity*>::mNode* j = ((Room*)entities[player->situation])->list.first;
		for (; j != nullptr; j = j->next)
		{
			if (j->data->Get_Name() == "Photo"){ printf("%s\n", j->data->Get_Description()); }
		}
		return 0;
	}
	else if (comand == "look broom")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Broom"){ printf("%s\n", i->data->Get_Description()); }
		}
		mList<Entity*>::mNode* j = ((Room*)entities[player->situation])->list.first;
		for (; j != nullptr; j = j->next)
		{
			if (j->data->Get_Name() == "Broom"){ printf("%s\n", j->data->Get_Description()); }
		}
		return 0;
	}
	else if (comand == "look heavy layer")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Heavy Layer"){ printf("%s\n", i->data->Get_Description()); }
		}
		mList<Entity*>::mNode* j = ((Room*)entities[player->situation])->list.first;
		for (; j != nullptr; j = j->next)
		{
			if (j->data->Get_Name() == "Heavy Layer"){ printf("%s\n", j->data->Get_Description()); }
		}
		return 0;
	}
	else if (comand == "look stun book")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Stun Book"){ printf("%s\n", i->data->Get_Description()); }
		}
		mList<Entity*>::mNode* j = ((Room*)entities[player->situation])->list.first;
		for (; j != nullptr; j = j->next)
		{
			if (j->data->Get_Name() == "Stun Book"){ printf("%s\n", j->data->Get_Description()); }
		}
		return 0;
	}
	else if (comand=="stats")
	{
		printf("\nAttack->%i\n", player->giveattack());
		printf("\nDefense->%i\n", player->givedefense());
		return 0;
	}
	else if (comand == "equip wand")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Wand")
			{ 
				printf("Wand equip.\n");
				player->equip.push_back(i->data);
				player->list.erase(i);
				return 0;
			}
		}
		
	}
	else if (comand == "equip sword")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Sword")
			{
				printf("Sword equip.\n");
				player->equip.push_back(i->data);
				player->list.erase(i);
			}
		}
	}
	else if (comand == "equip layer")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Layer")
			{
				printf("Layer equip.\n");
				player->equip.push_back(i->data);
				player->list.erase(i);
				return 0;
			}
		}
	}
	else if (comand == "unequip wand")
	{
		mList<Entity*>::mNode* i = player->equip.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Wand")
			{
				printf("Wand unequip.\n");
				player->list.push_back(i->data);
				player->equip.erase(i);
				return 0;
			}
		}
	}
	else if (comand == "unequip sword")
	{
		mList<Entity*>::mNode* i = player->equip.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Sword")
			{
				printf("Sword unequip.\n");
				player->list.push_back(i->data);
				player->equip.erase(i);
				return 0;
			}
		}
	}
	else if (comand == "unequip layer")
	{
		mList<Entity*>::mNode* i = player->equip.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Layer")
			{
				printf("Layer equip.\n");
				player->list.push_back(i->data);
				player->equip.erase(i);
				return 0;
			}
		}
	}
	else if (comand == "put wand into hole")
	{
		
		if (player->situation == 1)
		{
			mList<Entity*>::mNode* i = player->list.first;
			for (; i != nullptr; i = i->next)
			{
				if (i->data->Get_Name() == "Wand")
				{
					entities[34]->list.push_back(i->data);
					player->list.erase(i);
					player->modifyattack2(150);
					printf("PLOP\n");
					return 0;
				}
			}

		}
	}
	else if (comand == "put instakill book into hole")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Instakill Book")
			{
				entities[34]->list.push_back(i->data);
				player->list.erase(i);
				player->modifyattack2(500);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "put layer into hole")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Layer")
			{
				entities[34]->list.push_back(i->data);
				player->list.erase(i);
				player->modifydefense2(300);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "put keys into hole")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Keys")
			{
				entities[34]->list.push_back(i->data);
				player->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "put lantern into hole")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Lamp")
			{
				entities[34]->list.push_back(i->data);
				player->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "put sword into hole")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Sword")
			{
				entities[34]->list.push_back(i->data);
				player->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "put photo into hole")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Photo")
			{
				entities[34]->list.push_back(i->data);
				player->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "put stun book into hole")
	{
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Stun Book")
			{
				entities[34]->list.push_back(i->data);
				player->modifyattack2(50);
				player->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "get wand from hole")
	{
		mList<Entity*>::mNode* i = entities[34]->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Wand")
			{
				player->list.push_back(i->data);
				player->modifyattack(150);
				entities[34]->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "get instakill book from hole")
	{
		mList<Entity*>::mNode* i = entities[34]->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Instakill Book")
			{
				player->list.push_back(i->data);
				player->modifyattack(500);
				entities[34]->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "get layer from hole")
	{
		mList<Entity*>::mNode* i = entities[34]->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Layer")
			{
				player->list.push_back(i->data);
				player->modifydefense2(300);
				entities[34]->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "get keys from hole")
	{
		mList<Entity*>::mNode* i = entities[34]->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Keys")
			{
				player->list.push_back(i->data);
				entities[34]->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "get lantern from hole")
	{
		mList<Entity*>::mNode* i = entities[34]->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Lamp")
			{
				player->list.push_back(i->data);
				entities[34]->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "get sword from hole")
	{
		mList<Entity*>::mNode* i = entities[34]->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Sword")
			{
				player->list.push_back(i->data);
				entities[34]->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "get photo from hole")
	{
		mList<Entity*>::mNode* i = entities[34]->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Photo")
			{
				player->list.push_back(i->data);
				entities[34]->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "get stun book from hole")
	{
		mList<Entity*>::mNode* i = entities[34]->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Stun Book")
			{
				player->list.push_back(i->data);
				entities[34]->list.erase(i);
				printf("PLOP\n");
				return 0;
			}
		}
	}
	else if (comand == "hole")
	{
		printf("\nHole inv:\n");
		mList<Entity*>::mNode* i = entities[34]->list.first;
		for (; i != nullptr;i->next)
		{
			printf("%s\n", i->data->Get_Name());
			return 0;
		}
		
	}
	else if (comand == "talk friend")
	{
		if (((Friend*)entities[36])->friendposition() == player->situation)
		{
			((Friend*)entities[36])->changetalking();
			printf("%s\n", ((Friend*)entities[36])->talk(0));
			World talk;
			char str[25];
			mString hey;
			getinput();
			hey = input;
			if (hey == "yes" || hey == "yeah" || hey == "y")
			{
				if (((Friend*)entities[36])->list.empty()){ printf("Already given it to you bro!\n"); }
				else
				{
					printf("You recived a Time Turner.\n");
					player->list.push_back(entities[26]);
					((Friend*)entities[36])->list.clear();
				}
			}
			if (hey == "no" || hey == "nope" || hey == "n")
			{
				printf("%s\n", ((Friend*)entities[36])->talk(1));
			}
		}
		else
		{
			printf("Who is friend?\n");
		}
		((Friend*)entities[36])->changetalking();
		return 0;
	}
	else if (comand == "attack basilisk")
	{
		if (player->situation == 9)
		{
			int ret=attack(1);
			if (ret == 1){ return 1; }
			return 0;
		}
		else{printf("You mad bro?\n");}
		
	}
	else if (comand == "instakill basilisk")
	{
		if (player->situation == 9)
		{
			mList<Entity*>::mNode* i = player->list.first;
			for (; i != nullptr; i=i->next)
			{
				if (i->data->Get_Name() == "Goddreic's Griffindor sword")
				{
					int ret=attack(3);
					if (ret == 1){ return 1; }
					return 0;
				}
			}
		}
		else{ printf("You mad bro?\n"); }
	}
	else if (comand == "stun basilisk")
	{
		if (player->situation == 9)
		{
			int ret=attack(2);
			mList<Entity*>::mNode* i = player->list.first;
			for (; i != nullptr; i = i->next)
			{
				if (i->data->Get_Name() == "Stun Book")
				{
					((Room*)entities[10])->list.push_back(i->data);
					player->list.erase(i);
				}
			}
			if (ret == 1){ return 1; }
			return 0;
		}
		else{ printf("You mad bro?\n"); }
	}
	else if (comand == "stun wizard")
	{
		if (player->situation == 11)
		{
			int ret = attack(5);
			mList<Entity*>::mNode* i = player->list.first;
			for (; i != nullptr; i = i->next)
			{
				if (i->data->Get_Name() == "Stun Book")
				{
					((Room*)entities[10])->list.push_back(i->data);
					player->list.erase(i);
				}
			}
			if (ret == 1){ return 1; }
			if (ret == 2){ return 2; }
			return 0;
		}
		else{ printf("You mad bro?\n"); }
	}
	else if (comand == "attack wizard")
	{
		if (player->situation == 11)
		{
			int ret = attack(4);
			if (ret == 1){ return 1; }
			if (ret == 2){ return 2; }
			return 0;
		}
		else{ printf("You mad bro?\n"); }
	}
	else if (comand == "instakill wizard")
	{
		if (player->situation == 11)
		{
			mList<Entity*>::mNode* i = player->list.first;
			for (; i != nullptr; i=i->next)
			{
				if (i->data->Get_Name() == "Instakill Book")
				{
					int ret = attack(6);
					if (ret == 1){ return 1; }
					if (ret == 2){ return 2; }
					return 0;
				}

			}
		}
		else{ printf("You mad bro?\n"); }
	}
	else if (comand=="buy friend")
	{
		((Friend*)entities[36])->changebuying();
		printf("Everything costs 100 coins.\n");
		mList<Entity*>::mNode* i = ((Friend*)entities[36])->list.first;
		for (; i != nullptr; i = i->next)
		{
			printf("%s\n", i->data->Get_Name());
		}
		((Friend*)entities[36])->changebuying();
	}
	else if (comand == "sell keys to friend")
	{
		((Friend*)entities[36])->changebuying();
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Keys")
			{
				printf("Your friend gave you 100 coins for the keys.\n");
				player->coins = player->coins + 100;
				((Friend*)entities[36])->list.push_back(i->data);
				player->list.erase(i);
			}
		}
		((Friend*)entities[36])->changebuying();
	}
	else if (comand == "sell lamp to friend")
	{
		((Friend*)entities[36])->changebuying();
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Lamp")
			{
				printf("Your friend gave you 100 coins for the Lamp.\n");
				player->coins = player->coins + 100;
				((Friend*)entities[36])->list.push_back(i->data);
				player->list.erase(i);
			}
		}
		((Friend*)entities[36])->changebuying();
	}
	else if (comand == "sell photo to friend")
	{
		((Friend*)entities[36])->changebuying();
		mList<Entity*>::mNode* i = player->list.first;
		for (; i != nullptr; i = i->next)
		{
			if (i->data->Get_Name() == "Photo")
			{
				printf("Your friend gave you 100 coins for the photo.\n");
				player->coins = player->coins + 100;
				((Friend*)entities[36])->list.push_back(i->data);
				player->list.erase(i);
			}
		}
		((Friend*)entities[36])->changebuying();
	}
	else if (comand == "buy keys from friend")
	{
		((Friend*)entities[36])->changebuying();
		if (player->coins >= 100)
		{
			mList<Entity*>::mNode* i = ((Friend*)entities[36])->list.first;
			for (; i != nullptr; i = i->next)
			{
				if (i->data->Get_Name() == "Keys")
				{
					printf("You payed 100 coins for the keys.\n");
					player->coins = player->coins - 100;
					player->list.push_back(i->data);
					((Friend*)entities[36])->list.erase(i);
				}
			}
		}
		else{ printf("You don't have money dude!\n"); }
		((Friend*)entities[36])->changebuying();
	}
	else if (comand == "buy lamp from friend")
	{
		((Friend*)entities[36])->changebuying();
		if (player->coins >= 100)
		{
			mList<Entity*>::mNode* i = ((Friend*)entities[36])->list.first;
			for (; i != nullptr; i = i->next)
			{
				if (i->data->Get_Name() == "Lamp")
				{
					printf("You payed 100 coins for the lamp.\n");
					player->coins = player->coins - 100;
					player->list.push_back(i->data);
					((Friend*)entities[36])->list.erase(i);
				}
			}
		}
		else{ printf("You don't have money dude!\n"); }
		((Friend*)entities[36])->changebuying();
	}
	else if (comand == "buy photo from friend")
	{
		((Friend*)entities[36])->changebuying();
		if (player->coins >= 100)
		{
			mList<Entity*>::mNode* i = ((Friend*)entities[36])->list.first;
			for (; i != nullptr; i = i->next)
			{
				if (i->data->Get_Name() == "Photo")
				{
					printf("You payed 100 coins for the photo.\n");
					player->coins = player->coins - 100;
					player->list.push_back(i->data);
					((Friend*)entities[36])->list.erase(i);
				}
			}
		}
		else{ printf("You don't have money dude!\n"); }
		((Friend*)entities[36])->changebuying();
	}
	
	else
	{
		printf("\nWrong command.Type 'help' if you need it.\n");
		return 0;
	}
	
}

//movement

void World::moveNorth(){
	if (player->situation == 2)
	{
		player->situation = ((Exit*)entities[13])->destiny3;
		printf("\n%s\n", ((Room*)entities[7])->Get_Name());
		mList<Entity*>::mNode* i = entities[7]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 3)
	{
		player->situation = ((Exit*)entities[14])->destiny3;
		printf("\n%s\n", ((Room*)entities[2])->Get_Name());
		mList<Entity*>::mNode* i = entities[2]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 5)
	{
		player->situation = ((Exit*)entities[16])->destiny3;
		printf("%s\n", ((Room*)entities[3])->Get_Name());
		mList<Entity*>::mNode* i = entities[3]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 6)
	{
		player->situation = ((Exit*)entities[17])->destiny3;
		printf("\n%s\n", ((Room*)entities[5])->Get_Name());
		mList<Entity*>::mNode* i = entities[5]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 9)
	{
		player->situation = ((Exit*)entities[20])->destiny3;
		printf("\n%s\n", ((Room*)entities[8])->Get_Name());
		mList<Entity*>::mNode* i = entities[8]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
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
	if (player->situation == 2)
	{
		player->situation = ((Exit*)entities[13])->destiny4;
		printf("\n%s\n", ((Room*)entities[3])->Get_Name());
		mList<Entity*>::mNode* i = entities[3]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 7)
	{
		player->situation = ((Exit*)entities[18])->destiny4;
		printf("\n%s\n", ((Room*)entities[2])->Get_Name());
		mList<Entity*>::mNode* i = entities[2]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 3)
	{
		player->situation = ((Exit*)entities[14])->destiny4;;
		printf("\n%s\n", ((Room*)entities[5])->Get_Name());
		mList<Entity*>::mNode* i = entities[5]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 5)
	{
		player->situation = ((Exit*)entities[16])->destiny4;
		printf("\n%s\n", ((Room*)entities[6])->Get_Name());
		mList<Entity*>::mNode* i = entities[6]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 8)
	{
		if (((Room*)entities[8])->openfountain == 1){
			player->situation = ((Exit*)entities[19])->destiny4;
			printf("\n%s\n", ((Room*)entities[9])->Get_Name());
			printf("\n%s\n", ((Room*)entities[9])->Get_Description());
			mList<Entity*>::mNode* i = entities[9]->list.first;
			for (; i != nullptr; i = i->next){
				printf("%s\n", i->data->Get_Name());
			}
			return;
		}
		if (((Room*)entities[8])->openfountain == 0){
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
	if (player->situation == 1)
	{
		player->situation = ((Exit*)entities[12])->destiny;
		printf("\n%s\n", ((Room*)entities[2])->Get_Name());
		mList<Entity*>::mNode* i = entities[2]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 2)
	{
		if (((Room*)entities[2])->door == 1)
		{
			player->situation = ((Exit*)entities[13])->destiny;
			printf("\n%s\n", ((Room*)entities[4])->Get_Name());
			mList<Entity*>::mNode* i = entities[4]->list.first;
			for (; i != nullptr; i = i->next){
				printf("%s\n", i->data->Get_Name());
			}
			return;
		}
		else if (((Room*)entities[2])->door == 0)
		{
			printf("\nThe door is closed.\n");
		}
	}
	else if (player->situation == 4)
	{
		player->situation = ((Exit*)entities[15])->destiny;
		printf("\n%s\n", ((Room*)entities[11])->Get_Name());
		printf("\n%s\n", ((Room*)entities[11])->Get_Description());
		mList<Entity*>::mNode* i = entities[11]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 3)
	{
		player->situation = ((Exit*)entities[14])->destiny;
		printf("\n%s\n", ((Room*)entities[8])->Get_Name());
		printf("\n%s\n", ((Room*)entities[8])->Get_Description());
		mList<Entity*>::mNode* i = entities[8]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 6)
	{
		player->situation = ((Exit*)entities[17])->destiny;
		printf("\n%s\n", ((Room*)entities[10])->Get_Name());
		mList<Entity*>::mNode* i = entities[10]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
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
	if (player->situation == 2)
	{
		player->situation = ((Exit*)entities[13])->destiny2;
		printf("\n%s\n", ((Room*)entities[1])->Get_Name());
		printf("\nThere is a hole. %s\n", entities[34]->Get_Description());
		mList<Entity*>::mNode* i = entities[1]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 4)
	{
		if (((Room*)entities[4])->door == 1)
		{
			player->situation = ((Exit*)entities[15])->destiny2;
			printf("\n%s\n", ((Room*)entities[2])->Get_Name());
			mList<Entity*>::mNode* i = entities[2]->list.first;
			for (; i != nullptr; i = i->next){
				printf("%s\n", i->data->Get_Name());
			}
			return;
		}
		else if (((Room*)entities[4])->door == 0)
		{
			printf("\nThe door is closed.\n");
		}
	}

	else if (player->situation == 11)
	{
		player->situation = ((Exit*)entities[22])->destiny2;
		printf("\n%s\n", ((Room*)entities[4])->Get_Name());
		mList<Entity*>::mNode* i = entities[4]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 8)
	{
		player->situation = ((Exit*)entities[19])->destiny2;
		printf("\n%s\n", ((Room*)entities[3])->Get_Name());
		mList<Entity*>::mNode* i = entities[3]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
		return;
	}
	else if (player->situation == 10)
	{
		player->situation = ((Exit*)entities[21])->destiny2;
		printf("\n%s\n", ((Room*)entities[6])->Get_Name());
		mList<Entity*>::mNode* i = entities[6]->list.first;
		for (; i != nullptr; i = i->next){
			printf("%s\n", i->data->Get_Name());
		}
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
	if (player->situation == 1) printf("\n%s\n", ((Exit*)entities[12])->Get_Description());
	else if (player->situation == 2) printf("\n%s\n", ((Exit*)entities[13])->Get_Description());
	else if (player->situation == 3) printf("\n%s\n", ((Exit*)entities[21])->Get_Description());
	else if (player->situation == 4) printf("\n%s\n", ((Exit*)entities[15])->Get_Description());
	else if (player->situation == 5) printf("\n%s\n", ((Exit*)entities[22])->Get_Description());
	else if (player->situation == 6) printf("\n%s\n", ((Exit*)entities[14])->Get_Description());
	else if (player->situation == 7) printf("\n%s\n", ((Exit*)entities[13])->Get_Description());
	else if (player->situation == 8) printf("\n%s\n", ((Exit*)entities[17])->Get_Description());
	else if (player->situation == 9) printf("\n%s\n", ((Exit*)entities[18])->Get_Description());
	else if (player->situation == 10) printf("\n%s\n", ((Exit*)entities[19])->Get_Description());
	else if (player->situation == 11) printf("\n%s\n", ((Exit*)entities[20])->Get_Description());
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
	printf("\nUse command 'close' to close the door you oppened.\n");
	printf("\nUse command 'put __ into hole/get__from hole to use the hole.\n");
	printf("\nUse command 'pick/drop <item>' to pick and drop items.\n");
	printf("\nUse command 'equip/unequip<item> to equip and unequip items.\n");
	printf("\nUse command 'hole' to look into the hole.\n");
	printf("\nUse command 'inv/inventory/i' to look into your inventory.\n");
	printf("\nUse command 'stats' to see your stats.\n");
	printf("\nUse command 'buy/sell'+keys/lamp/photo\n");
	printf("\nUse command 'stun/instakill/attack'+basilisk/wizard.\n");
	printf("\nUse command 'talk' to talk with your friend.\n\n");
}

void World::openDoor()
{
	if (player->situation == 2 && ((Room*)entities[2])->door == 0)
	{
		printf("Door opened.\n");
		((Room*)entities[2])->door = 1;
		((Room*)entities[4])->door = 1;

	}
	else if (player->situation == 4 && ((Room*)entities[4])->door == 0)
	{
		printf("Door opened.\n");
		((Room*)entities[4])->door = 1;
		((Room*)entities[2])->door = 1;

	}
	else
	{
		printf("\nAll doors are opened.\n");

	}
}

void World::closeDoor()
{
	if (player->situation == 4 && ((Room*)entities[4])->door == 1){
		printf("The door is closed.\n");
		((Room*)entities[2])->door = 0;
		((Room*)entities[4])->door = 0;

	}
	else if (player->situation == 2 && ((Room*)entities[2])->door == 1)
	{
		printf("The door is closed.\n");
		((Room*)entities[2])->door = 0;
		((Room*)entities[4])->door = 0;
		

	}
	else
	{
		printf("\nYou can't close any door.\n");

	}
}

void World::talkParsel()
{
	if (player->situation == 8)
	{
		if (((Room*)entities[8])->openfountain == 0){
			printf("\nThe fountain is moving...A door just opened on the fountain\n");
			((Room*)entities[8])->openfountain = 1;
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

void World::lookRoomsNorth() const
{

	if (player->situation == 2)
	{
		printf("\nSeems like some time ago there was a door here.\n");
	}
	else if (player->situation == 3)
	{
		printf("\nThere are some stairs going up.\n");
	}
	else if (player->situation == 5)
	{
		printf("\nThere are some stairs going up.\n");
	}
	else if (player->situation == 6)
	{
		printf("\nThere are some stairs going up.\n");
	}
	else if (player->situation == 9)
	{
		printf("\nYou can see the fountain on the middle if the dark.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}
void World::lookRoomsSouth() const
{
	if (player->situation == 2)
	{
		printf("\nThere are a some stairs going down\n");
	}
	else if (player->situation == 3)
	{
		printf("\nThere are a some stairs going down\n");
	}
	else if (player->situation == 5)
	{
		printf("\nThere are a some stairs going down\n");
	}
	else if (player->situation == 7)
	{
		printf("\nA very old door is standing in front of you.\n");
	}
	else if (player->situation == 8)
	{
		printf("\nThere is only the fountain.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}

void World::lookRoomsEast() const
{
	if (player->situation == 1)
	{
		printf("\nThere is a door that leads to the 3rdFloor Rooms\n");
	}
	else if (player->situation == 2)
	{
		printf("\nThere is a closed door.\n");
	}
	else if (player->situation == 4)
	{
		printf("\nThere is an old painting.\n");
	}
	else if (player->situation == 3)
	{
		printf("\nThe door of the bathroom is in front of you.\n");
	}
	else if (player->situation == 6)
	{
		printf("\nThe door of the transformation room is there, watching you.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}

void World::lookRoomsWest() const
{
	if (player->situation == 2)
	{
		printf("\nYou started your search there.\n");
	}
	else if (player->situation == 4)
	{
		printf("\nYou can go to the 3rdFloor stairs.\n");
	}
	else if (player->situation == 11)
	{
		printf("\nThe dark arts room is there.\n");
	}
	else if (player->situation == 8)
	{
		printf("\nYou can go to the 2ndFloor stairs.\n");
	}
	else if (player->situation == 10)
	{
		printf("\nStraight to Low Level.\n");
	}
	else
	{
		printf("\nThere is a high wall you can't climb\n");
	}
}

void World::friendmove(int room)
{
	((Friend*)entities[36])->changeposition(room);
	if (((Friend*)entities[36])->friendposition() == player->situation)
	{
		printf("Your friend joined the room.\n");
	}
}

int World::attack(int kind) const
{
	switch (kind)
	{
	case 1:
		((Basilisk*)entities[35])->modifydefense2(player->giveattack());
		printf("You hit the enemeny.\n");
		player->modifydefense2(((Basilisk*)entities[35])->giveattack());
		printf("The basilisk hit you and dealt 50 dmg.\n");
		if (player->givedefense() == 0)
		{
			printf("The basilisk killed you.\n");
			return 1;
		}
		return 0;
	case 2:
		((Basilisk*)entities[35])->modifydefense2(player->giveattack() + 50);
		printf("You hit the enemeny.\n");
		player->modifydefense2(((Basilisk*)entities[35])->giveattack());
		printf("The basilisk hit you and dealt 50 dmg.\n");
		if (player->givedefense() == 0)
		{
			printf("The basilisk killed you.\n");
			return 1;
		}
		return 0;
	case 3:
		((Basilisk*)entities[35])->modifydefense2(((Basilisk*)entities[35])->givedefense());
		printf("You killed the basilisk.\n");
		printf("The basilisk droped your parents Photo.\n");
		((Room*)entities[9])->list.push_back(entities[30]);
		return 0;
	case 4:
		((Wizard*)entities[37])->modifydefense2(player->giveattack());
		printf("You hit the enemeny.\n");
		player->modifydefense2(((Wizard*)entities[37])->giveattack());
		printf("The DarkWizard hit you and dealt 100 dmg.\n");
		if (((Wizard*)entities[37])->givedefense() == 0)
		{
			printf("Congratulations, you have killed the wizard.\n");;
			return 2;
		}
		if (player->givedefense() == 0)
		{
			printf("The Wizard killed you.\n");
			return 1;
		}
		return 0;
	case 5:
		((Wizard*)entities[37])->modifydefense2(player->giveattack() + 50);
		printf("You hit the enemeny.\n");
		player->modifydefense2(((Wizard*)entities[37])->giveattack());
		printf("The Wizard hit you and dealt 100 dmg.\n");
		if (((Wizard*)entities[37])->givedefense() == 0)
		{
			printf("Congratulations, you have killed the wizard.\n");;
			return 2;
		}
		if (player->givedefense() == 0)
		{
			printf("The DarkWizard killed you.\n");
			return 1;
		}
		return 0;
	case 6:
		((Wizard*)entities[37])->modifydefense2(((Wizard*)entities[37])->givedefense());
		printf("Congratulations, you have killed the wizard.\n");
		return 2;
	default:
		return 5;
	}
	
}
