#include "HashTable.h"

#include <iostream>
#include <unordered_map>

#include "Node.h"

void HashTable::printTable()
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << i << ":" << std::endl;
		if (dataMap[i])
		{
			Node* temp = dataMap[i];
			while (temp)
			{
				std::cout << "   {" << temp->key << ",  " << temp->value << "}\n";
				temp = temp->next;
			}
		}
	}
}

int HashTable::Hash(std::string key)
{
	int hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		int asciiValue = int(key[i]);
		hash = (hash + asciiValue * 23) % SIZE;
	}
	return hash;
}

void HashTable::Set(std::string key, int value)
{
	int index = Hash(key);
	Node* newNode = new Node(key, value);
	if (dataMap[index] == nullptr)
	{
		dataMap[index] = newNode;
	}
	else
	{
		Node* temp = dataMap[index];
		while(temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

int HashTable::Get(std::string key)
{
	int index = Hash(key);
	Node* temp = dataMap[index];
	while (temp != nullptr)
	{
		if (temp->key == key)
		{
			return temp->value;
		}
		temp = temp->next;
	}
	return 0;
}

std::vector<std::string> HashTable::keys()
{
	std::vector<std::string> allKeys;
	for (int i = 0; i < SIZE; i++) {
		Node* temp = dataMap[i];
		while (temp != nullptr) {
			allKeys.push_back(temp->key);
			temp = temp->next;
		}
	}
	return allKeys;
}

bool HashTable::itemInCommon(std::vector<int> vect1, std::vector<int> vect2)
{
	std::unordered_map<int, bool> myMap;
	for (auto i : vect1) {
		myMap.insert({ i, true });
	}

	for (auto j : vect2) {
		if (myMap[j]) return true;
	}

	return false;
}

