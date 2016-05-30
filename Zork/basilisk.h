#ifndef _BASILISK_
#define _BASILISK_
#include"creature.h"

enum basilisk_state
{
	STATE_DEFENSE,
	STATE_ATTACK,
	STATE_DEAD,
	STATE_ERROR
};

class Basilisk :public Creature
{
public:
	Basilisk(const char* str1, const char* str2, int attack, int defense);
	~Basilisk();

};


#endif //_BASILISK_
