#include"entity.h"

Entity::Entity(const char* str1,const char* str2) : name(str1), description(str2)
{
}

Entity::~Entity()
{
}

mString Entity::Get_Name()const
{
	return name;
}

mString Entity::Get_Description()const
{
	return description;
}