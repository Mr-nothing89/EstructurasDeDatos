#pragma once
class Node;
class LinkedList
{
public:
	LinkedList(int value);
	~LinkedList();

	void PrintList();
	void Append(int value);
	void Prepend(int value);
	void DeleteLast();
	void DeleteFirst();
	Node* Get(int index);
	bool Set(int index, int value);
	bool Insert(int index, int value);
	void DeleteNode(int index);
	void Reverse();
	

	void GetHead();
	void GetTail();
	void GetLength();
protected:

private:
	Node* Head;
	Node* Tail;
	int Length;
};

