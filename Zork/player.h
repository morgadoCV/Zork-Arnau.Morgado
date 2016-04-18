#ifndef _PLAYER
#define _PLAYER

#include"entity.h"
#include"myvector.h"

class Player:public Entity
{
private:
	int attack, defense;
public:
	int situation;
	mVector<bool> inventory;
	mVector<bool> equipement;
	

public:
	Player(const char* str1, const char* str2, int position);
	~Player();
	void modifybool(int a);
	void modifyattack(int at);
	void modifyattack2(int at);
	void modifydefense(int def);
	void modifydefense2(int def);
	int giveattack();
	int givedefense();
};


#endif