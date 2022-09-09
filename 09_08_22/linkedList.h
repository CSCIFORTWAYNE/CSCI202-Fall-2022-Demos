#ifndef LINKED_H
#define LINKED_H
#include <stdexcept>


struct nodeType
{
    int info;
    nodeType * link;
};

class intLinkedList
{
public:
    intLinkedList();
    void insert(int newInfo);
    void deleteNum(int del);
    void deleteNode(nodeType *);
    nodeType * search(int num);


private:    
    nodeType * head;
    nodeType * tail;
    int length;
};

intLinkedList::intLinkedList()
{
    this->head = nullptr;
    this->tail = nullptr;
    length = 0;
}

void intLinkedList::insert(int newInfo)
{
    nodeType * newNode = new nodeType;
    newNode->info = newInfo;
    newNode->link = nullptr;
    if(head == nullptr)
    {
        head = newNode;
        tail = newNode;
    } 
    else
    {
        tail->link = newNode;
        tail = newNode;
    }
    length++;
}

void intLinkedList::deleteNum(int del)
{
    nodeType * current;
    nodeType * previous;
    current = head;
    previous = head;

    while (current != nullptr)
    {
        if(current->info == del)
        {
            break;
        } 
        else
        {
            previous = current;
            current = current->link;
        }
    }

    if(current == nullptr)
    {
        throw std::out_of_range("Item not found in list. Cannot delete.");
    }

    previous->link = current->link;
    delete current;
    length--;
}





#endif