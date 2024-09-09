#include <iostream>
#include "LinkedList.h"
#include "Node.h"

int main()
{
	LinkedList* myLinkedList = new LinkedList(1);

	myLinkedList->Append(2);
	myLinkedList->Append(3);
	myLinkedList->Append(4);
	myLinkedList->Reverse();
	
	myLinkedList->PrintList();
	
	
	

    return 0;
}
