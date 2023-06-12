#include "./Array.h"

#include <iostream>

int main()
{
    Array<int, 3> array = {1, 2, 3};

    std::cout << "Array contents: " << array << std::endl;
    std::cout << "Array length: " << array.GetLength() << std::endl;
    std::cout << "Array first element: " << array[0] << std::endl;

    array[0] = 10;

    std::cout << "Array first element after reassignment: " << array[0] << std::endl;

    array = {4, 5, 6};

    std::cout << "Array contents after reassignment: " << array << std::endl;

    std::cin.get();

    return 0;
}

template <class T, size_t SIZE>
Array<T, SIZE>::Array(std::initializer_list<T> arr)
{
    std::copy(arr.begin(), arr.end(), array);
}

template <typename T, size_t SIZE>
Array<T, SIZE>::~Array()
{
}

template <typename T, size_t SIZE>
Iterator<T> Array<T, SIZE>::begin()
{
    return Iterator<T>(array);
}

template <typename T, size_t SIZE>
Iterator<T> Array<T, SIZE>::end()
{
    return Iterator<T>(array + SIZE);
}

template <typename T, size_t SIZE>
size_t Array<T, SIZE>::GetLength()
{
    return SIZE;
}

// bool String::IsEqual(const char *str)
// {
//     return string == str;
// }

// void String::Append(const char *str)
// {
//     string = string + *str;
// }

// void String::Insert(const char c, size_t index)
// {
//     char *split1 = new char[index - 1];
//     char *split2 = new char[std::strlen(string) - index];
//     char *newStr = new char[std::strlen(string) + 1];

//     for (int i = 0; i < std::strlen(string); i++)
//     {
//         if (i <= index)
//         {
//             split1 += string[i];
//         }
//         else
//         {
//             split2 += string[i];
//         }
//     }

//     // newStr = split1 + c + *split2;
//     // string = new char[std::strlen(newStr)];
//     // string = newStr;
// }

template <typename T, size_t SIZE>
Array<T, SIZE> &Array<T, SIZE>::operator=(std::initializer_list<T> arr)
{
    std::copy(arr.begin(), arr.end(), array);
    return *this;
}

template <typename U, size_t S>
std::ostream &operator<<(std::ostream &os, Array<U, S> &arr)
{
    for (auto element : arr)
    {
        os << element << " ";
    }

    return os;
}

template <typename T, size_t SIZE>
T &Array<T, SIZE>::operator[](const size_t index)
{
    return *(array + index);
}
