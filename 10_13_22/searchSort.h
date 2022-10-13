#ifndef SEARCH_H
#define SEARCH_H
#include <iostream>
/*********SEARCH ALGORITHMS**********/
template <class elemType>
int seqSearch(const elemType list[], int length, const elemType &item)
{
    int loc;
    bool found = false;
    for (loc = 0; loc < length && !found; loc++)
    {
        if (list[loc] == item)
        {
            found = true;
        }
    }
    if (found)
    {
        return loc;
    }
    else
    {
        return -1;
    }
}

template <class elemType>
int binarySearch(const elemType list[], int length, const elemType &item, int& comp)
{
    int first = 0;
    int last = length - 1;
    int mid;
    bool found = false;
    comp = 0;
    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (list[mid] == item)
        {
            found = true;
        }
        else if (list[mid] > item)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
        comp++;
    }
    if(found)
        return mid;
    else
        return -1;
}

/*********SORT ALGORITHMS**********/
template <class elemType>
void bubbleSort(elemType list[], int length)
{
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration; index++)
        {
            if (list[index] > list[index + 1])
            {
                elemType temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
}

template <class elemType>
int minLocation(elemType list[], int first, int last)
{
    int minIndex;
    minIndex = first;
    for (int loc = first + 1; loc <= last; loc++)
    {
        if (list[loc] < list[minIndex])
        {
            minIndex = loc;
        }
    }
    return minIndex;
}

template <class elemType>
void swap(elemType list[], int first, int second)
{
    elemType temp = list[first];
    list[first] = list[second];
    list[second] = temp;
}

template<class elemType>
void selectionSort(elemType list[], int length)
{
    int minIndex;
    for(int loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length -1);
        swap(list, loc, minIndex);
        std::cout << loc << std::endl;
    }
}

template <class elemType>
void insertionSort(elemType list[], int length)
{
    for(int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
    {
        if(list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            elemType temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;
            do
            {
                list[location] = list[location-1];
                location--;
            } while(location > 0 && list[location - 1] > temp);
            list[location] = temp;
        }
        std::cout << firstOutOfOrder << std::endl;
    }
}

template <class elemType>
void merge(elemType list[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    elemType * leftList = new elemType[n1];
    elemType * rightList = new elemType[n2];

    for(i = 0; i < n1; i++)
    {
        leftList[i] = list[left + i];
        //std::cout << leftList[i] << " ";
    }
    //std::cout << std::endl;
    for(j = 0; j < n2; j++)
    {
        rightList[j] = list[mid + 1 + j];
        //std::cout << rightList[j] << " ";
    }
    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2)
    {
        if(leftList[i] <= rightList[j])
        {
            list[k] = leftList[i];
            i++;
        }
        else
        {
            list[k] = rightList[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        list[k++] = leftList[i++];
    }
    while(j < n2)
    {
        list[k++] = rightList[j++];
    }
    delete [] leftList;
    delete[] rightList;
}

template<class elemType>
void mergeSort(elemType list[], int length)
{
    int currSize;
    int leftStart;
    for(currSize = 1; currSize < length; currSize = 2 * currSize)
    {
        for(leftStart = 0; leftStart < length -1; leftStart += 2 * currSize)
        {
            int mid;
            if(leftStart + currSize -1 < length -1)
            {
                mid = leftStart + currSize - 1;
            }
            else 
            {
                mid = length -1;
            }
            int rightEnd;
            if(leftStart + 2 * currSize -1 < length -1)
            {
                rightEnd = leftStart + 2 * currSize -1;
            }
            else
            {
                rightEnd = length - 1;
            }
            merge(list, leftStart, mid, rightEnd);
        }
        for(int i = 0; i < length; i++)
        {
            std::cout << list[i] << " ";
        }
        std::cout << std::endl;
    }
}

#endif
