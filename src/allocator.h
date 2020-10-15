/*
 * This is a Allocator class
 * use for
 * - memory create and delete
 * - object constructor and destructor
 */

#ifndef MYTINYSTL_ALLOCATOR_H
#define MYTINYSTL_ALLOCATOR_H

#include <iostream>

// NOTE: Unusable
namespace tiny_stl{
    using std::size_t;

    template <typename T>
    class allocator{
    public:
        typedef T           value_type;
        typedef T*          pointer;
        typedef const T*    const_pointer;
        typedef T&          reference;
        typedef const T&    const_reference;
        typedef size_t      size_type;
        typedef ptrdiff_t   difference_type;
    public:
        static T* allocate();
        static T* allocate(size_type n);
        static void deallocate(T* ptr);
        static void deallocate(T* ptr, size_type n);
    };

    template <typename T>
    T* allocator<T>::allocate() {
        return static_cast<T*>(::operator new(sizeof(T)));
    }

    template <typename T>
    T* allocator<T>::allocate(size_type n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    template <typename T>
    void allocator<T>::deallocate(T *ptr) {
        if(ptr == nullptr){
            return;
        }

        ::operator delete(ptr);
    }

    template <typename T>
    void allocator<T>::deallocate(T *ptr, size_type) {
        if(ptr == nullptr){
            return;
        }

        ::operator delete[] (ptr);
    }
}


#endif //MYTINYSTL_ALLOCATOR_H
