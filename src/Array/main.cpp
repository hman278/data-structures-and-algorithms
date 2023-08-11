#include "./Array.h"

#include <iostream>

int main()
{
    Array<int, 3> array = {1, 2, 3};
    Array<int, 3> array2 = {1, 2, 3};

    std::cout << std::boolalpha;
    std::cout << "Array comparison: " << (array == array2) << std::endl;

    std::cout << "Array contents: " << array << std::endl;
    std::cout << "Array length: " << array.GetLength() << std::endl;
    std::cout << "Array first element: " << array[0] << std::endl;

    array[0] = 10;

    std::cout << "Array first element after reassignment: " << array[0] << std::endl;

    array = {4, 5, 6};

    std::cout << "Array contents after reassignment: " << array << std::endl;

    std::cout << "Does contain 4 (linear search): " << array.LinearSearch(4) << std::endl;
    std::cout << "Does contain 5 (binary search): " << array.BinarySearch(5) << std::endl;

    Array<int, 8> array3 = {1, 2, 5, 6, 3, 2, 1, 8};
    array3.BubbleSort();
    std::cout << "Sorting the array {1, 2, 5, 6, 3, 2, 1, 8}: " << array3 << std::endl;

    std::cin.get();

    return 0;
}
