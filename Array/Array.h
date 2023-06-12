#pragma once

#include <ostream>

template <typename DataType>
class Iterator;

template <typename T>
class IIterable;

template <typename T, size_t SIZE = 0>
class Array : IIterable<T>
{
private:
    T array[SIZE];

public:
    Array<T, SIZE>(std::initializer_list<T> arr);
    ~Array<T, SIZE>();

    virtual Iterator<T> begin() override;
    virtual Iterator<T> end() override;

    size_t GetLength();
    void Insert(const T &e, size_t index);
    Array &Replace(const T &e, size_t index, size_t len);
    Array &Reverse(const Array &arr);
    T *Find(const T &c);

    Array &operator=(std::initializer_list<T> arr);
    T &operator[](const size_t index);
    template <typename U, size_t S>
    friend std::ostream &operator<<(std::ostream &os, Array<U, S> &arr);
};

template <typename DataType>
class Iterator
{
private:
    DataType *ptr;

public:
    explicit Iterator(DataType *p) : ptr(p) {}

    DataType &operator*()
    {
        return *ptr;
    }

    Iterator &operator++()
    {
        ++ptr;
        return *this;
    }

    bool operator==(const Iterator &other) const
    {
        return ptr == other.ptr;
    }

    bool operator!=(const Iterator &other) const
    {
        return !(*this == other);
    }
};

template <typename T>
class IIterable
{
    virtual Iterator<T> begin() = 0;
    virtual Iterator<T> end() = 0;
};