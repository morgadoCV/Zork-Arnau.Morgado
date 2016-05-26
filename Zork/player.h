#ifndef _PLAYER
#define _PLAYER

#include"entity.h"
#include"myvector.h"
#include"creature.h"

class Player:public Creature
{

public:
	int situation;
	mList<Entity*>equip;
	mVector<bool> equipement;
	

public:
	Player(const char* str1, const char* str2, int position,int attack, int defense);
	~Player();
	void modifybool(int a);
	//void modifyattack(int at);
	//void modifyattack2(int at);
	//void modifydefense(int def);
	//void modifydefense2(int def);
	//int giveattack();
	//int givedefense();
};


#endif