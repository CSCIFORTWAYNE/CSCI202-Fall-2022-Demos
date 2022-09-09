#ifndef LINKED_H
#define LINKED_H
#include <stdexcept>


template <class Type>
struct nodeType
{
	Type * info;
	nodeType<Type> *link;
	~nodeType()
	{
		delete info;
	}
};

template <class Type>
class linkedListType
{
public:
    linkedListType();
    linkedListType(const linkedListType<Type> &otherList);
    const linkedListType<Type>& operator=(const linkedListType<Type>&);
    virtual void insert(const Type& newInfo) = 0;
    virtual void deleteNode(const Type& deleteItem) = 0;
    virtual bool search(int num) = 0;
    ~linkedListType();
    void initializeList();
	bool isEmptyList() const;
	void print() const;
	int length() const;
	void destroyList();
	Type front() const;
	Type back() const;

protected:    
    nodeType * head;
    nodeType * tail;
    int length;
private: 
	void copyList(const linkedListType<Type>& otherList);
};



#endif