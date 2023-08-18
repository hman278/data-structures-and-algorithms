project(LinkedListTest)

add_executable(LinkedListTest LinkedListTest.cpp)

target_link_libraries(LinkedListTest PUBLIC LinkedListLib gtest gtest_main)

add_test(LinkedListTest LinkedListTest)
