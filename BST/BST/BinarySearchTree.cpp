#include "BinarySearchTree.h"

#include "Node.h"

BinarySearchTree::BinarySearchTree()
{
	Root = nullptr;
}

bool BinarySearchTree::Insert(int value)
{
	Node* newNode = new Node(value);
	if(Root == nullptr)
	{
		Root = newNode;
		return true;
	}

	Node* Temp = Root;
	while(true)
	{
		if(newNode->value == Temp->value)
		{
			return false;
		}

		if(newNode->value < Temp->value)
		{
			if(Temp->Left == nullptr)
			{
				Temp->Left = newNode;
				return true;
			}
			Temp = Temp->Left;
		}
		else
		{
			if(Temp->Right == nullptr)
			{
				Temp->Right = newNode;
				return true;
			}
			Temp = Temp->Right;
		}
	}
}

bool BinarySearchTree::Contains(int value)
{
	//if (Root == nullptr) return false;
	Node* temp = Root;

	while(temp)
	{
		if(value < temp->value)
		{
			temp = temp->Left;
		}
		else if(value > temp->value)
		{
			temp = temp->Right;
		}
		else
		{
			return true;
		}
	}

	return false;
}
