#include <iostream>
#include <iomanip>
#include "AVLTree.h"


int main()
{
    AVLTree<int> tree;
    for(int i = 0; i < 50; i++)
    {
        int x;
        std::cin >> x;
        tree.insert(x);
        std::cout << tree << std::endl;
        std::cout << std::setw(50) << std::setfill('*') << "*" << std::endl;

    }
    return 0;
}