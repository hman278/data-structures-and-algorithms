#pragma once

#include <cstddef>
#include <iterator>

template <typename T>
class Iterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;

    Iterator(pointer p) : ptr(p) {}

    reference operator*() const { return *ptr; }
    pointer operator->() const { return ptr; }
    // Prefix increment
    Iterator &operator++()
    {
        ptr++;
        return *this;
    }
    // Postfix increment
    Iterator operator++(int)
    {
        Iterator tmp = *this;
        ++(*this);
        return tmp;
    }

    template <typename U>
    friend bool operator==(const Iterator<U> &a, const Iterator<U> &b) { return a.ptr == b.ptr; }
    template <typename U>
    friend bool operator!=(const Iterator<U> &a, const Iterator<U> &b) { return a.ptr != b.ptr; }

private:
    pointer ptr;
};
