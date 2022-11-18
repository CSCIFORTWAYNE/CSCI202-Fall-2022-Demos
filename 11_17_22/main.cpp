#include "graph.h"
#include <iostream>

int main()
{
    graphType g;

    

    g.createGraph("input2.txt");
    std::cout << g.printGraph() << std::endl;

    std::cout << g.depthFirstTraversal() << std::endl;
    std::cout << g.dftAtVertex(9) << std::endl;

    std::cout << g.breadthFirstTraversal() << std::endl;
    return 0;
}