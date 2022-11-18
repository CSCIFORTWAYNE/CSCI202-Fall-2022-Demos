#ifndef LINK_H
#define LINK_H
#include "queueADT.h"
#include "node.h"
#include <stdexcept>

using std::out_of_range;


template <class Type>
class linkedQueueType: public queueADT<Type>
{
public:
	bool isEmptyQueue() const;
	bool isFullQueue() const;
	void initializeQueue();
	Type front() const;
	Type back() const;
	void enqueue(const Type& queueElement);
	Type dequeue();
	const linkedQueueType<Type>& operator= (const linkedQueueType<Type>&);
	linkedQueueType();
	linkedQueueType(const linkedQueueType<Type>&);
	~linkedQueueType();
private:	
	nodeType<Type> * queueFront;
	nodeType<Type> * queueRear;
	void copyQueue(const linkedQueueType<Type>&);
};

template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
	return queueFront == nullptr;
}

template <class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
	return false;
}

template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
	nodeType<Type> * current;
	
	
	while(queueFront != nullptr)
	{
		current = queueFront;
		queueFront = queueFront->link;
		delete current;
	}
	queueRear = nullptr;
}

template <class Type>
Type linkedQueueType<Type>::front() const
{
	return *(queueFront->info);
}

template <class Type>
Type linkedQueueType<Type>::back() const
{
	return *(queueRear->info);
}

template <class Type>
void linkedQueueType<Type>::enqueue(const Type& queueElement)
{
	nodeType<Type> * newNode;
	newNode = new nodeType<Type>;
	newNode->info = new Type(queueElement);
	newNode->link = nullptr;
	if(isEmptyQueue())
	{
		queueFront = newNode;
		queueRear = newNode;	
	}
	else 
	{
		queueRear->link = newNode;
		queueRear = newNode;
	}
}

template <class Type>
Type linkedQueueType<Type>::dequeue()
{
	if(isEmptyQueue())
		throw out_of_range("Cannot remove from an empty queue.");
	else
	{
		nodeType<Type> * temp;
		temp = queueFront;
		queueFront = queueFront->link;
		Type t(*(temp->info));
		return t;
	}
}

template <class Type>
linkedQueueType<Type>::linkedQueueType()
{
	queueFront = nullptr;
	queueRear = nullptr;
}

template <class Type>
linkedQueueType<Type>::~linkedQueueType()
{
	initializeQueue();
}

template <class Type>
void linkedQueueType<Type>::copyQueue(const linkedQueueType<Type>& otherQueue)
{
	this->initializeQueue();
	nodeType<Type> * current;
	current = otherQueue.queueFront;
	while(current != nullptr)
	{
		addQueue(*(current->info));
		current = current->link;
	}
}

template <class Type>
linkedQueueType<Type>::linkedQueueType(const linkedQueueType<Type>& otherQueue)
{
	queueFront = nullptr;
	queueRear = nullptr;
	copyQueue(otherQueue);
}

template <class Type>
const linkedQueueType<Type>& linkedQueueType<Type>::operator=(const linkedQueueType<Type>& otherQueue)
{
	if(this != &otherQueue)
		copyQueue(otherQueue);
	
	return *this;
}

























#endif