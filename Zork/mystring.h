
#ifndef _STRING_CLASS_
#define _STRING_CLASS_
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

class mString
{
private:
	char* buffer = nullptr;
	unsigned int reservedmemory;
public:
	mString()
	{
		reservedmemory = 1;
		buffer = new char[reservedmemory];
		strcpy_s(buffer, reservedmemory, "");
	}

	mString(const char* str)
	{
		int len = strlen(str);
		reservedmemory = len + 1;
		buffer = new char[len + 1];
		strcpy_s(buffer, len + 1, str);

	}
	mString(const mString& str)
	{
		int len = strlen(str.buffer);
		reservedmemory = len + 1;
		buffer = new char[len + 1];
		strcpy_s(buffer, len + 1, str.buffer);

	}
	~mString()
	{
		delete[]buffer;
	}
	unsigned int lenght() const
	{
		return strlen(buffer);
	}
	const char* c_str() const
	{
		return buffer;
	}
	bool empty() const
	{
		return strlen(buffer) == 0;
	}
	bool operator==(mString& str) const
	{
		return strcmp(str.buffer, buffer) == 0;
	}
	bool operator==(const char* str) const
	{
		return strcmp(str, buffer) == 0;
	}
	/*void operator+=(const mString& str)
	{
		unsigned int memory_i_need = lenght() + str.lenght() + 1;
		if (memory_i_need > reservedmemory)
		{
			char* temp = nullptr;
			temp = new char[memory_i_need];
			strcat_s(temp, reservedmemory, buffer);
			delete[]buffer;
			buffer = new char[memory_i_need];
			buffer = temp;
			delete[]temp;

		}
		strcat_s(buffer, str.reservedmemory, str.buffer);
	}*/
	void operator+=(const char* str);
	void operator=(const mString& str)
	{

		if (str.reservedmemory == reservedmemory) strcpy_s(buffer, str.reservedmemory, str.buffer);
		else if (str.reservedmemory < reservedmemory) strcpy_s(buffer, str.reservedmemory, str.buffer);
		else{
			delete[]buffer;
			reservedmemory = str.reservedmemory;
			buffer = new char[str.reservedmemory];
			strcpy_s(buffer, str.reservedmemory, str.buffer);
		}
	}
	void operator=(const char* str)
	{

		if (strlen(str) + 1 == reservedmemory) strcpy_s(buffer, strlen(str) + 1, str);
		else if (strlen(str) + 1 < reservedmemory) strcpy_s(buffer, strlen(str) + 1, str);
		else{
			delete[]buffer;
			reservedmemory = strlen(str) + 1;
			buffer = new char[strlen(str) + 1];
			strcpy_s(buffer, strlen(str) + 1, str);
		}
	}
	
	unsigned int capacity()const
	{
		return reservedmemory;
	}
	char* give_str()
	{
		return buffer;
	}
	
};

#endif //_STRING_CLASS_



