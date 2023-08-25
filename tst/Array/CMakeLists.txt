project(ArrayTest)

add_executable(ArrayTest ArrayTest.cpp)

target_link_libraries(ArrayTest PUBLIC ArrayLib gtest gtest_main)

add_test(ArrayTest ArrayTest)
