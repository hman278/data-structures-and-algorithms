#include "LinkedList.h"

#include <iostream>
#include <memory>
#include <string>

int main()
{
    LinkedList<int> linkedList;

    linkedList.Append(2);
    Node<int> *firstNode = linkedList.Prepend(1);
    linkedList.InsertBefore(firstNode, 0);

    std::cout << linkedList << std::endl;

    // std::cout << linkedList.Get(0) << std::endl;
    // std::cout << linkedList.Get(1) << std::endl;
    // std::cout << linkedList.Get(2) << std::endl;
    // std::cout << linkedList.Get(3) << std::endl;
    // std::cout << linkedList.Get(4) << std::endl;

    // std::cin.get();

    return 0;
}
