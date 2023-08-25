#include <gtest/gtest.h>
#include <Array.h>

TEST(ArrayTest, GetLength)
{
    Array<int, 3> array = {1, 2, 3};

    ASSERT_EQ(array.GetLength(), 3);
}

TEST(ArrayTest, ElementAccessOperator)
{
    Array<int, 3> array = {1, 2, 3};

    ASSERT_EQ(array[0], 1);

    try
    {
        int value = array[4];
        FAIL() << "Expected std::out_of_range exception";
    }
    catch (const std::out_of_range &e)
    {
        EXPECT_STREQ("Index out of range", e.what());
    }
}

TEST(ArrayTest, OutputOperator)
{
    Array<int, 3> array = {1, 2, 3};

    std::ostringstream oss;
    oss << array;

    ASSERT_EQ(oss.str(), "1 2 3 ");
}

TEST(ArrayTest, EqualityOperator)
{
    Array<int, 3> array_a = {1, 2, 3};
    Array<int, 4> array_b = {1, 2, 3, 4};
    Array<int, 3> array_c = {1, 2, 3};

    ASSERT_EQ(array_a == array_b, false);
    ASSERT_EQ(array_a == array_c, true);
}