#include "LinkedList.h"

#include <iostream>
#include <memory>
#include <string>

int main()
{
    LinkedList<int> linkedList;
    linkedList.Prepend(0);
    linkedList.Prepend(1);
    linkedList.Prepend(2);
    linkedList.Prepend(3);

    std::cout << linkedList.Get(0) << std::endl;
    std::cout << linkedList.Get(1) << std::endl;
    std::cout << linkedList.Get(2) << std::endl;
    std::cout << linkedList.Get(3) << std::endl;

    std::cin.get();

    return 0;
}
