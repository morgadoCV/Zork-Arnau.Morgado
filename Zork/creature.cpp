#include"creature.h"

Creature::Creature(const char* str1, const char* str2, int at, int def) :Entity(str1, str2)
{
	attack = at;
	defense = def;
}

void Creature::modifyattack(int at)
{
	attack += at;
}

void Creature::modifydefense(int def)
{
	defense += def;
}

int Creature::giveattack()
{
	return attack;
}

int Creature::givedefense()
{
	return defense;
}

void Creature::modifyattack2(int at)
{
	attack -= at;
}

void Creature::modifydefense2(int def)
{
	defense -= def;
}

Creature::~Creature(){}