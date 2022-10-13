#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <class Type> 
class linkedListIterator 
{ 
	public:
linkedListIterator();
//Default constructor //Postcondition: current = nullptr;
linkedListIterator(nodeType<Type> *ptr);
//Constructor with a parameter. //Postcondition: current = ptr;
Type operator*(); //Function to overload the dereferencing operator *. //Postcondition: Returns the info contained in the node.
linkedListIterator<Type> operator++(); //Overload the pre-increment operator. //Postcondition: The iterator is advanced to the next //	node.
bool operator==(const linkedListIterator<Type>& right) const; //Overload the equality operator. //Postcondition: Returns true if this iterator is equal to //	the iterator specified by right,
//	otherwise it returns false.
bool operator!=(const linkedListIterator<Type>& right) const; //Overload the not equal to operator. //Postcondition: Returns true if this iterator is not equal //	to the iterator specified by right,
//	otherwise it returns false.
private: nodeType<Type> *current; //pointer to point to the current
//node in the linked list
};

template <class Type>
linkedListIterator<Type>::linkedListIterator()
{
	current = nullptr;
}

template <class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> * ptr)
{
	current = ptr;
}

template <class Type>
Type linkedListIterator<Type>::operator*()
{
	return *current->info;
}

template <class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++()
{
	current = current->link;
	return *this;
}

template<class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type>& right) const
{
	return (current == right.current);
}

template <class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type>& right) const
{
	return (current != right.current);
}

#endif

