#include <gtest/gtest.h>
#include <LinkedList.h>

TEST(LinkedListTest, Append)
{
    LinkedList<int> list;

    list.Append(1);

    list.Append(2);
    list.Append(3);

    ASSERT_EQ(list.Get(0), 1);
    ASSERT_EQ(list.Get(1), 2);
    ASSERT_EQ(list.Get(2), 3);
    ASSERT_EQ(list.GetLength(), 3);

    ASSERT_FALSE(list.IsEmpty());
}

TEST(LinkedListTest, Prepend)
{
    LinkedList<int> list;

    list.Prepend(1);
    list.Prepend(2);
    list.Prepend(3);

    ASSERT_EQ(list.Get(0), 3);
    ASSERT_EQ(list.Get(1), 2);
    ASSERT_EQ(list.Get(2), 1);
    ASSERT_EQ(list.GetLength(), 3);

    ASSERT_FALSE(list.IsEmpty());
}

TEST(LinkedListTest, RemoveAll)
{
    LinkedList<int> list;

    list.Append(5);
    list.Append(10);
    list.Append(5);

    list.RemoveAll(5);
    ASSERT_EQ(list.GetLength(), 1);
    ASSERT_EQ(list.Get(0), 10);
}

TEST(LinkedListTest, RemoveAt)
{
    LinkedList<int> list;

    list.Append(5);
    list.Append(10);
    list.Append(15);

    list.RemoveAt(1);
    ASSERT_EQ(list.GetLength(), 2);
    ASSERT_EQ(list.Get(0), 5);
    ASSERT_EQ(list.Get(1), 15);
}

TEST(LinkedListTest, HeadAndTailReferences)
{
    LinkedList<int> list;

    list.Append(5);
    list.Append(10);
    list.Append(15);

    ASSERT_EQ(list.GetHead()->data, 5);
    ASSERT_EQ(list.GetTail()->data, 15);
}

TEST(LinkedListTest, AccessOutOfBounds)
{
    LinkedList<int> list;

    list.Append(5);

    // Accessing out of bounds should throw an exception
    ASSERT_THROW(list.Get(1), std::out_of_range);
}

TEST(LinkedListTest, MemoryManagement)
{
    LinkedList<int> *list = new LinkedList<int>;

    list->Append(5);
    list->Append(10);

    delete list; // Destructor should deallocate memory, according to dr memory there are most likely no leaks happening in these tests
}
