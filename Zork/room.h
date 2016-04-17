#ifndef _ROOM
#define _ROOM

#include"entity.h"
#include"myvector.h"

class Room:public Entity
{
public:
	int door, openfountain;
	mVector<bool> room_items;
public:
	Room(const char* str1,const char* str2);
	~Room();
	void set_items(int i1, int i2); 
	void modifybool(int a);
};




#endif