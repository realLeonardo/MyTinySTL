cmake_minimum_required(VERSION 3.17)
project(MyTinySTL)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_HEADERS
        src/vector.h
        src/allocator.h
        test/vector_test.h test/vector_test.h src/iterator.h)

set(PROJECT_SOURCES
        main.cpp
        )

add_executable(MyTinySTL ${PROJECT_SOURCES} ${PROJECT_HEADERS})