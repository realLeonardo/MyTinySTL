cmake_minimum_required(VERSION 3.17)
project(tiny-stl)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        src/vector.h
        src/allocator.h
        src/iterator.h
        test/vector_test.h
        test/vector_test.h)

set(PROJECT_SOURCES
        main.cpp)

add_executable(tiny-stl ${PROJECT_SOURCES} ${PROJECT_HEADERS})