#pragma once

#include "./IIterable.h"
#include "./Iterator.h"

#include <ostream>
#include <initializer_list>
#include <algorithm>

template <typename T, size_t SIZE = 0>
class Array : IIterable<T>
{
public:
    Array<T, SIZE>(std::initializer_list<T> arr) { std::copy(arr.begin(), arr.end(), array); }
    ~Array<T, SIZE>() {}

    virtual Iterator<T> begin() override { return Iterator<T>(array); }
    virtual Iterator<T> end() override { return Iterator<T>(array + SIZE); }

    size_t GetLength()
    {
        return SIZE;
    }

    void Insert(const T &e, size_t index);
    Array &Replace(const T &e, size_t index, size_t len);
    Array &Reverse(const Array &arr);
    T *Find(const T &c);

    Array &operator=(std::initializer_list<T> arr)
    {
        std::copy(arr.begin(), arr.end(), array);
        return *this;
    }

    bool operator==(const Array &arr)
    {
        return std::equal(begin(), end(), arr.begin());
    }

    T &operator[](const size_t index)
    {
        return *(array + index);
    }

    template <typename U, size_t S>
    friend std::ostream &operator<<(std::ostream &os, Array<U, S> &arr)
    {
        for (auto element : arr)
        {
            os << element << " ";
        }

        return os;
    }

private:
    T array[SIZE];
};
