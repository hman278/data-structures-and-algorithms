#include "LinkedList.h"

#include <iostream>
#include <memory>
#include <string>
#include <crtdbg.h>

int main()
{
    LinkedList<int> linkedList;

    linkedList.Append(2);
    // Node<int> *firstNode = linkedList.Prepend(1);
    // linkedList.InsertBefore(firstNode, 0);
    // linkedList.Append(1);
    linkedList.Append(3);
    linkedList.Append(4);
    linkedList.Append(5);
    linkedList.Append(6);

    std::cout << "Before removing: " << linkedList << std::endl;

    linkedList.RemoveAt(3);
    // linkedList.RemoveAll(3);

    std::cout << "After removing: " << linkedList << std::endl;

    std::cin.get();

    return 0;
}
