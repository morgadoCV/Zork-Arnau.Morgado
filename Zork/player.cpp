#include"player.h"

Player::Player(const char* str1, const char* str2,int position):Entity(str1,str2)
{
	situation = position;
	for (int i = 0; i < 11; i++)
	{
		inventory.push_back(false);
	}
}

Player::~Player()
{
}

void Player::modifybool(int a)
{
	if (inventory[a]){ inventory[a] = false; }
	if (inventory[a] == false){ inventory[a] = true; }

}