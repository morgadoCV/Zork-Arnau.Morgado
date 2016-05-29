#ifndef _FRIEND_
#define _FRIEND_
#include"creature.h"

class Friend :public Creature
{
private:
	const char* talk1;
	const char* talk2;
	int position;
public:
	Friend(const char* str1, const char* str2, int attack, int defense, const char* talk1, const char* talk2, int position);
	~Friend();
	int friendposition()const;
	const char* talk(int temp) const;

};


#endif //_FRIEND_