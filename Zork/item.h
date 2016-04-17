#ifndef _ITEM
#define _ITEM

#include "entity.h"

class Item :public Entity
{
public:
	Item(const char* str1, const char* str2);
	~Item();

};

#endif