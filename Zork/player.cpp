#include"player.h"
#include"creature.h"

Player::Player(const char* str1, const char* str2,int position,int attack, int defense):Creature(str1,str2,attack,defense)
{
	situation = position;
}

Player::~Player()
{
}


