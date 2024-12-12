#include <iostream>

#include "Graph.h"

int main()
{
    Graph* myGraph = new Graph();
    myGraph->addVertex("A");
    myGraph->addVertex("B");
    myGraph->addVertex("C");
    myGraph->addVertex("D");
    myGraph->addEdge("A", "B");
    myGraph->addEdge("A", "C");
    myGraph->addEdge("A", "D");
    myGraph->addEdge("B", "D");
    myGraph->addEdge("C", "D");
    myGraph->printGraph();
    std::cout << std::endl;

    myGraph->removeVertex("D");
    myGraph->printGraph();
    
    return 0;
}


