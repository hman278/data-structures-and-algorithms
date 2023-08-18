cmake_minimum_required(VERSION 3.12)
project(AlgosAndStructures LANGUAGES CXX)

include(CTest)

enable_testing()

find_program(MEMORYCHECK_COMMAND drmemory)

if(NOT MEMORYCHECK_COMMAND)
    message(FATAL_ERROR "drmemory was not found.")
endif()

set(MEMORYCHECK_COMMAND_OPTIONS "--trace-children=yes --leak-check=full") 

set(CTEST_MEMORYCHECK_TYPE "DrMemory")
set(CTEST_MEMORYCHECK_COMMAND MEMORYCHECK_COMMAND)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "-D_GLIBCXX_DEBUG -g") 
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib)