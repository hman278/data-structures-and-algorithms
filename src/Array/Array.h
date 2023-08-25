#pragma once

#include "./IIterable.h"
#include "./ConstIterator.h"

#include <math.h>
#include <ostream>
#include <initializer_list>
#include <algorithm>
#include <format>

template <typename T, size_t SIZE = 0>
class Array : IIterable<T>
{
public:
    Array<T, SIZE>(std::initializer_list<T> arr) { std::copy(arr.begin(), arr.end(), array); }
    ~Array<T, SIZE>() {}

    virtual ConstIterator<T> begin() const override { return ConstIterator<T>(array); }
    virtual ConstIterator<T> end() const override { return ConstIterator<T>(array + SIZE); }

    const size_t GetLength() const
    {
        return SIZE;
    }

    // Array<T, SIZE + 1> Insert(const T &e, size_t index)
    // {
    //     if (index >= SIZE)
    //     {
    //         throw std::out_of_range("Index out of range");
    //     }
    //
    //     Array<T, SIZE + 1> array;
    //
    //     if (i == SIZE - 1)
    //     {
    //         return;
    //     }
    //     else if (i == 0)
    //     {
    //         return;
    //     }
    //
    //     for (int i = index; i < SIZE; ++i)
    //     {
    //     }
    //
    //     return array;
    // }

    Array &Replace(const T &e, size_t index, size_t len);
    Array &Reverse(const Array &arr);

    // Performs a linear search on a sorted array
    // O(n)
    bool LinearSearch(const T &element)
    {
        for (int i = 0; i < GetLength(); ++i)
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
                high = middle;
            }
            else
            {
                low = middle + 1;
            }
        } while (low < high);

        return false;
    }

    // O(sqr(N))
    void BubbleSort()
    {
        for (int i = 0; i < GetLength(); ++i)
        {
            for (int j = 0; j < GetLength() - 1 - i; ++j)
            {
                if (array[j] > array[j + 1])
                {
                    T tmp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }
    }

    Array &operator=(std::initializer_list<T> arr)
    {
        std::copy(arr.begin(), arr.end(), array);
        return *this;
    }

    // User defined types must have the '==' operator overloaded
    template <typename U, size_t SIZE_>
    bool operator==(const Array<U, SIZE_> &arr) const
    {
        if (SIZE != SIZE_)
        {
            return false;
        }

        return std::equal(begin(), end(), arr.begin());
    }

    T &operator[](const size_t index)
    {
        if (index >= SIZE)
        {
            throw std::out_of_range("Index out of range");
        }

        return *(array + index);
    }

    friend std::ostream &operator<<(std::ostream &os, Array<T, SIZE> &arr)
    {
        for (T element : arr)
        {
            os << element << " ";
        }

        return os;
    }

private:
    T array[SIZE];
};
