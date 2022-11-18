#ifndef NODE_H
#define NODE_H
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

#endif