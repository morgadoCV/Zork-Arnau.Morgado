#ifndef _FRIEND_
#define _FRIEND_
#include"creature.h"

class Friend :public Creature
{
private:
	const char* talk1;
	const char* talk2;
	int position;
	bool talking = false;
public:
	Friend(const char* str1, const char* str2, int attack, int defense, const char* talk1, const char* talk2, int position);
	Friend();
	~Friend();
	int friendposition()const;
	void changeposition(int room);
	const char* talk(int temp) const;
	bool istalking() const;
	void changetalking();
	

};


#endif //_FRIEND_