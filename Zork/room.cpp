#include"room.h"

Room::Room(const char* str1, const char* str2) : Entity(str1,str2)
{
	door = 0;
	openfountain = 0;
}
Room::~Room()
{

}