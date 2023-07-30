#pragma once

#include <ostream>
#include <iostream>
#include <memory>

/* Doubly Linked List implementation */

template <typename T>
class Node
{
public:
    Node(const T &data) : data(data), next(nullptr), prev(nullptr) {}

public:
    T data;

    Node<T> *next;
    Node<T> *prev;
};

template <typename T>
class LinkedList
{
public:
    LinkedList<T>() : length(0), head(nullptr), tail(nullptr) {}

    ~LinkedList()
    {
        Node<T> *current = const_cast<Node<T> *>(GetHead());
        Node<T> *next;

        while (current != nullptr)
        {
            next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        tail = nullptr;

        length = 0;
    }

    size_t GetLength()
    {
        return length;
    }

    Node<T> *InsertBefore(Node<T> *nextNode, const T &data)
    {
        if (nextNode == nullptr)
        {
            throw std::invalid_argument("The provided node is null.");
        }

        length++;

        Node<T> *newNode = new Node<T>(data);

        newNode->prev = nextNode->prev;
        nextNode->prev = newNode;
        newNode->next = nextNode;

        if (newNode->prev != nullptr)
        {
            newNode->prev->next = newNode;
        }
        else
        {
            head = newNode;
        }

        return newNode;
    }

    void RemoveAll(const T &item)
    {
        Node<T> *nodeToDelete;

        while (head != nullptr && head->data == item)
        {
            nodeToDelete = head;
            head = head->next;
            head->prev = nullptr;

            delete nodeToDelete;
            length--;
        }
        while (tail != nullptr && tail->data == item)
        {
            nodeToDelete = tail;
            tail = tail->prev;
            tail->next = nullptr;

            delete nodeToDelete;
            length--;
        }

        Node<T> *current = const_cast<Node<T> *>(GetHead());
        while (current->next != nullptr)
        {
            if (current->next->data == item)
            {
                nodeToDelete = current->next;
                current->next = current->next->next;
                current->prev = current->prev->prev;

                delete current;

                length--;
            }
            current = current->next;
        }
    }

    void RemoveAt(const size_t index)
    {
        if (index > length)
        {
            throw std::out_of_range("The supplied index is out of range of this Linked List.");
        }

        if (index == 0)
        {
            head->next->prev = nullptr;
            head = head->next;

            length--;

            return;
        }
        else if (index == length - 1)
        {
            tail->prev->next = nullptr;
            tail = tail->prev;

            length--;

            return;
        }

        Node<T> *current = const_cast<Node<T> *>(GetHead());

        for (int i = 0; i < index - 1; ++i)
        {
            current = current->next;
        }

        Node<T> *next = current->next->next;

        delete current->next;

        current->next = next;
        next->prev = current;

        length--;
    }

    Node<T> *Append(const T &item)
    {
        length++;

        Node<T> *newTail = new Node<T>(item);
        newTail->next = nullptr;
        newTail->prev = tail;

        if (head == nullptr)
        {
            newTail->prev = nullptr;
            head = newTail;
            tail = newTail;

            return newTail;
        }

        tail->next = newTail;
        tail = newTail;

        return newTail;
    }

    Node<T> *Prepend(const T &item)
    {
        length++;

        Node<T> *newHead = new Node<T>(item);
        newHead->next = head;
        newHead->prev = nullptr;

        if (head != nullptr)
        {
            head->prev = newHead;
        }

        head = newHead;

        if (tail == nullptr)
        {
            tail = head;
        }

        return newHead;
    }

    T const &Get(size_t index)
    {
        if (index >= length)
        {
            throw std::out_of_range("The index is out of range.");
        }

        T &data = GetNode(index)->data;

        return data;
    }

    bool IsEmpty() const
    {
        return head == nullptr;
    }

    Node<T> const *GetHead() const { return head; }
    Node<T> const *GetTail() const { return tail; }

    friend std::ostream &operator<<(std::ostream &os, const LinkedList &linkedList)
    {
        if (linkedList.IsEmpty())
        {
            return os;
        }

        Node<T> *node = const_cast<Node<T> *>(linkedList.GetHead());

        while (node->next != nullptr)
        {
            os << node->data << " ";
            node = node->next;
        }

        os << node->data;

        return os;
    }

private:
    Node<T> *GetNode(size_t index)
    {
        if (index == length - 1)
        {
            return tail;
        }

        Node<T> *tmp = const_cast<Node<T> *>(GetHead());

        size_t i = 0;
        while (tmp != nullptr)
        {
            if (i == index)
            {
                return tmp;
            }

            i++;
            tmp = tmp->next;
        }

        // The element does not exist
        return nullptr;
    }

private:
    Node<T> *head;
    Node<T> *tail;

    size_t length;
};
