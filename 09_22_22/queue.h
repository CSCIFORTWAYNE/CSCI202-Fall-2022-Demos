#ifndef QUEUE_H
#define QUEUE_H
#include "queueADT.h"
#include <stdexcept>

template <class t>
class queue : public queueADT<t>
{
public:
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    t front() const;
    t back() const;
    void enqueue(const t& queueElement);
    t dequeue();
    queue(int size = 100);
    queue(const queue<t>&);
    ~queue();
private:
    void copyQueue(const queue<t>&);
    int maxQueueSize;
    int queueRear;
    int queueFront;
    int count;
    t ** list;

};

template <class t>
bool queue<t>::isEmptyQueue() const
{
    return count == 0;
}
template <class t>
bool queue<t>::isFullQueue() const
{
    return count == maxQueueSize;
}

template <class t>
void queue<t>::initializeQueue()
{
    if(!this->isEmptyQueue())
    {
        int i = queueFront;
        bool end = false;
        while(!end)
        {
            if(i == queueRear)
                end = true;
                
            delete list[i++];
            
            if(i >= maxQueueSize)
                i = 0;
            
        }
    }
    queueFront = 0;
    queueRear = maxQueueSize -1;
    count = 0;
}

template <class t>
t queue<t>::front() const
{
    if(this->isEmptyQueue())
        throw std::out_of_range("Cannot view item in an empty queue");
    
    return *(list[queueFront]);
}

template <class t>
t queue<t>::back() const
{
    if(this->isEmptyQueue())
        throw std::out_of_range("Cannot view item in an empty queue");
    
    return *(list[queueRear]);
}

template <class t>
void queue<t>::enqueue(const t& queueElement)
{
    if(this->isFullQueue())
        throw std::overflow_error("Cannot add to a full queue");
    if(++queueRear >= maxQueueSize)
        queueRear = 0;
    list[queueRear] = new t(queueElement);
    count++;
}

template <class t>
t queue<t>::dequeue()
{
    if(this->isEmptyQueue())
        throw std::underflow_error("Cannot delete from an empty queue");
    t returnT(*(list[queueFront]));
    delete list[queueFront++];
    if(queueFront >= maxQueueSize)
        queueFront = 0;
    count--;
    return returnT;
}

template <class t>
queue<t>::queue(int size)
{
    this->maxQueueSize = size;
    list = new t*[maxQueueSize];
    count = 0;
    initializeQueue();

}

template <class t>
void queue<t>::copyQueue(const queue<t>& o)
{
    if(!this->isEmptyQueue())
        this->initializeQueue();
    delete [] this->list;
    this->maxQueueSize = o.maxQueueSize;
    this->count = o.count;
    this->list = new t*[maxQueueSize];
    this->queueFront = o.queueFront;
    this->queueRear = o.queueRear;
    bool end = false;
    for(int i = front; !end; i++)
    {
        if(i >= maxQueueSize)
            i = 0;

        this->list[i] = new t(*(o.list[i]));

        if(i == queueRear)
            end = true;

    }

}

template <class t>
queue<t>::queue(const queue<t>& o)
{
    list = new t*[100];
    copyQueue(o);
}

template <class t>
queue<t>::~queue()
{
    initializeQueue();
    delete [] list;
}


#endif