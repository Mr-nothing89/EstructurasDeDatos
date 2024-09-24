
#include <iostream>

#include "Stack.h"

int main()
{
    Stack* myStack = new Stack(1);
    
    std::cout << "Popped Value: " << myStack->Pop();
    std::cout << "\n\nPopped Value: " << myStack->Pop();
    return 0;
}


