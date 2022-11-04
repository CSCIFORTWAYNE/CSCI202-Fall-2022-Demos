#ifndef AVLTREE_H
#define AVLTREE_H
#include <sstream>
#include <string>
#include <stdexcept>
#include <iostream>
#include "binarySearchTree.h"
#include "linkedQueue.h"

template <class T>
struct AVLNode
{
    T *info;
    int bfactor;
    AVLNode<T> *lLink;
    AVLNode<T> *rLink;
    ~AVLNode() { delete info; };
};

template <class T>
class AVLTree
{
public:
    const AVLTree<T> &operator=(const AVLTree<T> &);
    bool isEmpty() const;
    std::string inorderTraversal() const;
    std::string preorderTraversal() const;
    std::string postorderTraversal() const;
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    void destroyTree();
    bool search(const T &searchItem) const;
    void insert(const T &insertItem);
    void deleteNode(const T &deleteItem);
    template <class Type>
    friend std::ostream &operator<<(std::ostream &out, const AVLTree<Type> &tree);
    AVLTree(const AVLTree<T> &otherTree);
    AVLTree();
    ~AVLTree();

protected:
    AVLNode<T> *root;

private:
    void copyTree(AVLNode<T> *&copiedTreeRoot, AVLNode<T> *otherTreeRoot);
    void destroy(AVLNode<T> *&p);
    void inorder(AVLNode<T> *p, std::ostringstream &out) const;
    void preorder(AVLNode<T> *p, std::ostringstream &out) const;
    void postorder(AVLNode<T> *p, std::ostringstream &out) const;
    int height(AVLNode<T> *p) const;
    int max(int x, int y) const;
    int nodeCount(AVLNode<T> *p) const;
    int leavesCount(AVLNode<T> *p) const;
    bool search(const T &searchItem, AVLNode<T> *p) const;
    std::string printTree() const;
    void rotateToLeft(AVLNode<T> *&root);
    void rotateToRight(AVLNode<T> *&root);
    void balanceFromLeft(AVLNode<T> *&root);
    void balanceFromRight(AVLNode<T> *&root);
    void insertIntoAVL(AVLNode<T> *&root, AVLNode<T> *newNode, bool &isTaller);
};

template <class T>
int AVLTree<T>::height(AVLNode<T> *p) const
{
    if (p == nullptr)
    {
        return 0;
    }
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}

template <class T>
int AVLTree<T>::max(int x, int y) const
{
    if (x >= y)
        return x;
    else
        return y;
}

template <class T>
int AVLTree<T>::treeHeight() const
{
    return height(root);
}

template <class T>
void AVLTree<T>::rotateToRight(AVLNode<T> *&root)
{
    AVLNode<T> *p;
    if (root == nullptr)
        throw std::out_of_range("Cannot rotate empty node.");
    else if (root->lLink == nullptr)
        throw std::out_of_range("Cannot rotate empty node.");
    else
    {
        p = root->lLink;        // p is new root node made from left subtree root
        root->lLink = p->rLink; // take the left tree from old root and move the new root right tree to it
        p->rLink = root;        // take the right tree of the new root and set it to the old root
        root = p;               // Change the root to the new root
    }
}

template <class T>
void AVLTree<T>::rotateToLeft(AVLNode<T> *&root)
{
    AVLNode<T> *p;
    if (root == nullptr)
        throw std::out_of_range("Cannot rotate empty node.");
    else if (root->rLink == nullptr)
        throw std::out_of_range("Cannot rotate empty node.");
    else
    {
        p = root->rLink;        // p is new root node made from right subtree root
        root->rLink = p->lLink; // take the right tree from old root and move the new root left tree to it
        p->lLink = root;        // take the left tree of the new root and set it to the old root
        root = p;               // Change the root to the new root
    }
}

template <class T>
void AVLTree<T>::balanceFromRight(AVLNode<T> *&root)
{
    AVLNode<T> *p;
    AVLNode<T> *w;
    p = root->rLink;

    switch (p->bfactor)
    {
    case -1:
        w = p->lLink;
        switch (w->bfactor)
        {
        case -1:
            root->bfactor = 0;
            p->bfactor = 1;
            break;
        case 0:
            root->bfactor = 0;
            p->bfactor = 0;
            break;
        case 1:
            root->bfactor = -1;
            p->bfactor = 0;
        }
        w->bfactor = 0;
        rotateToRight(p);
        root->rLink = p;
        rotateToLeft(root);
        break;
    case 0:
        throw std::runtime_error("Right subtree is balanced.");
    case 1:
        root->bfactor = 0;
        p->bfactor = 0;
        rotateToLeft(root);
    }
}

template <class T>
void AVLTree<T>::balanceFromLeft(AVLNode<T> *&root)
{
    AVLNode<T> *p;
    AVLNode<T> *w;
    p = root->lLink;
    switch (p->bfactor)
    {
    case -1:
        root->bfactor = 1;
        p->bfactor = 0;
        rotateToRight(root);
        break;
    case 0:
        throw std::runtime_error("Left subtree is balanced.");
    case 1:
        w = p->rLink;
        switch (w->bfactor)
        {
        case -1:
            root->bfactor = 1;
            p->bfactor = 0;
            break;
        case 0:
            root->bfactor = 0;
            p->bfactor = 0;
            break;
        case 1:
            root->bfactor = 0;
            p->bfactor = -1;
        }
        w->bfactor = 0;
        rotateToLeft(p);
        root->lLink = p;
        rotateToRight(root);
    }
}

template <class T>
void AVLTree<T>::insert(const T& newItem)
{
    bool isTaller = false;
    AVLNode<T> * newNode;
    newNode = new AVLNode<T>;
    newNode->info = new T(newItem);
    newNode->bfactor = 0;
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;

    insertIntoAVL(root, newNode, isTaller);
}

template <class T>
void AVLTree<T>::insertIntoAVL(AVLNode<T>*&root, AVLNode<T>* newNode, bool& isTaller)
{
    if(root == nullptr)
    {
        root = newNode;
        isTaller = true;
    }
    else if(*root->info == *newNode->info)
        throw std::invalid_argument("No duplicates allowed.");
    else if(*root->info > *newNode->info)
    {
        insertIntoAVL(root->lLink, newNode, isTaller);
        if(isTaller)
        {
            switch(root->bfactor)
            {
                case -1:
                    balanceFromLeft(root);
                    isTaller = false;
                    break;
                case 0:
                    root->bfactor = -1;
                    isTaller = true;
                    break;
                case 1:
                    root->bfactor = 0;
                    isTaller = false;
            }
        }
    }
    else 
    {
        insertIntoAVL(root->rLink, newNode, isTaller);
        if(isTaller)
        {
            switch(root->bfactor)
            {
                case -1:
                    root->bfactor = 0;
                    isTaller = false;
                    break;
                case 0:
                    root->bfactor = 1;
                    isTaller = true;
                    break;
                case 1:
                    balanceFromRight(root);
                    isTaller = false;
            }
        }
    }
}

template<class T>
std::string AVLTree<T>::printTree() const
{
	std::ostringstream out;
	struct nodeDepth
	{
		AVLNode<T>* n;
    	int lvl;
    	//node_depth(node<T>* n_, int lvl_) : n(n_), lvl(lvl_) {}
	};
	int depth = height(root);
	int last_lvl = 0;
	int offset = (1 << depth) - 1;
	linkedQueueType<nodeDepth> nodes;
	nodeDepth rootDepth;
	rootDepth.n = root;
	rootDepth.lvl = last_lvl;
	nodes.enqueue(rootDepth);
	while(!nodes.isEmptyQueue())
	{
		nodeDepth current = nodes.front();
		if(last_lvl != current.lvl)
		{
			out << std::endl;
			last_lvl = current.lvl;
    		offset = (1 << (depth - current.lvl)) - 1;
			
		}
		if(current.n != nullptr)
		{
			out << std::setw(offset) << " ";
			out << std::setw(3) << *current.n->info;
			out << std::setw(offset) << " ";
			nodeDepth left;
			nodeDepth right;
			left.n = current.n->lLink;
			right.n = current.n->rLink;
			left.lvl = last_lvl + 1;
			right.lvl = last_lvl + 1;
			nodes.enqueue(left);
			nodes.enqueue(right);
		} 
		else
		{
			out << std::setw(offset) << " " << "   ";
			out << std::setw(offset) << " ";
		}
		nodes.dequeue();
	}
	out << std::endl;
	
	return out.str();
}

template <class elemType>
std::ostream& operator<<(std::ostream& out, const AVLTree<elemType>& tree)
{
	out << tree.printTree();
	return out;
}
template <class T>
AVLTree<T>::AVLTree()
{
	root = nullptr;
}

template <class T>
AVLTree<T>::~AVLTree()
{
//	destroy(root);
}
#endif
