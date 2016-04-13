#ifndef _PLAYER
#define _PLAYER

#include"entity.h"

class Player:public Entity
{
public:
	int situation;
public:
	Player(const char* str1, const char* str2, int position);
	~Player();
};


#endif