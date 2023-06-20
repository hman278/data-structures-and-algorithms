#pragma once

#include <ostream>
#include <iostream>
#include <memory>

/* Doubly Linked List implementation */

template <typename T>
class Node
{
public:
    Node(const T *data) : data(*data) {}
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
    LinkedList<T>() {}
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

    void Append(const T *item)
    {
        try
        {
            if (item == nullptr)
            {
                throw std::invalid_argument("Can't add an item that is a nullptr");
            }

            if (head.get() == nullptr)
            {
                /*
                    Create a circular shared pointer reference
                    between the head and the tail for the one
                    single object in the linked list
                */
                head = std::make_shared<Node<T>>(item);
                tail = head;
                length++;

                return;
            }

            Node<T> *newTail = new Node<T>(*item);

            std::shared_ptr<Node<T>> tmp = std::move(tail);
            tail.reset(newTail);
            tail->prev = std::move(tmp);

            length++;

            delete newTail;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << e.what() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    void Append(const T &item)
    {
        if (head.get() == nullptr)
        {
            /*
                Create a circular shared pointer reference
                between the head and the tail for the one
                single object in the linked list
            */
            head = std::make_shared<Node<T>>(item);
            tail = head;
            length++;

            return;
        }

        Node<T> *newTail = new Node<T>(item);

        std::shared_ptr<Node<T>> tmp = std::move(tail);
        tail.reset(newTail);
        tail->prev = std::move(tmp);

        length++;

        delete newTail;
    }

    void Prepend(T item)
    {
        length++;

        head = item;
    }

    T Get(size_t index) {}

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
