#ifndef TREE_H
#define TREE_H

template <class T>
struct treeNode
{
    T* info;
    treeNode *nextSibling;
    treeNode *firstChild;
};



#endif