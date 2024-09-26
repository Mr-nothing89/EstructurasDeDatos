#pragma once
class Node;

class BinarySearchTree
{
public:
	Node* Root;


	BinarySearchTree();
	bool Insert(int value);
	bool Contains(int value);
};

