#ifndef _FRIEND_
#define _FRIEND_
#include"creature.h"

class Friend :public Creature
{
public:
	Friend(const char* str1, const char* str2, int attack, int defense);
	~Friend();
};


#endif //_FRIEND_