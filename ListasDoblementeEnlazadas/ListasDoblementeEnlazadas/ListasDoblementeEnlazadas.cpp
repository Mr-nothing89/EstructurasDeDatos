
#include <iostream>

#include "DoublyLinkedList.h"
#include "Node.h"

int main()
{
    DoublyLinkedList* myDLL = new DoublyLinkedList(1);
    myDLL->Append(2);
    myDLL->Append(3);
    myDLL->Append(4);
    myDLL->Append(5);

    std::cout << "DLL before DeleteNode():\n";
    myDLL->PrintList();

    myDLL->DeleteNode(2);
    std::cout << "\nDLL before DeleteNode() in the middle:\n";
    myDLL->PrintList();

    myDLL->DeleteNode(0);
    std::cout << "\nDLL before DeleteNode() of first node:\n";
    myDLL->PrintList();





    return 0;
}


