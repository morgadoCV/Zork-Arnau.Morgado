#ifndef _ENTITY_
#define _ENTITY_
#include"mystring.h"
#include"myvector.h"
#include"mylist.h"

class Entity
{
private:
	mString name;
	mString description;
	int position;
	
	
public:
	mVector<bool> inv;
	mList <Entity*> list;
public:
	Entity();
	Entity(const char* str1, const char* str2);
	Entity(const char* str1, const char* str2,int position);
	~Entity();
	mString Get_Name()const;
	mString Get_Description()const;
	
};


#endif