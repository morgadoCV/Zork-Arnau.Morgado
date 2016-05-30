#include"friend.h"
#include"creature.h"

Friend::Friend(const char* str1, const char* str2, int attack, int defense,const char* talk1, const char* talk2, int position) :Creature(str1,str2,attack,defense)
{
	this->talk1 = talk1;
	this->talk2 = talk2;
	this->position = position;
}
Friend::Friend(){}
Friend::~Friend(){}

int Friend::friendposition() const
{
	return position;
}
const char* Friend::talk(int temp) const
{
	switch (temp)
	{
	case 0:
		return talk1;
	case 1:
		return talk2;
	}
	

	return "error";
}

bool Friend::istalking() const
{
	return talking;
	
}

void Friend::changetalking()
{
	if (talking == false){ talking = true; }
	if (talking){ talking = false; }
}

void Friend::changeposition(int room)
{
	position = room;
}

bool Friend::isbuying() const
{
	return buying;
}
void Friend::changebuying()
{
	if (buying == false){ buying = true; }
	if (buying){ buying = false; }
	
}