#include "DoublyLinkedList.h"

#include <iostream>

#include "Node.h"

DoublyLinkedList::DoublyLinkedList(int value)
{
	Node* newNode = new Node(value);
	Head = newNode;
	Tail = newNode;
	Length = 1;
}

void DoublyLinkedList::PrintList()
{
	Node* temp = Head;
	while(temp)
	{
		std::cout << temp->value << "\n";
		temp = temp->Next;
	}
}

void DoublyLinkedList::Append(int value)
{
	Node* newNode=new Node(value);
	if(Length == 0)
	{
		Head = newNode;
		Tail = newNode;
	}
	else
	{
		Tail->Next = newNode;
		newNode->Prev = Tail;
		Tail = newNode;
	}
	Length++;
}

void DoublyLinkedList::Prepend(int value)
{
	Node* newNode = new Node(value);

	if (Length == 0)
	{
		Head = newNode;
		Tail = newNode;
	}
	else
	{
		Head->Prev = newNode;
		newNode->Next = Head;
		Head = newNode;
	}
	Length++;
}

void DoublyLinkedList::DeleteLast()
{
	if(Length == 0)
	{
		return;
	}

	Node* Temp = Tail;
	if(Length == 1)
	{
		Head = nullptr;
		Tail = nullptr;
	}
	else
	{
		Tail = Tail->Prev;
		Tail->Next = nullptr;
	}
	delete Temp;
	Length--;
}

void DoublyLinkedList::DeleteFirst()
{
	if (Length == 0)
	{
		return;
	}

	Node* Temp = Head;
	if (Length == 1)
	{
		Head = nullptr;
		Tail = nullptr;
	}
	else
	{
		Head = Head->Next;
		Head->Prev = nullptr;
	}
	delete Temp;
	Length--;
}

void DoublyLinkedList::DeleteNode(int index)
{
	if (index < 0 || index >= Length)
	{
		return;
	}

	if(index == 0)
	{
		return DeleteFirst();
	}
	if(index == Length - 1)
	{
		return DeleteLast();
	}

	Node* Temp = Get(index);
	if(Temp)
	{
		Temp->Next->Prev = Temp->Prev;
		Temp->Prev->Next = Temp->Next;
	}
	delete Temp;
	Length--;
}

Node* DoublyLinkedList::Get(int index)
{
	if(index < 0 || index >= Length)
	{
		return nullptr;
	}
	Node* Temp = Head;
	if(index < Length/2)
	{
		for (int i = 0; i < index; i++)
		{
			Temp = Temp->Next;
		}
	}
	else
	{
		Temp = Tail;
		for(int i = Length - 1; i > index; i--)
		{
			Temp = Temp->Prev;
		}
	}
	return Temp;
	
}

bool DoublyLinkedList::Set(int index, int value)
{
	Node* Temp = Get(index);
	if(Temp)
	{
		Temp->value = value;
		return true;
	}
	return false;
}

bool DoublyLinkedList::Insert(int index, int value)
{
	if(index < 0 || index > Length)
	{
		return false;
	}
	if(index == 0)
	{
		Prepend(value);
		return true;
	}

	if(index == Length)
	{
		Append(value);
		return true;
	}

	Node* newNode = new Node(value);
	Node* before = Get(index - 1);
	Node* after = before->Next;

	newNode->Prev = before;
	newNode->Next = after;
	before->Next = newNode;
	after->Prev = newNode;
	Length++;
	return true;
	
}


void DoublyLinkedList::GetHead()
{
	std::cout << "Head: " << Head->value << "\n";
}

void DoublyLinkedList::GetTail()
{
	std::cout << "Tail: " << Tail->value << "\n";
}

void DoublyLinkedList::GetLength()
{
	std::cout << "Length: " << Length << "\n";
}
