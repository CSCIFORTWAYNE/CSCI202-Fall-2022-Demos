#ifndef UNORDERED_H
#define UNORDERED_H
#include "linkedList.h"

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
	public:
		bool search(const Type& searchItem) const;
		void insert(const Type& newItem);
		void deleteNode(const Type& deleteItem);
	
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



#endif