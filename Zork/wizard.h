#ifndef _WIZARD_
#define _WIZARD_
#include"creature.h"

class Wizard :public Creature
{
public:
	Wizard(const char* str1, const char* str2, int attack, int defense);
	~Wizard();
};

#endif //_WIZARD_