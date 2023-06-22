#pragma once

#include <ostream>
#include <iostream>
#include <memory>

/* Doubly Linked List implementation */

template <typename T>
class Node
{
public:
    Node(const T &data) : data(data) {}

public:
    T data;

    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;
};

template <typename T>
class LinkedList
{
public:
    LinkedList<T>() : length(0) {}
    ~LinkedList() {}

    size_t GetLength()
    {
        return length;
    }

    void InsertAt(T item, size_t index)
    {
        length++;
    }

    T Remove(T item)
    {
        length--;
    }

    T RemoveAt(size_t index)
    {
        length--;
    }

    void Append(const T &item)
    {
        std::shared_ptr<Node<T>> newTail = std::make_shared<Node<T>>(item);
        newTail->next = nullptr;
        newTail->prev = tail;

        if (head.get() == nullptr)
        {
            newTail->prev = nullptr;
            head = newTail;
            tail = newTail;

            return;
        }

        tail->next = newTail;
        tail = std::move(newTail);

        length++;
    }

    void Prepend(const T &item)
    {
        std::shared_ptr<Node<T>> newHead = std::make_shared<Node<T>>(item);
        newHead->next = head;
        newHead->prev = nullptr;

        if (head.get() != nullptr)
        {
            // Set the second node's prev to the new head
            head->prev = newHead;
        }

        head = std::move(newHead);

        length++;
    }

    T Get(size_t index)
    {
    }

    bool IsEmpty() const
    {
        return head.get() == nullptr;
    }

    Node<T> GetHead() const { return *head; }
    Node<T> GetTail() const { return *tail; }

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &linkedList)
    {
        if (linkedList.IsEmpty())
        {
            return os;
        }

        Node<T> node = linkedList.GetHead();

        while (node.next != nullptr)
        {
            os << node.data << " ";
            node = *node.next;
        }

        os << node.data;

        return os;
    }

private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;

    size_t length;
};
