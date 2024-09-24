#include "Stack.h"

#include <iostream>

#include "Node.h"

Stack::Stack(int value)
{
	Node* newNode = new Node(value);
	Top = newNode;
	Height = 1;
}

void Stack::PrintStack()
{
	Node* Temp = Top;
	while(Temp)
	{
		std::cout << Temp->value << std::endl;
		Temp = Temp->Next;
	}
}

void Stack::GetTop()
{
	std::cout << "Top: " << Top->value << std::endl;
}

void Stack::GetHeight()
{
	std::cout << "Height: " << Height << std::endl;
}

void Stack::Push(int value)
{
	Node* newNode = new Node(value);
	newNode->Next = Top;
	Top = newNode;
	Height++;
}

int Stack::Pop()
{
	if(Height == 0)
	{
		return INT_MIN;
	}
	Node* Temp = Top;
	int PoppedValue = Top->value;
	Top = Top->Next;
	delete Temp;
	Height--;
	return PoppedValue;

}
