#pragma once

#include <cstddef>
#include <iterator>

template <typename T>
class ConstIterator
{
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = const T *;
    using reference = const T &;

    ConstIterator(pointer p) : ptr(p) {}

    reference operator*() const { return *ptr; }
    pointer operator->() const { return ptr; }
    // Prefix increment
    ConstIterator &operator++()
    {
        ptr++;
        return *this;
    }
    // Postfix increment
    ConstIterator operator++(int)
    {
        ConstIterator tmp = *this;
        ++(*this);
        return tmp;
    }

    template <typename U>
    friend bool operator==(const ConstIterator<U> &a, const ConstIterator<U> &b) { return a.ptr == b.ptr; }
    template <typename U>
    friend bool operator!=(const ConstIterator<U> &a, const ConstIterator<U> &b) { return a.ptr != b.ptr; }

private:
    pointer ptr;
};
