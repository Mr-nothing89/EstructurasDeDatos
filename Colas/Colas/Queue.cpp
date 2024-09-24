#include "Queue.h"

#include <iostream>

#include "Node.h"

Queue::Queue(int value)
{
	Node* newNode = new Node(value);
	First = newNode;
	Last = newNode;
	Length = 1;
}

void Queue::PrintQueue()
{
	Node* Temp = First;
	while(Temp)
	{
		std::cout << Temp->value << std::endl;
		Temp = Temp->Next;
	}
}

void Queue::GetFirst()
{
	std::cout << "First: " << First->value << std::endl;
}

void Queue::GetLast()
{
	std::cout << "Last: " << Last->value << std::endl;
}

void Queue::GetLength()
{
	std::cout << "Length: " << Length << std::endl;
}

void Queue::Enqueue(int value)
{
	Node* newNode = new Node(value);

	if (Length == 0)
	{
		First = newNode;
		Last = newNode;
	}
	else
	{
		Last->Next = newNode;
		Last = newNode;
	}
	Length++;
}

int Queue::Dequeue()
{
	if(Length == 0)
	{
		return INT_MIN;
	}

	Node* Temp = First;
	int DequeuedValue = First->value;
	if(Length == 1)
	{
		First = nullptr;
		Last = nullptr;
	}
	else
	{
		First = First->Next;

	}
	delete Temp;
	Length--;
	return DequeuedValue;
}
