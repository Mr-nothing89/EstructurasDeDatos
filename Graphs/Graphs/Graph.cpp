#include "Graph.h"

#include <iostream>

void Graph::printGraph()
{
	for (auto [vertex,edges] : adjList)
	{
		std::cout << vertex << ": [ ";
		for (auto edge : edges)
		{
			std::cout << edge << " ";
		}
		std::cout << "]\n";
	}
}

bool Graph::addVertex(std::string vertex)
{
	if (adjList.count(vertex) == 0)
	{
		adjList[vertex];
		return true;
	}

	return false;
}

bool Graph::addEdge(std::string vertex1, std::string vertex2)
{
	if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
	{
		adjList.at(vertex1).insert(vertex2);
		adjList.at(vertex2).insert(vertex1);
		return true;
	}
	return false;
}

bool Graph::removeEdge(std::string vertex1, std::string vertex2)
{
	if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0)
	{
		adjList.at(vertex1).erase(vertex2);
		adjList.at(vertex2).erase(vertex1);
		return true;
	}
	return false;
}

bool Graph::removeVertex(std::string vertex)
{
	if (adjList.count(vertex) == 0) return false;

	for (auto otherVertex : adjList.at(vertex))
	{
		adjList.at(otherVertex).erase(vertex);
	}
	adjList.erase(vertex);
	return true;
}
