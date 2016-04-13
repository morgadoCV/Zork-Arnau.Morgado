#include"player.h"

Player::Player(const char* str1, const char* str2,int position):Entity(str1,str2)
{
	situation = position;
}

Player::~Player()
{
}
