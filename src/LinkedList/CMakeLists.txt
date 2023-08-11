project(LinkedList)

add_library(LinkedListLib STATIC LinkedList.h LinkedList.cpp)
target_include_directories(LinkedListLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(LinkedListLib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(LinkedList main.cpp) 
target_link_libraries(LinkedList PRIVATE LinkedListLib)