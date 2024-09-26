
#include <iostream>

#include "BinarySearchTree.h"
#include "Node.h"

int main()
{
    BinarySearchTree* myBST = new BinarySearchTree();
    myBST->Insert(47);
    myBST->Insert(21);
    myBST->Insert(76);
    myBST->Insert(18);
    myBST->Insert(27);
    myBST->Insert(52);
    myBST->Insert(82);
    std::cout << "Contains 27: " << myBST->Contains(27) << std::endl;
    std::cout << "Contains 17: " << myBST->Contains(17) << std::endl;
    return 0;
}


