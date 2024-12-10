#pragma once
#include <string>
#include <vector>
class Node;

class HashTable
{
private:

	static const int SIZE = 7;
	Node* dataMap[SIZE];

public:

	void printTable();
	int Hash(std::string key);
	void Set(std::string key, int value);
	int Get(std::string key);
	std::vector<std::string> keys();
	bool itemInCommon(std::vector<int> vect1, std::vector<int> vect2);

};

