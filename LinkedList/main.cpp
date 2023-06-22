#include "LinkedList.h"

#include <iostream>
#include <memory>
#include <string>

class DummyClass
{
private:
    int dummyData = 5;

public:
    DummyClass() {}
};

int main()
{
    LinkedList<int> linkedList;
    linkedList.Append(-1);
    linkedList.Prepend(1);
    linkedList.Append(2);
    linkedList.Append(3);
    linkedList.Append(4);
    linkedList.Prepend(0);

    std::cout << linkedList << std::endl;

    // LinkedList<DummyClass> linkedList;
    // DummyClass *c = new DummyClass();
    // linkedList.Prepend(*c);
    // delete c;

    std::cin.get();

    return 0;
}