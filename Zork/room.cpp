#include"room.h"

Room::Room(const char* str1, const char* str2) : Entity(str1,str2)
{
	door = 0;
	openfountain = 0;
	for (int i = 0; i < 11; i++)
	{
		room_items.push_back(false);
	}
}
Room::~Room()
{
	
}

void Room::set_items(int i1, int i2)
{
	if (i1 != -1)
	{
		room_items[i1] = true;
	}
	if (i2 != -1)
	{
		room_items[i2] = true;
	}
	
}

void Room::modifybool(int a)
{
	if (room_items[a]){ room_items[a] = false; }
	if (room_items[a] == false){ room_items[a] = true; }
	
}