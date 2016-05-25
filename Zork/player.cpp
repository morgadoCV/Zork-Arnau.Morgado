#include"player.h"

Player::Player(const char* str1, const char* str2,int position,int attack, int defense):Creature(str1,str2,attack,defense)
{
	situation = position;
	for (int i = 0; i < 11; i++)
	{
		inventory.push_back(false);
	}
	for (int i = 0; i < 3; i++)
	{
		equipement.push_back(false);
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



