#pragma once
class Node;

class Stack
{
private:

	Node* Top;
	int Height;

public:

	Stack(int value);

	void PrintStack();
	void GetTop();
	void GetHeight();

	void Push(int value);
	int Pop();
};

