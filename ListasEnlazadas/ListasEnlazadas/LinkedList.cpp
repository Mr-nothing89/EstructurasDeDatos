#include "LinkedList.h"
#include "Node.h"
#include <iostream>

LinkedList::LinkedList(int value)
{
	Node* newNode = new Node(value);
	Head = newNode;
	Tail = newNode;
	Length = 1;
}

LinkedList::~LinkedList()
{
	Node* Temp = Head;
	while (Head)
	{
		Head = Head->Next;
		delete Temp;
		Temp = Head;
	}
}

void LinkedList::PrintList()
{
	Node* Temp = Head;
	while (Temp)
	{
		std::cout << Temp->Value << std::endl;
		Temp = Temp->Next;
	}
}

void LinkedList::Append(int value)
{
	Node* newNode = new Node(value);
	if (Length == 0)
	{
		Head = newNode;
		Tail = newNode;
	}
	else
	{
		Tail->Next = newNode;
		Tail = newNode;
	}
	Length++;
	
}

void LinkedList::Prepend(int value)
{
	Node* newNode = new Node(value);
	if (Length == 0)
	{
		Head = newNode;
		Tail = newNode;
	}
	else
	{
		newNode->Next = Head;
		Head = newNode;
	}
	Length++;
}

void LinkedList::DeleteLast()
{
	if (Length == 0)
	{
		return;
	}

	if (Length == 1)
	{
		Head = nullptr;
		Tail = nullptr;
	}
	else
	{
		Node* Temp = Head;
		Node* Pre = Head;
		while (Temp->Next)
		{
			Pre = Temp;
			Temp = Temp->Next;

		}
		Tail = Pre;
		Tail->Next = nullptr;
	}
	
	Length--;
}

void LinkedList::DeleteFirst()
{
	if (Length == 0)
	{
		return;
	}

	if (Length == 1)
	{
		Head = nullptr;
		Tail = nullptr;
	}
	else
	{
		Node* Temp = Head;
		Head = Head->Next;
		delete Temp;
	}
	Length--;
}

Node* LinkedList::Get(int index)
{
	if (index < 0 || index >= Length)
	{
		return nullptr;
	}
	Node* Temp = Head;
	for (int i = 0; i < index; i++)
	{
		Temp = Temp->Next;
	}
	return Temp;
}

bool LinkedList::Set(int index, int value)
{
	if (index < 0 || index >= Length)
	{
		return false;
	}
	Node* Temp = Get(index);
	if (Temp)
	{
		Temp->Value = value;
		return true;
	}
	return false;
	

}

bool LinkedList::Insert(int index, int value)
{
	if (index < 0 || index > Length)
	{
		return false;
	}
	if (index == 0)
	{
		Prepend(value);
		return true;
	}
	if (index == Length)
	{
		Append(value);
		return true;
	}
	
	Node* newNode = new Node(value);
	Node* Temp = Get(index - 1);
	newNode->Next = Temp->Next;
	Temp->Next = newNode;
	Length++;
	return true;
}

void LinkedList::DeleteNode(int index)
{
	if (index < 0 || index > Length)
	{
		return;
	}
	if (index == 0)
	{
		return DeleteFirst();
	}
	if (index == Length - 1)
	{
		return DeleteLast();
	}

	Node* prev = Get(index - 1);
	Node* temp = prev->Next;
	prev->Next = temp->Next;
	delete temp;
	Length--;
}

void LinkedList::Reverse()
{
	Node* temp = Head;
	Head = Tail;
	Tail = temp;

	Node* After = temp->Next;
	Node* before = nullptr;

	for (int i = 0; i < Length; i++)
	{
		After = temp->Next;
		temp->Next = before;
		before = temp;
		temp = After;
	}
}



void LinkedList::GetHead()
{
	std::cout << "Head: " << Head->Value << std::endl;
}

void LinkedList::GetTail()
{
	std::cout << "Tail: " << Tail->Value << std::endl;
}

void LinkedList::GetLength()
{
	std::cout << "Length: " << Length << std::endl;
}
