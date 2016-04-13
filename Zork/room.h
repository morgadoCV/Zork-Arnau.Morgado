#ifndef _ROOM
#define _ROOM

#include"entity.h"

class Room:public Entity
{
public:
	Room(const char* str1,const char* str2);
	~Room();
};




#endif