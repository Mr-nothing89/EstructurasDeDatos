#pragma once
class Node;

class DoublyLinkedList
{
private:

	Node* Head;
	Node* Tail;
	int Length;

public:

	DoublyLinkedList(int value);

	void PrintList();

	void Append(int value);
	void Prepend(int value);
	void DeleteLast();
	void DeleteFirst();
	void DeleteNode(int index);

	Node* Get(int index);
	bool Set(int index, int value);
	bool Insert(int index, int value);

	void GetHead();
	void GetTail();
	void GetLength();

};

