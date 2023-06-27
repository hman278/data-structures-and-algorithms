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
        if (index >= length)
        {
            throw std::out_of_range("The index is out of range.");
        }

        if (index == 0)
        {
            Prepend(item);

            return;
        }
        else if (index == length - 1)
        {
            Append(item);

            return;
        }

        Node<T> &oldItem = GetNode(index);

        std::shared_ptr<Node<T>> newItem = std::make_shared<Node<T>>(item);

        *newItem->next = oldItem;
        newItem->prev = oldItem.prev;
        oldItem = *newItem;

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

        if (tail.get() == nullptr)
        {
            tail = head;
        }

        length++;
    }

    T const &Get(size_t index)
    {
        T &data = GetNode(index)->data;
        return data;
    }

    bool IsEmpty() const
    {
        return head.get() == nullptr;
    }

    Node<T> const &GetHead() const { return *head; }
    Node<T> const &GetTail() const { return *tail; }

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
    Node<T> *GetNode(size_t index)
    {
        if (index == length - 1)
        {
            return &*tail;
        }

        Node<T> *tmp = &*head;

        size_t i = 0;
        while (tmp != nullptr)
        {
            if (i == index)
            {
                return tmp;
            }

            i++;
            tmp = &*tmp->next;
        }

        // The element does not exist
        return nullptr;
    }

private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;

    size_t length;
};
