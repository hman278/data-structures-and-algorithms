#include <gtest/gtest.h>
#include <Array.h>

TEST(ArrayTest, ConstructorInvalidArgument)
{
    try
    {
        Array<int, 5> array = {1, 2, 3, 4};
        FAIL() << "Expected std::invalid_argument exception";
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_STREQ("Initializer list size mismatch", e.what());
    }
}

TEST(ArrayTest, EqualityOperatorInvalidArgument)
{
    try
    {
        Array<int, 5> array;
        array = {1, 2, 3, 4};
        FAIL() << "Expected std::invalid_argument exception";
    }
    catch (const std::invalid_argument &e)
    {
        EXPECT_STREQ("Initializer list size mismatch", e.what());
    }
}

TEST(ArrayTest, EqualityOperatorArray)
{
    Array<int, 3> array_a = {1, 2, 3};
    Array<int, 3> array_b = array_a;

    ASSERT_EQ(array_b[0], 1);
    ASSERT_EQ(array_b[1], 2);
    ASSERT_EQ(array_b[2], 3);
}

TEST(ArrayTest, GetLength)
{
    Array<int, 3> array = {1, 2, 3};

    ASSERT_EQ(array.GetLength(), 3);
}

TEST(ArrayTest, ElementAccessOperator)
{
    Array<int, 3> array = {1, 2, 3};

    ASSERT_EQ(array[0], 1);
    ASSERT_EQ(array[1], 2);
    ASSERT_EQ(array[2], 3);

    try
    {
        int value = array[4];
        // If an exception was not thrown than we fail the test manually
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

TEST(ArrayTest, EqualityCheckOperator)
{
    Array<int, 3> array_a = {1, 2, 3};
    Array<int, 3> array_b = {3, 2, 1};
    Array<int, 3> array_c = {1, 2, 3};

    ASSERT_EQ(array_a == array_b, false);
    ASSERT_EQ(array_a == array_c, true);
}

TEST(ArrayTest, Reverse)
{
    Array<int, 3> array = {1, 2, 3};

    array.Reverse();

    std::ostringstream oss;
    oss << array;

    ASSERT_EQ(oss.str(), "3 2 1 ");
}