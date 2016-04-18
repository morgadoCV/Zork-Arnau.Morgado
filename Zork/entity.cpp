#include"entity.h"

Entity::Entity(const char* str1,const char* str2) : name(str1), description(str2)
{
	
}
Entity::Entity(const char* str1, const char* str2,int position) : name(str1), description(str2)
{
	this->position = position;
	for (int i = 0; i < 11; i++)
	{
		inv.push_back(false);
	}
}
Entity::Entity()
{
}
Entity::~Entity()
{
}

mString Entity::Get_Name() const
{
	return name;
}

mString Entity::Get_Description()const
{
	return description;
}