#include <iostream>
#include <fstream>
#include <cstdlib>
#include "searchSort.h"

const int ARRAY = 10;

void printResult(int index, int searchTerm, int comp);

int main()
{
    std::ifstream in;
    in.open("input.txt");

    int list[ARRAY];
    for(int i = 0; i < ARRAY; i++)
    {
        //in >> list[i];
        list[i] = rand() % 100 + 1;
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "List loaded with data." << std::endl;

    int searchTerm = 57;

    int index = seqSearch(list, ARRAY, searchTerm);
    printResult(index, searchTerm, ARRAY);
    index = seqSearch(list, ARRAY, 7646074);
	printResult(index, 7646074, index);
    index = seqSearch(list, ARRAY, 9902527);
    printResult(index, 9902527, index);

    //bubbleSort(list, ARRAY);
    //selectionSort(list, ARRAY);
    //insertionSort(list, ARRAY);
    mergeSort(list, ARRAY);

    std::cout << "Sorting Complete" << std::endl;

    int comp = 0;
    index = binarySearch(list, ARRAY, searchTerm, comp);
    printResult(index, searchTerm, comp);
    index = binarySearch(list, ARRAY, 7646074, comp);
	printResult(index, 7646074, comp);
    index = binarySearch(list, ARRAY, 9902527, comp);
    printResult(index, 9902527, comp);




    return 0;
}

void printResult(int index, int searchTerm, int comp)
{
    if(index == -1)
    {
        std::cout << searchTerm << " is not in the list." << std::endl;
    }
    else
    {
        std::cout << searchTerm << " is found at " << index << std::endl;
    }

    std::cout << comp << " comparsions performed." << std::endl;
}