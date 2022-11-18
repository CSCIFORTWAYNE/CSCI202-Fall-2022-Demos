#ifndef GRAPH_H
#define GRAPH_H

#include "unorderedLinkedList.h"
#include "linkedQueue.h"
#include <string>
#include <fstream>
#include <stdexcept>
#include <sstream>

class graphType
{
public:
    bool isEmpty() const;
    void createGraph(std::string);
    void clearGraph();
    std::string printGraph() const;
    std::string depthFirstTraversal();
    std::string dftAtVertex(int vertex);
    std::string breadthFirstTraversal();
    graphType(int size = 0);
    ~graphType();
protected:
    int maxSize;
    int gSize;
    unorderedLinkedList<int> * graph;
private:
    void dft(int v, bool visited[], std::string& output);
};

bool graphType::isEmpty() const
{
    return gSize == 0;
}

void graphType::createGraph(std::string filename)
{
    std::ifstream in(filename);
    int index;
    int vertex;
    int adjacentVertex;
    if(gSize != 0)
        clearGraph();
    if(!in.is_open())
    {
        throw std::runtime_error("Cannot open input file.");
    }

    in >> gSize;
    if(gSize > maxSize)
    {
        delete [] graph;
        maxSize = gSize;
        graph = new unorderedLinkedList<int>[maxSize];
    }
    for(index = 0; index < gSize; index++)
    {
        in >> vertex;
        in >> adjacentVertex;
        while(adjacentVertex != -999)
        {
            graph[vertex].insert(adjacentVertex);
            in >> adjacentVertex;
        }
    }

    in.close();
    
}

void graphType::clearGraph()
{
    for(int i = 0; i < gSize; i++)
        graph[i].destroyList();
    gSize = 0;
}

graphType::graphType(int size)
{
    maxSize = size;
    gSize = 0;
    graph = new unorderedLinkedList<int>[size];
}

graphType::~graphType()
{
    clearGraph();
    delete [] graph;
}

std::string graphType::printGraph() const
{
    std::ostringstream out;
    for(int i = 0; i < gSize; i++)
    {
        out << i << " ";
        out << graph[i].print();
        out << std::endl;
    }
    out << std::endl;
    return out.str();
}

void graphType::dft(int v, bool visited[], std::string& output)
{
    visited[v] = true;
    output = output + " " + std::to_string(v) + " ";
    linkedListIterator<int> graphIt;
    for(graphIt = graph[v].begin(); graphIt != graph[v].end(); ++graphIt)
    {
        int w = *graphIt;
        if(!visited[w])
            dft(w, visited, output);
    }
}

std::string graphType::depthFirstTraversal()
{
    bool * visited;
    visited = new bool[gSize];
    std::string out = "";
    for(int i = 0; i < gSize; i++)  
        visited[i] = false;
    for(int i = 0; i < gSize; i++)
    {
        if(!visited[i])
            dft(i, visited, out);
    }

    delete [] visited;
    return out;
}

std::string graphType::dftAtVertex(int vertex)
{
    bool * visited;
    visited = new bool[gSize];
    for(int i = 0; i < gSize; i++)
        visited[i] = false;
    std::string out = "";
    dft(vertex, visited, out);
    delete [] visited;
    return out;
}


std::string graphType::breadthFirstTraversal()
{
    linkedQueueType<int> queue;
    bool * visited;
    visited = new bool[gSize];
    for(int i = 0; i < gSize; i++)
        visited[i] = false;
    std::string out = "";
    linkedListIterator<int> graphIt;
    for(int i = 0; i < gSize; i++)
    {
        if(!visited[i])
        {
            queue.enqueue(i);
            visited[i] = true;
            out = out + " " + std::to_string(i) + " ";
            while(!queue.isEmptyQueue())
            {
                int u = queue.dequeue();
                
                for(graphIt = graph[u].begin(); graphIt != graph[u].end(); ++graphIt)
                {
                    int w = *graphIt;
                    if(!visited[w])
                    {
                        queue.enqueue(w);
                        visited[w] = true;
                        out = out + " " + std::to_string(w) + " ";
                    }
                }

            }
        }
    }
    delete [] visited;
    return out;
}

#endif