cmake_minimum_required(VERSION 3.12)
project(AlgosAndStructures LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_DEBUG "-D_GLIBCXX_DEBUG") # removed -g
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib)