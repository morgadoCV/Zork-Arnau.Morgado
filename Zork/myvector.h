#ifndef _NEW_H_
#define _NEW_H_

typedef unsigned int uint;
#include<assert.h>
#include<stdio.h>


template <class TYPE>
class mVector
{
private:
	TYPE* my_array = nullptr;
	uint capacity = 10;
	uint num_elements = 0;

public:
	//contructor deconstructor
	mVector()
	{
		my_array = new TYPE[capacity];
	}
	mVector(const mVector& other)
	{
		num_elements = other.num_elements;
		capacity = other.capacity;
		my_array = new TYPE[capacity];
		for (uint i = 0; i < num_elements; i++)
		{
			my_array[i] = other.my_array[i];
		}

	}
	mVector(uint size) :capacity(size)
	{
		num_elements = size;
		my_array = new TYPE[capacity];

	}
	~mVector()
	{
		delete[]my_array;
	}
	//operators
	TYPE& operator[](uint i)
	{
		assert(i < num_elements);
		return my_array[i];
	}
	TYPE& operator[](uint i) const
	{
		assert(i < num_elements);
		return my_array[i];
	}
	//modifiers
	void push_back(const TYPE num)
	{
		if (num_elements >= capacity)
		{
			TYPE* temp;
			capacity += 20;
			temp = new TYPE[capacity];
			for (int i = 0; i < num_elements; ++i)
			{
				temp[i] = my_array[i];
			}
			delete[]my_array;
			my_array = temp;
		}

		my_array[num_elements++] = num;

	}
	void push_front(const TYPE num)
	{
		num_elements++;
		if (num_elements >= capacity)
		{
			TYPE* temp;
			capacity += 20;
			temp = new TYPE[capacity];
			for (int i = 0; i < num_elements; ++i)
			{
				temp[i] = my_array[i];
			}
			delete[]my_array;
			my_array = temp;
		}

		for (int i = num_elements; i >0; --i)
		{
			my_array[i - 1] = my_array[i - 2];
		}

		my_array[0] = num;

	}


	//other functions
	uint size() const
	{
		return num_elements;
	}
	uint mycapacity() const
	{
		return capacity;
	}
	bool empty() const
	{
		return num_elements == 0;
	}
	void clear()
	{
		num_elements = 0;
	}
	bool pop_back(TYPE& value)
	{
		if (num_elements > 0)
		{
			num_elements--;
			value = my_array[num_elements];
			return true;
		}
		else if (num_elements == NULL)
		{
			printf("Ets un matat\n");
			return false;
		}

	}

};



#endif
