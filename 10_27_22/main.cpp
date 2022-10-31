#include <iostream>
#include <fstream>
#include "binarySearchTree.h"


int main()
{
    binarySearchTree<int> b;

    std::ifstream in;
    in.open("input.txt");

    while(!in.eof())
    {
        try
        {
            int x;
            in >> x;
            b.insert(x);
        }
        catch(const std::invalid_argument& e)
        {
            //std::cerr << e.what() << '\n';
        }
        
    }
    int x = 490028;
    std::cout << b.print(x, nullptr) << std::endl;

    return 0;
}
