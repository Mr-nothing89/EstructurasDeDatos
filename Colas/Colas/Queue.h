#pragma once
class Node;

class Queue
{
private:

	Node* First;
	Node* Last;
	int Length;

public:

	Queue(int value);

	void PrintQueue();
	void GetFirst();
	void GetLast();
	void GetLength();

	void Enqueue(int value);
	int Dequeue();

};

