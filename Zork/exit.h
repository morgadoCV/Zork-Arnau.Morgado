#ifndef _EXIT
#define _EXIT

#include"entity.h"

class Exit:public Entity
{
public:
	int destiny,destiny2,destiny3,destiny4;
public:
	Exit(const char* str1, const char*str2, int a, int b, int c, int d);
};


#endif