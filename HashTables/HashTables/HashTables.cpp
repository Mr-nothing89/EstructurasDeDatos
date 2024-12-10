#include <iostream>

#include "HashTable.h"

int main()
{
	HashTable* myHashTable = new HashTable;
	std::vector<int> vect1{ 1, 3, 5 };

	std::vector<int> vect2{ 2, 4, 6 };

	std::cout << myHashTable->itemInCommon(vect1, vect2);
    return 0;
}

