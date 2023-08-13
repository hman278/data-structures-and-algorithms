project(LinkedListTest)

add_executable(LinkedListTest LinkedListTest.cpp)

target_link_libraries(LinkedListTest PUBLIC LinkedListLib gtest gtest_main) # here, dig into how gtest and gtest main are created

add_test(LinkedListTest LinkedListTest)
