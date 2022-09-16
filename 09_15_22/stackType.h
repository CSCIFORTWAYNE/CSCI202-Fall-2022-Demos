#ifndef STACK_H
#define STACK_H
#include <stdexcept>
#include "stackADT.h"

template <class t>
class stackType : public stackADT<t>
{
public:
    const stackType<t>& operator=(const stackType<t>&);
    void initializeStack();
    bool isEmptyStack() const;
    bool isFullStack() const;
    void push(const t&);
    t top() const;
    t pop();
    stackType(int = 100);
    stackType(const stackType<t>&);
    ~stackType();

private:
    void copyStack(const stackType<t>&);
    int maxStackSize;
    int stackTop;
    t ** list;

};

template <class t>
void stackType<t>::initializeStack()
{
    if(!isEmptyStack())
    {
        for(int i = 0; i < stackTop; i++)
        {
            delete list[i];
        }
    }
    stackTop = 0;
}

template <class t>
bool stackType<t>::isEmptyStack() const
{
    return stackTop == 0;
}

template <class t>
bool stackType<t>::isFullStack() const
{
    return stackTop == maxStackSize;
}

template <class t>
void stackType<t>::push(const t& newItem)
{
    if(!isFullStack())
    {
        list[stackTop++] = new t(newItem);
    }
    else 
    {
        throw std::overflow_error("Stack Overflow.  Cannot add to a full stack.");
    }
}

template <class t>
t stackType<t>::top() const
{
    if(isEmptyStack())
    {
        throw std::out_of_range("Empty Stack");
    }
    return *(list[stackTop - 1]);
}

template <class t>
t stackType<t>::pop()
{
    if(isEmptyStack())
    {
        throw std::underflow_error("Stack Underflow. Cannot remove from an empty stack.");
    }
    else
    {
        t newt(*(list[stackTop - 1]));
        delete list[--stackTop];
        return newt;
    }
}

template <class t>
void stackType<t>::copyStack(const stackType<t>& othStack)
{
    if(!isEmptyStack())
    {
        for(int i = 0; i < this->stackTop; i++)
        {
            delete this->list[i];
        }
    }
    delete [] this->list;

    this->maxStackSize = othStack.maxStackSize;
    this->stackTop = othStack.stackTop;
    this->list = new t*[this->maxStackSize];
    for(int i = 0; i < this->stackTop; i++)
    {
        this->list[i] = new t(othStack.list[i]);
    }
}

template <class t>
stackType<t>::stackType(int stackSize)
{
    if(stackSize <= 0)
    {
        maxStackSize = 100;
    }
    else 
    {
        maxStackSize = stackSize;
    }
    stackTop = 0;
    list = new t *[maxStackSize];
}

template <class t>
stackType<t>::~stackType()
{
    if(!isEmptyStack())
    {
        for(int i = 0; i < this->stackTop; i++)
        {
            delete this->list[i];
        }
    }
    delete [] list;
    stackTop = 0;
}


#endif