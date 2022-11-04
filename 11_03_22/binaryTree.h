#ifndef BINARY_H
#define BINARY_H
#include <string>
#include <sstream>
template <class T>
struct binaryNode
{
    T *info;
    binaryNode<T> *lLink;
    binaryNode<T> *rLink;
    ~binaryNode() { delete info; };
};

template <class T>
class binaryTree
{
public:
    const binaryTree<T> &operator=(const binaryTree<T> &otherTree);
    bool isEmpty() const;
    std::string inorderTraversal() const;
    std::string preorderTraversal() const;
    std::string postorderTraversal() const;
    int treeHeight() const;
    int treeNodeCount(const T &searchItem) const;
    int treeLeavesCount(const T &searchItem) const;
    void destroyTree();
    virtual bool search(const T &searchItem) const = 0;
    virtual void insert(const T &insertItem) = 0;
    virtual void deleteNode(const T &deleteItem) = 0;
    binaryTree(const binaryTree<T> &otherTree);
    binaryTree();
    ~binaryTree();

protected:
    binaryNode<T> *root;

private:
    void copyTree(binaryNode<T> *&copiedTreeRoot, binaryNode<T> *otherTreeRoot);
    void destroy(binaryNode<T> *&p);
    void inorder(binaryNode<T> *p, std::ostringstream &out) const;
    void preorder(binaryNode<T> *p, std::ostringstream &out) const;
    void postorder(binaryNode<T> *p, std::ostringstream &out) const;
    int height(binaryNode<T> *p) const;
    int max(int x, int y) const;
    int nodeCount(const T &searchItem, binaryNode<T> *p, int count = 0) const;
    int leavesCount(const T &searchItem, binaryNode<T> *p, int count = 0) const;
};

template <class T>
void binaryTree<T>::copyTree(binaryNode<T> *&copiedTreeRoot, binaryNode<T> *otherTreeRoot)
{
    if (otherTreeRoot == nullptr)
        copiedTreeRoot = nullptr;
    else
    {
        copiedTreeRoot = new binaryNode<T>;
        copiedTreeRoot->info = new T(otherTreeRoot->info);
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
}

template <class T>
std::string binaryTree<T>::inorderTraversal() const
{
    std::ostringstream out;
    inorder(root, out);
    return out.str();
}

template <class T>
std::string binaryTree<T>::preorderTraversal() const
{
    std::ostringstream out;
    preorder(root, out);
    return out.str();
}

template <class T>
std::string binaryTree<T>::postorderTraversal() const
{
    std::ostringstream out;
    postorder(root, out);
    return out.str();
}

template <class T>
void binaryTree<T>::inorder(binaryNode<T> *p, std::ostringstream &out) const
{
    /*1. inorder left sub tree
  2. visit the current node
  3. inorder right sub tree */
    if (p != nullptr)
    {
        inorder(p->lLink, out);
        out << *p->info << "\n\n";
        inorder(p->rLink, out);
    }
}

template <class T>
void binaryTree<T>::preorder(binaryNode<T> *p, std::ostringstream &out) const
{
    /*1. visit current node
  2. preorder left sub tree
  3. preorder right sub tree*/
    if (p != nullptr)
    {
        out << *p->info << "\n\n";
        preorder(p->lLink, out);
        preorder(p->rLink, out);
    }
}

template <class T>
void binaryTree<T>::postorder(binaryNode<T> *p, std::ostringstream &out) const
{
    /*1. postorder left sub tree
  2. postorder right sub tree
  3. visit current node*/
    if (p != nullptr)
    {
        postorder(p->lLink, out);
        postorder(p->rLink, out);
        out << *p->info << "\n\n";
    }
}

template <class T>
const binaryTree<T> &binaryTree<T>::operator=(const binaryTree<T> &otherTree)
{
    if (this != &otherTree)
    {
        if (root != nullptr)
            destroy(root);
        if (otherTree.root == nullptr)
            root = nullptr;
        else
            copyTree(root, otherTree.root);
    }
    return *this;
}
template <class T>
bool binaryTree<T>::isEmpty() const
{
    return root == nullptr;
}
template <class T>
int binaryTree<T>::treeHeight() const
{
    return height(root);
}
template <class T>
int binaryTree<T>::treeNodeCount(const T &searchItem) const
{
    return nodeCount(searchItem, root);
}
template <class T>
int binaryTree<T>::treeLeavesCount(const T &searchItem) const
{
    return leavesCount(searchItem, root);
}

template <class T>
void binaryTree<T>::destroyTree()
{
    destroy(root);
}
template <class T>
binaryTree<T>::binaryTree(const binaryTree<T> &otherTree)
{
    if (otherTree.root == nullptr)
        root = nullptr;
    else
        copyTree(root, otherTree.root);
}
template <class T>
binaryTree<T>::binaryTree()
{
    root = nullptr;
}
template <class T>
binaryTree<T>::~binaryTree()
{
    destroy(root);
}
template <class T>
void binaryTree<T>::destroy(binaryNode<T> *&p)
{
    if(p != nullptr)
    {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = nullptr;
    }
}
template <class T>
int binaryTree<T>::height(binaryNode<T> *p) const
{
    if(p == nullptr)
        return 0;
    else 
        return 1 + max(height(p->lLink), height(p->rLink));
}
template <class T>
int binaryTree<T>::max(int x, int y) const
{
    if(x >= y)
        return x;
    else 
        return y;
}
/* template <class T>
int nodeCount(const T &searchItem, binaryNode<T> *p, int count = 0) const;
template <class T>
int leavesCount(const T &searchItem, binaryNode<T> *p, int count = 0) const; */

#endif