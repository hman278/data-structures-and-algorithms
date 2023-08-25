project(Array)

add_library(ArrayLib STATIC Array.h Array.cpp IIterable.h ConstIterator.h)
target_include_directories(ArrayLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(ArrayLib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(Array main.cpp) 
target_link_libraries(Array PRIVATE ArrayLib)