#pragma once

#include "./IIterable.h"
#include "./Iterator.h"

#include <math.h>
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

    // Performs a linear search on a sorted array
    // O(n)
    bool LinearSearch(const T &element)
    {
        for (int i = 0; i < GetLength(); i++)
        {
            if (array[i] == element)
            {
                return true;
            }
        }
        return false;
    }

    // Performs binary search on a sorted array
    // O(logN)
    bool BinarySearch(const T &element)
    {
        // Inclusive
        int low = 0;
        // Exclusive
        int high = GetLength();

        do
        {
            const int middle = std::floor(low + (high - low) / 2);
            const T value = array[middle];

            if (value == element)
            {
                return true;
            }
            // If user defined type - has to have the ">" comparison operator overloaded
            else if (value > element)
            {
                hi = middle;
            }
            else
            {
                low = middle + 1;
            }
        } while (low < high);

        return false;
    }

    Array &operator=(std::initializer_list<T> arr)
    {
        std::copy(arr.begin(), arr.end(), array);
        return *this;
    }

    bool operator==(Array &arr)
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
