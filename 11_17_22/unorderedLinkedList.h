#ifndef UNORDERED_H
#define UNORDERED_H
#include <stdexcept>
#include "linkedList.h"

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
	public:
		bool search(const Type& searchItem) const;
		void insert(const Type& newItem);
		void deleteNode(const Type& deleteItem);
		Type operator[](int i);
		void swap(int, int);
	
};

template <class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const
{
    nodeType<Type> * current;
    bool found = false;
    current = this->head;
    while(current != nullptr && !found)
    {
        if(*(current->info) == searchItem)
        {
            found = true;
        }
        else 
        {
            current = current->link;
        }
    }
    return found;
}

template <class Type>
void unorderedLinkedList<Type>::insert(const Type& newItem)
{
    nodeType<Type> * newNode;
    newNode = new nodeType<Type>;
    newNode->info = new Type(newItem);
    newNode->link = nullptr;
    if(this->isEmptyList())
    {
        this->head = newNode;
        this->tail = newNode;
        this->count++;
    }
    else
    {
        this->tail->link = newNode;
        this->tail = newNode;
        this->count++;
    }
}

template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
	nodeType<Type> * current;
	nodeType<Type> * trailCurrent;
	bool found;
	
	if(this->head == nullptr)
		throw std::out_of_range("Cannot delete from empty list.");
	else
	{
		if(*(this->head->info) == deleteItem)
		{
			current = this->head;
			this->head = this->head->link;
			this->count--;
			if(this->head == nullptr)
				this->tail = nullptr;
			delete current;
		}
		else 
		{
			found = false;
			trailCurrent = this->head;
			current = this->head->link;
			while(current != nullptr && !found)
			{
				if(*(current->info) != deleteItem)
				{
					trailCurrent = current;
					current = current->link;
				}
				else
					found = true;
			}
			if(found)
			{
				trailCurrent->link = current->link;
				this->count--;
				if(this->tail == current)
					this->tail = trailCurrent;
				delete current;
			}
			else 
				throw std::out_of_range("Item not found in list. Cannot delete.");
		}
	}
}

template<class Type>
Type unorderedLinkedList<Type>::operator[](int i)
{
	if(i > this->count -1 || i < 0)
		throw std::out_of_range("Position is outside fo the linked list");
	linkedListIterator<Type> it = this->begin();
	for (int j = 0; j < i; j++)
	{
		++it;
	}
	return *it;
}

template<class Type>
void unorderedLinkedList<Type>::swap(int pos1, int pos2)
{
	nodeType<Type>* item1;
	nodeType<Type>* item2;
	nodeType<Type>* temp;
	nodeType<Type>* trail1;
	nodeType<Type>* trail2;
	temp = this->head;
	trail1 = nullptr;
	for(int i = 0; i < pos1; i++)
	{
		trail1 = temp;
		temp = temp->link;
	}
	item1 = temp;
	temp = this->head;
	trail2 = nullptr;
	for(int i = 0; i < pos2; i++)
	{
		trail2 = temp;
		temp = temp->link;
	}
	item2 = temp;
	
	
		if(item1->link == item2)
		{
			temp = item1;
		}
		else
		{
			temp = item1->link;
			if(trail2 != nullptr)
				trail2->link = item1;
		}
		if(item2->link == item1)
			item1->link = item2;
		else 
		{
			item1->link = item2->link;
			if(trail1 != nullptr)
				trail1->link = item2;
		}
		item2->link = temp;
		
		
	if(item1 == this->head)
	{
		this->head = item2;
	}
	else if(item2 == this->head)
	{
		this->head = item1;
	}
	if(item1 == this->tail)
	{
		this->tail = item2;
	}
	else if(item2 == this->tail)
	{
		this->tail = item1;
	}
}

#endif