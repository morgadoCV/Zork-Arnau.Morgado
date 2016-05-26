#ifndef _BASILISK_
#define _BASILISK_
#include"creature.h"

class Basilisk :public Creature
{
public:
	Basilisk(const char* str1, const char* str2, int attack, int defense);
	~Basilisk();
};


#endif //_BASILISK_
