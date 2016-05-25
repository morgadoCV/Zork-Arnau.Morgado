#ifndef _CREATURE_
#define _CREATURE_
#include "entity.h"

class Creature :public Entity
{
private:
	int attack, defense;
public:
	Creature(const char* str1,const char* str2,int attack, int defense);
	~Creature();
	void modifybool(int a);
	void modifyattack(int at);
	void modifyattack2(int at);
	void modifydefense(int def);
	void modifydefense2(int def);
	int giveattack();
	int givedefense();
};


#endif //_CREATURE_