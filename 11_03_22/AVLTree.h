#ifndef AVLTREE_H
#define AVLTREE_H
#include <sstream>
#include <string>
#include <stdexcept>
#include "binarySearchTree.h"

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
    const AVLTreeType<T> &operator=(const AVLTreeType<T> &);
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
    friend ostream &operator<<(ostream &out, const AVLTreeType<Type> &tree);
    AVLTreeType(const AVLTreeType<T> &otherTree);
    AVLTreeType();
    ~AVLTreeType();

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
    string printTree() const;
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
        return 1 + max(height(p->llink), height(p->rLink));
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
    AVLNode *p;
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
    AVLNode *p;
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
    AVLNode *p;
    AVLNode *w;
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

#endif
