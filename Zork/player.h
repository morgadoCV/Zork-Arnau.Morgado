#ifndef _PLAYER
#define _PLAYER

#include"entity.h"
#include"myvector.h"

class Player:public Entity
{
public:
	int situation;
	mVector<bool> inventory;
public:
	Player(const char* str1, const char* str2, int position);
	~Player();
	void modifybool(int a);
	
};


#endif