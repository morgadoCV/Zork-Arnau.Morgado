#ifndef _ENTITY_
#define _ENTITY_
#include"mystring.h"

class Entity
{
private:
	mString name;
	mString description;
public:
	Entity();
	Entity(const char* str1, const char* str2);
	~Entity();
	mString Get_Name()const;
	mString Get_Description()const;
	
};


#endif