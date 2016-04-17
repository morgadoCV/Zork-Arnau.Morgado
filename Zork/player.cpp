#include"player.h"

Player::Player(const char* str1, const char* str2,int position):Entity(str1,str2)
{
	situation = position;
	attack = 100;
	defense = 50;
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

void Player::modifyattack(int at)
{
	attack += at;
}

void Player::modifydefense(int def)
{
	defense += def;
}

int Player::giveattack()
{
	return attack;
}

int Player::givedefense()
{
	return defense;
}

void Player::modifyattack2(int at)
{
	attack -= at;
}

void Player::modifydefense2(int def)
{
	defense -= def;
}

