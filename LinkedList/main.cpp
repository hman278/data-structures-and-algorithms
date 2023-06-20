#include "LinkedList.h"

#include <iostream>
#include <memory>
#include <string>

class DummyClass
{
public:
    DummyClass() {}
};

int main()
{
    LinkedList<int> linkedList;
    linkedList.Append(4);
    std::cout << linkedList << std::endl;

    // LinkedList<DummyClass> linkedList;
    // DummyClass *c = new DummyClass();
    // linkedList.Append(c);

    std::cin.get();

    return 0;
}