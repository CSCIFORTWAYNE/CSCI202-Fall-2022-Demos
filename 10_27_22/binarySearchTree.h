#ifndef SEARCH_H
#define SEARCH_H
#include "binaryTree.h"
#include <stdexcept>

template <class T>
class binarySearchTree : public binaryTree<T>
{
public:
    bool search(const T &searchItem) const;
    void insert(const T &insertItem);
    void deleteNode(const T &deleteItem);
    std::string print(T &searchItem, binaryNode<T> *p) const;

private:
    void deleteFromTree(binaryNode<T> *&p);
    bool search(const T &searchitem, binaryNode<T> *p) const;
    void insert(binaryNode<T> *&insertItem, binaryNode<T> *&p);
};

template <class T>
bool binarySearchTree<T>::search(const T &searchItem) const
{
    return search(searchItem, this->root);
}

template <class T>
bool binarySearchTree<T>::search(const T &searchItem, binaryNode<T> *p) const
{
    /*Start search at root node
  If no match, and search item is smaller than root node, follow lLink to left subtree
  otherwise, follow rLink to right subtree*/
    if (p == nullptr)
        return false;
    else if (*p->info == searchItem)
        return true;
    else if (*p->info > searchItem)
        return search(searchItem, p->lLink);
    else
        return search(searchItem, p->rLink);
}

template <class T>
void binarySearchTree<T>::insert(const T &insertItem)
{
    binaryNode<T> *newNode;
    newNode = new binaryNode<T>;
    newNode->info = new T(insertItem);
    newNode->lLink = nullptr;
    newNode->rLink = nullptr;
    insert(newNode, this->root);
}

template <class T>
void binarySearchTree<T>::insert(binaryNode<T> *&insertItem, binaryNode<T> *&p)
{
    if (p == nullptr)
        p = insertItem;
    else if (*p->info == *insertItem->info)
        throw std::invalid_argument("The item to be inserted is already in the tree -- duplicates are not allowed.");
    else if (*p->info > *insertItem->info)
        insert(insertItem, p->lLink);
    else
        insert(insertItem, p->rLink);
}

template <class T>
void binarySearchTree<T>::deleteNode(const T &deleteItem)
{
    binaryNode<T> *current;
    binaryNode<T> *trailCurrent;
    bool found = false;
    if (this->root == nullptr)
        throw std::invalid_argument("Cannot delete from an empty tree");
    else
    {
        current = this->root;
        trailCurrent = this->root;
        while (current != nullptr && !found)
        {
            if (*current->info == deleteItem)
                found = true;
            else
            {
                trailCurrent = current;
                if (*current->info > deleteItem)
                    current = current->lLink;
                else
                    current = current->rLink;
            }
        }
        if(current == nullptr || !found)
            throw std::invalid_argument("The item to be deleted is not in the tree.");
        else if(found)
        {
            if(current == this->root)
                deleteFromTree(this->root);
            else if(*trailCurrent->info > deleteItem)
                deleteFromTree(trailCurrent->lLink);
            else
                deleteFromTree(trailCurrent->rLink);
        }
        
    }
}

template <class T>
void binarySearchTree<T>::deleteFromTree(binaryNode<T>* &p)
{
    binaryNode<T> *current;
    binaryNode<T> *trailCurrent;
    binaryNode<T> *temp;

    if(p == nullptr)
        throw std::invalid_argument("The item to be deleted is not in the tree.");
    else if(p->lLink == nullptr && p->rLink == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    else if(p->lLink == nullptr)
    {
        temp = p;
        p = temp->rLink;
        delete temp;
    }
    else if(p->rLink == nullptr)
    {
        temp = p;
        p = temp->lLink;
        delete temp;
    }
    else
    {
        current = p->lLink;
        trailCurrent = nullptr;
        while(current->rLink != nullptr)
        {
            trailCurrent = current;
            current = current->rLink;
        }
        T * temp;
        temp = p->info;
        p->info = current->info;
        current->info = temp;
        if(trailCurrent == nullptr)
            p->lLink = current->lLink;
        else 
            trailCurrent->rLink = current->lLink;

        delete current;
    }
}

template <class T>
std::string binarySearchTree<T>::print(T& searchItem, binaryNode<T> *p) const
{
    std::ostringstream out;
    if(p == nullptr)
    {
        p = this->root;
        if(search(searchItem))
            out << print(searchItem,p);
        else
            out << "Item does not exist in the tree.";
    }
    else if(*p->info == searchItem)
        out << *p->info << std::endl;
    else if(*p->info > searchItem)
        out << print(searchItem, p->lLink);
    else
        out << print(searchItem, p->rLink);

    return out.str();

}

#endif