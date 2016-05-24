#ifndef _MY_LIST_
#define _MY_LIST_

typedef unsigned int uint;

template<class TYPE>
class mList
{
public:

	struct mNode
	{
		TYPE data;
		mNode* next = nullptr;
		mNode* prev = nullptr;

		mNode(const TYPE& data) :data(data){}
		~mNode(){}
	};

	mNode* first = nullptr;

public:
	mList(){};
	~mList(){};

	bool empty() const
	{
		return first == nullptr;
	}

	uint size() const
	{
		uint n_elements = 0;
		mNode* temp = first;
		while (temp != nullptr)
		{
			temp = temp->next;
			n_elements++;
		}
		return n_elements;
	}

	mNode* end() const
	{
		mNode* temp = first;

		if (temp != nullptr)
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
		}
		return temp;
	}

	void push_back(const TYPE& data)
	{
		mNode* temp = first;
		mNode* new_node = new mNode(data);

		if (temp == nullptr)
		{
			first = new_node;
		}

		else
		{
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new_node;
			new_node->prev = temp;
		}
	}

	void push_front(const TYPE& data)
	{
		mNode* new_node = new mNode(data);

		if (first == nullptr)
		{
			first = new_node;
		}

		else
		{
			new_node->next = first;
			first->prev = new_node;
			first = new_node;
		}
	}

	bool pop_back()
	{
		if (first != nullptr)
		{
			if (first->next != nullptr)
			{
				mNode* temp = first;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->prev->next = nullptr;
				delete temp;
			}
			else //size = 1
			{
				mNode* temp = first;
				first = nullptr;
				delete temp;
			}
			return true;
		}
		return false;
	}

	bool pop_front()
	{
		if (first != nullptr)
		{
			if (first->next != nullptr)
			{
				mNode* temp = first;
				first = temp->next;
				first->prev = nullptr;
				delete temp;
			}
			else
			{
				mNode* temp = first;
				first = nullptr;
				delete temp;
			}
			return true;
		}
		return false;
	}

	void erase(mNode* toerase)
	{
		if (size() > 1)
		{
			if (toerase->prev == nullptr)
			{
				first = toerase->next;
				first->prev = nullptr;
			}
			else if (toerase->next == nullptr)
			{
				toerase->prev->next = nullptr;
			}
			else
			{
				toerase->prev->next = toerase->next;
				toerase->next->prev = toerase->prev;
			}
			delete toerase;
		}
		else
		{
			first = nullptr;
			delete toerase;
		}
	}

	void insert(mNode* toinsert, const TYPE& data)
	{
		mNode* new_node = new mNode(data);
		if (first != nullptr)
		{
			if (toinsert->prev == nullptr)
			{
				new_node->next = toinsert;
				toinsert->prev = new_node;
				first = new_node;
			}

			else
			{
				new_node->next = toinsert;
				toinsert->prev->next = new_node;
				new_node->prev = toinsert->prev;
				toinsert->prev = new_node;
			}
		}

		else
		{
			first = new_node;
		}
	}

	void clear()
	{
		mNode* n = first;
		mNode* next;
		while (n != nullptr)
		{
			next = n->next;
			delete n;
			n = next;
		}
		first = nullptr;
	}

};

#endif