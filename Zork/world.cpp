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
	/*0*/entities.push_back(new Player("Unknown", "As you would know you are at Hogwarts, School of Witchcraft and Wizary.We found you unconscious last night on the top of the north tower's steps, we don't know what happened to you..\n You are at the sickroom, you must investigate what happened to you, maybe a dark wizard is in the castle..",1));
	player = (Player*)entities[0];
	
	//rooms
	
	/*1*//*0*/entities.push_back(new Room("Starting Room.\n", "You can see a room when you look at east.There is a broom."));
	/*2*//*1*/entities.push_back(new Room("3rd Floor.\n", "There are stair going down on south and a closed room east, it seems very cold.\n"));
	/*3*//*2*/entities.push_back(new Room("2nd floor.\n", "You can go east to the bathroom and south downstairs to 1st floor.\nThere is a lantern on the floor.\n"));
	/*4*//*3*/entities.push_back(new Room("Dark arts room.\n", "There is an old painting of Salazar Slytherin. You can also see a wand over the table and a heavy layer behind the door.\n"));
	/*5*//*4*/entities.push_back(new Room("1st floor.\n", "There is a layer on the floor. The only way you can go is south, straight to the low level.\n"));
	/*6*//*5*/entities.push_back(new Room("Low Level.\n", "You can only go east, to the transformation room.\n"));
	/*7*//*6*/entities.push_back(new Room("Room of requirements.\n", "Wait..Where are you? You can see a book over a table."));
	/*8*//*7*/entities.push_back(new Room("Bathroom\n", "You found your friend Arnau. There is an old fountain with what seem snakes \narround it.\n"));
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
	/*24*/entities.push_back(new Item("Instakill Book", "Seems like you can read it."));
	/*25*/entities.push_back(new Item("Layer", "Maybe you can equip it."));
	/*26*/entities.push_back(new Item("Time Turner", "It gives you the hability to teleport throw rooms you have been before."));
	/*27*/entities.push_back(new Item("Keys", "Just some keys."));
	/*28*/entities.push_back(new Item("Lamp", "It will show you the light."));
	/*29*/entities.push_back(new Item("Goddreic's Griffindor sword", "Some books say that it can kill magic creatures."));
	/*30*/entities.push_back(new Item("Photo", "It is an old photo of you and your parents, what is it doing here?."));
	/*31*/entities.push_back(new Item("Broom", "An old Broom, maybe you can fly with it, who knows?"));
	/*32*/entities.push_back(new Item("Heavy Layer", "Maybe you can equip it."));
	/*33*/entities.push_back(new Item("Stun Book", "Just read it."));

	//giving items to rooms
	((Room*)entities[1])->set_items(8, -1);
	((Room*)entities[2])->set_items(-1, -1);
	((Room*)entities[3])->set_items(5, -1);
	((Room*)entities[4])->set_items(9, 0);
	((Room*)entities[5])->set_items(2, -1);
	((Room*)entities[6])->set_items(-1, -1);
	((Room*)entities[7])->set_items(10, -1);
	((Room*)entities[8])->set_items(3, -1);
	((Room*)entities[9])->set_items(1, 7);
	((Room*)entities[10])->set_items(4, 6);
	((Room*)entities[11])->set_items(-1, -1);

	//hole

	hole.push_back(new Entity("There is a hole", "Seems like you can put thinks into it",0));
	

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
		if (((Room*)entities[player->situation])->room_items[0])
		{
			((Room*)entities[player->situation])->modifybool(0);
			player->modifybool(0);
			printf("You have picked the wand.\n");
			((Room*)entities[player->situation])->room_items[0] = false;
			
		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
		return 0;
	}
	
	else if (comand == "pick instakill book")
	{
		if (((Room*)entities[player->situation])->room_items[1])
		{
			((Room*)entities[player->situation])->modifybool(1);
			player->modifybool(1);
			printf("You have picked the instakill book.\n");
			((Room*)entities[player->situation])->room_items[1] = false;
			player->modifyattack(500);
		}
		
		else
		{
			printf("You can't find this item at this room.\n");
		}
		return 0;
	}
	else if (comand == "pick layer")
	{
		if (((Room*)entities[player->situation])->room_items[2])
		{
			((Room*)entities[player->situation])->modifybool(2);
			player->modifybool(2);
			printf("You have picked the layer.\n");
			((Room*)entities[player->situation])->room_items[2] = false;
			player->modifydefense(300);
		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
		return 0;
	}
	else if (comand == "pick time turner")
	{
		if (((Room*)entities[player->situation])->room_items[3])
		{
			((Room*)entities[player->situation])->modifybool(3);
			player->modifybool(3);
			printf("You have picked the time turner.\n");
			((Room*)entities[player->situation])->room_items[3] = false;
		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
		return 0;
	}
	else if (comand == "pick keys")
	{
		if (((Room*)entities[player->situation])->room_items[4])
		{
			((Room*)entities[player->situation])->modifybool(4);
			player->modifybool(4);
			printf("You have picked the keys.\n");
			((Room*)entities[player->situation])->room_items[4] = false;
		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
		return 0;
	}
	else if (comand == "pick lantern")
	{
		if (((Room*)entities[player->situation])->room_items[5])
		{
			((Room*)entities[player->situation])->modifybool(5);
			player->modifybool(5);
			printf("You have picked the lamp.\n");
			((Room*)entities[player->situation])->room_items[5] = false;
		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
		return 0;
	}
	else if (comand == "pick sword")
	{
		if (((Room*)entities[player->situation])->room_items[6])
		{
			((Room*)entities[player->situation])->modifybool(6);
			player->modifybool(6);
			printf("You have picked the sword.\n");
			((Room*)entities[player->situation])->room_items[6] = false;
		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
		return 0;
	}
	else if (comand == "pick photo")
	{
		if (((Room*)entities[player->situation])->room_items[7])
		{
			((Room*)entities[player->situation])->modifybool(7);
			player->modifybool(7);
			printf("You have picked the photo.\n");
			((Room*)entities[player->situation])->room_items[7] = false;
		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
		return 0;
	}
	else if (comand == "pick broom")
	{
		if (((Room*)entities[player->situation])->room_items[8])
		{
			printf("This isn't the time to use that! Do you wanna fly into the school?\n");
		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
		return 0;
	}
	else if (comand == "pick heavy layer")
	{
		if (((Room*)entities[player->situation])->room_items[9])
		{
			printf("It is to heavy!!");
		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
		return 0;
	}
	else if (comand == "pick stun book")
	{
		if (((Room*)entities[player->situation])->room_items[10])
		{
			((Room*)entities[player->situation])->modifybool(10);
			player->modifybool(10);
			printf("You have picked the stun book.\n");
			((Room*)entities[player->situation])->room_items[10] = false;
			player->modifyattack(50);
		}
		else
		{
			printf("You can't find this item at this room.\n");
		}
		return 0;
	}
	else if (comand == "drop wand")
	{
		if (player->inventory[0])
		{
			player->inventory[0] = false;
			printf("You have droped the wand.\n");
			((Room*)entities[player->situation])->room_items[0] = true;
			
		}
		else
		{
			printf("You don't have this item.\n");
		}
		return 0;
	}
	else if (comand == "drop instakill book")
	{
		if (player->inventory[1])
		{
			player->inventory[1] = false;
			printf("You have droped the isntakill book.\n");
			((Room*)entities[player->situation])->room_items[1] = true;
			player->modifyattack2(500);
		}
		else
		{
			printf("You don't have this item.\n");
		}
		return 0;
	}
	else if (comand == "drop layer")
	{
		if (player->inventory[2])
		{
			player->inventory[2] = false;
			printf("You have droped the layer.\n");
			((Room*)entities[player->situation])->room_items[2] = true;
			
		
		}
		else
		{
			printf("You don't have this item.\n");
		}
		return 0;
	}
	else if (comand == "drop time turner")
	{
		if (player->inventory[3])
		{
			player->inventory[3] = false;
			printf("You have droped the time turner.\n");
			((Room*)entities[player->situation])->room_items[3] = true;
		}
		else
		{
			printf("You don't have this item.\n");
		}
		return 0;
	}
	else if (comand == "drop keys")
	{
		if (player->inventory[4])
		{
			player->inventory[4] = false;
			printf("You have droped the keys.\n");
			((Room*)entities[player->situation])->room_items[4] = true;
		}
		else
		{
			printf("You don't have this item.\n");
		}
		return 0;
	}
	else if (comand == "drop lantern")
	{
		if (player->inventory[5])
		{
			player->inventory[5] = false;
			printf("You have droped the lantern.\n");
			((Room*)entities[player->situation])->room_items[5] = true;
		}
		else
		{
			printf("You don't have this item.\n");
		}
		return 0;
	}
	else if (comand == "drop sword")
	{
		if (player->inventory[6])
		{
			player->inventory[6] = false;
			printf("You have droped the sword.\n");
			((Room*)entities[player->situation])->room_items[6] = true;
			
		}
		else
		{
			printf("You don't have this item.\n");
		}
		return 0;
	}
	else if (comand == "drop photo")
	{
		if (player->inventory[7])
		{
			player->inventory[7] = false;
			printf("You have droped the photo.\n");
			((Room*)entities[player->situation])->room_items[7] = true;
		}
		else
		{
			printf("You don't have this item.\n");
		}
		return 0;
	}
	else if (comand == "drop stun book")
	{
		if (player->inventory[10])
		{
			player->inventory[10] = false;
			printf("You have droped the stun book.\n");
			((Room*)entities[player->situation])->room_items[10] = true;
			player->modifyattack2(50);
		}
		else
		{
			printf("You don't have this item.\n");
		}
		return 0;
	}
	else if (comand == "i"||comand=="inventory"||comand=="inv")
	{
		for (int i = 0; i < 1; i++)
		{
			if (player->inventory[i])
			{
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
			}
		}
		return 0;
		
	}
	
	else if (comand == "look wand")
	{ 
		if (player->inventory[0] || ((Room*)entities[player->situation])->room_items[0])
		{
			printf("\n%s\n", ((Item*)entities[23])->Get_Description());
		}
		else
		{
			printf("You can't see this item.");
		}
		return 0;
	}
	else if (comand == "look instakill book")
	{
		if (player->inventory[1] || ((Room*)entities[player->situation])->room_items[1])
		{
			printf("\n%s\n", ((Item*)entities[24])->Get_Description());
			
		}
		else
		{
			printf("You can't see this item.");
		}
		return 0;
	}
	else if (comand == "look layer")
	{
		if (player->inventory[2] || ((Room*)entities[player->situation])->room_items[2])
		{
			printf("\n%s\n", ((Item*)entities[25])->Get_Description());
		}
		else
		{
			printf("You can't see this item.");
		}
		return 0;
	}
	else if (comand == "look time turner")
	{
		if (player->inventory[3] || ((Room*)entities[player->situation])->room_items[3])
		{
			printf("\n%s\n", ((Item*)entities[26])->Get_Description());
		}
		else
		{
			printf("You can't see this item.");
		}
		return 0;
	}
	else if (comand == "look keys")
	{
		if (player->inventory[4] || ((Room*)entities[player->situation])->room_items[4])
		{
			printf("\n%s\n", ((Item*)entities[27])->Get_Description());
		}
		else
		{
			printf("You can't see this item.");
		}
		return 0;
	}
	else if (comand == "look lantern")
	{
		if (player->inventory[5] || ((Room*)entities[player->situation])->room_items[5])
		{
			printf("\n%s\n", ((Item*)entities[28])->Get_Description());
		}
		else
		{
			printf("You can't see this item.");
		}
		return 0;
	}
	else if (comand == "look sword")
	{
		if (player->inventory[6] || ((Room*)entities[player->situation])->room_items[6])
		{
			printf("\n%s\n", ((Item*)entities[29])->Get_Description());
		}
		else
		{
			printf("You can't see this item.");
		}
		return 0;
	}
	else if (comand == "look photo")
	{
		if (player->inventory[7] || ((Room*)entities[player->situation])->room_items[7])
		{
			printf("\n%s\n", ((Item*)entities[30])->Get_Description());
		}
		else
		{
			printf("You can't see this item.");
		}
		return 0;
	}
	else if (comand == "look broom")
	{
		if (player->inventory[8] || ((Room*)entities[player->situation])->room_items[8])
		{
			printf("\n%s\n", ((Item*)entities[31])->Get_Description());
		}
		else
		{
			printf("You can't see this item.");
		}
		return 0;
	}
	else if (comand == "look heavy layer")
	{
		if (player->inventory[9] || ((Room*)entities[player->situation])->room_items[9])
		{
			printf("\n%s\n", ((Item*)entities[32])->Get_Description());
		}
		else
		{
			printf("You can't see this item.");
		}
		return 0;
	}
	else if (comand == "look stun book")
	{
		if (player->inventory[10] || ((Room*)entities[player->situation])->room_items[10])
		{
			printf("\n%s\n", ((Item*)entities[33])->Get_Description());
		}
		else
		{
			printf("You can't see this item.");
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
		if (player->inventory[0])
		{
			player->equipement[0] = true;
			player->inventory[0] = false;
			player->modifyattack(50);
			printf("Wand equip.\n");
		}
		else{ printf("There is not a wand on your inventory.\n"); }
		return 0;
	}
	else if (comand == "equip sword")
	{
		if (player->inventory[6])
		{
			player->equipement[1] = true;
			player->inventory[6] = false;
			player->modifyattack(15);
			printf("Sword equip.\n");
		}
		else{ printf("There is not a wand on your inventory.\n"); }
		return 0;
	}
	else if (comand == "equip layer")
	{
		if (player->inventory[2])
		{
			player->equipement[2] = true;
			player->inventory[2] = false;
			player->modifydefense(300);
			printf("Layer equip.\n");
		}
		else{ printf("There is not a layer on your inventory.\n"); }
		return 0;
	}
	else if (comand == "unequip wand")
	{
		if (player->equipement[0])
		{
			player->inventory[0] = true;
			player->equipement[0] = false;
			player->modifyattack2(50);
			printf("Wand unequip.\n");
		}
		else{ printf("Wand not equip.\n"); }
		return 0;
	}
	else if (comand == "unequip sword")
	{
		if (player->equipement[1])
		{
			player->equipement[1] = false;
			player->inventory[6] = true;
			player->modifyattack2(15);
			printf("Sword unequip.\n");
		}
		else{ printf("Sword not equip.\n"); }
		return 0;
	}
	else if (comand == "unequip layer")
	{
		if (player->equipement[2])
		{
			player->equipement[2] = false;
			player->inventory[2] = true;
			player->modifydefense2(300);
			printf("Layer unequip.\n");
		}
	   else{ printf("Layer not equip.\n"); }
	   return 0;
	}
	else if (comand == "put wand into hole")
	{
		if (player->situation == 1 && player->inventory[0])
		{
			player->inventory[0] = false;
			hole[0]->inv[0] = true;
		}
		return 0;
	}
	else if (comand == "put instakill book into hole")
	{
		if (player->situation == 1 && player->inventory[1])
		{
			player->inventory[1] = false;
			hole[0]->inv[1] = true;
		}
		return 0;
	}
	else if (comand == "put layer into hole")
	{
		if (player->situation == 1 && player->inventory[2])
		{
			player->inventory[2] = false;
			hole[0]->inv[2] = true;
		}
		return 0;
	}
	else if (comand == "put keys into hole")
	{
		if (player->situation == 1 && player->inventory[4])
		{
			player->inventory[4] = false;
			hole[0]->inv[4] = true;
		}
		return 0;
	}
	else if (comand == "put lantern into hole")
	{
		if (player->situation == 1 && player->inventory[5])
		{
			player->inventory[5] = false;
			hole[0]->inv[5] = true;
		}
		return 0;
	}
	else if (comand == "put sword into hole")
	{
		if (player->situation == 1 && player->inventory[6])
		{
			player->inventory[6] = false;
			hole[0]->inv[6] = true;
		}
		return 0;
	}
	else if (comand == "put photo into hole")
	{
		if (player->situation == 1 && player->inventory[7])
		{
			player->inventory[7] = false;
			hole[0]->inv[7] = true;
		}
		return 0;
	}
	else if (comand == "put stun book into hole")
	{
		if (player->situation == 1 && player->inventory[10])
		{
			player->inventory[10] = false;
			hole[0]->inv[10] = true;
		}
		return 0;
	}
	else if (comand == "get wand from hole")
	{
		if (player->situation == 1)
		{
			if (hole[0]->inv[0])
			{
				player->inventory[0] = true;
				hole[0]->inv[0] = false;
			}
		}
		return 0;
	}
	else if (comand == "get instakill book from hole")
	{
		if (player->situation == 1)
		{
			if (hole[0]->inv[1])
			{
				player->inventory[1] = true;
				hole[0]->inv[1] = false;
			}
		}
		return 0;
	}
	else if (comand == "get layer from hole")
	{
		if (player->situation == 1)
		{
			if (hole[0]->inv[2])
			{
				player->inventory[2] = true;
				hole[0]->inv[2] = false;
			}
		}
		return 0;
	}
	else if (comand == "get keys from hole")
	{
		if (player->situation == 1)
		{
			if (hole[0]->inv[4])
			{
				player->inventory[4] = true;
				hole[0]->inv[4] = false;
			}
		}
		return 0;
	}
	else if (comand == "get lantern from hole")
	{
		if (player->situation == 1)
		{
			if (hole[0]->inv[5])
			{
				player->inventory[5] = true;
				hole[0]->inv[5] = false;
			}
		}
		return 0;
	}
	else if (comand == "get sword from hole")
	{
		if (player->situation == 1)
		{
			if (hole[0]->inv[6])
			{
				player->inventory[6] = true;
				hole[0]->inv[6] = false;
			}
		}
		return 0;
	}
	else if (comand == "get photo from hole")
	{
		if (player->situation == 1)
		{
			if (hole[0]->inv[7])
			{
				player->inventory[7] = true;
				hole[0]->inv[7] = false;
			}
		}
		return 0;
	}
	else if (comand == "get stun book from hole")
	{
		if (player->situation == 1)
		{
			if (hole[0]->inv[10])
			{
				player->inventory[10] = true;
				hole[0]->inv[10] = false;
			}
		}
		return 0;
	}
	else if (comand == "hole")
	{
		printf("\nHole inv:\n");
		for (int i = 0; i < 11; i++)
		{
			if (hole[0]->inv[i])
			{
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
			}
		}
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
	if (player->situation == 2)
	{
		player->situation = ((Exit*)entities[13])->destiny3;
		printf("\n%s\n", ((Room*)entities[7])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[7])->room_items[i]==true)
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 3)
	{
		player->situation = ((Exit*)entities[14])->destiny3;
		printf("\n%s\n", ((Room*)entities[2])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[2])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 5)
	{
		player->situation = ((Exit*)entities[16])->destiny3;
		printf("%s\n", ((Room*)entities[3])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[3])->room_items[i])
				printf("%s\n", ((Item*)entities[i + 23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 6)
	{
		player->situation = ((Exit*)entities[17])->destiny3;
		printf("\n%s\n", ((Room*)entities[5])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[5])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 9)
	{
		player->situation = ((Exit*)entities[20])->destiny3;
		printf("\n%s\n", ((Room*)entities[8])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[8])->room_items[i])
				printf("%s\n", ((Item*)entities[i + 23])->Get_Name());
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
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[3])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 7)
	{
		player->situation = ((Exit*)entities[18])->destiny4;
		printf("\n%s\n", ((Room*)entities[2])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[2])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 3)
	{
		player->situation = ((Exit*)entities[14])->destiny4;;
		printf("\n%s\n", ((Room*)entities[5])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[5])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 5)
	{
		player->situation = ((Exit*)entities[16])->destiny4;
		printf("\n%s\n", ((Room*)entities[6])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[6])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 8)
	{
		if (((Room*)entities[8])->openfountain == 1){
			player->situation = ((Exit*)entities[19])->destiny4;
			printf("\n%s\n", ((Room*)entities[9])->Get_Name());
			for (int i = 0; i < 11; i++){
				if (((Room*)entities[9])->room_items[i])
					printf("%s\n", ((Item*)entities[i+23])->Get_Name());
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
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[2])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 2)
	{
		if (((Room*)entities[2])->door == 1)
		{
			player->situation = ((Exit*)entities[13])->destiny;
			printf("\n%s\n", ((Room*)entities[4])->Get_Name());
			for (int i = 0; i < 11; i++){
				if (((Room*)entities[4])->room_items[i])
					printf("%s\n", ((Item*)entities[i+23])->Get_Name());
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
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[11])->room_items[i])
				printf("%s\n", ((Item*)entities[i + 23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 3)
	{
		player->situation = ((Exit*)entities[14])->destiny;
		printf("\n%s\n", ((Room*)entities[8])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[8])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 6)
	{
		player->situation = ((Exit*)entities[17])->destiny;
		printf("\n%s\n", ((Room*)entities[10])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[10])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
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
		printf("\nThere is a hole. %s\n", hole[0]->Get_Description());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[1])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 4)
	{
		if (((Room*)entities[4])->door == 1)
		{
			player->situation = ((Exit*)entities[15])->destiny2;
			printf("\n%s\n", ((Room*)entities[2])->Get_Name());
			for (int i = 0; i < 11; i++){
				if (((Room*)entities[2])->room_items[i])
					printf("%s\n", ((Item*)entities[i+23])->Get_Name());
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
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[4])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 8)
	{
		player->situation = ((Exit*)entities[19])->destiny2;
		printf("\n%s\n", ((Room*)entities[3])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[3])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
		}
		return;
	}
	else if (player->situation == 10)
	{
		player->situation = ((Exit*)entities[21])->destiny2;
		printf("\n%s\n", ((Room*)entities[6])->Get_Name());
		for (int i = 0; i < 11; i++){
			if (((Room*)entities[6])->room_items[i])
				printf("%s\n", ((Item*)entities[i+23])->Get_Name());
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
	printf("\nUse command 'stats' to see your stats.\n\n");
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

