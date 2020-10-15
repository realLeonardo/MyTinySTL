/*
 * Vector
 * Need Achieve: Random access,
 * Methods:
 * * void push_back(T), int size()
 *
 * TODO
 */
#ifndef MYTINYSTL_VECTOR_H
#define MYTINYSTL_VECTOR_H

#include "allocator.h"

namespace tiny_stl{

    template <typename T>
    class vector{
    public:
        typedef tiny_stl::allocator<T> data_allocator;
    public:
        enum {DEFAULT_CAPACITY = 16};
        // constructor about
        vector() {
            init(DEFAULT_CAPACITY);
        }
        explicit vector(int cap) {
            init(cap);
        }
        ~vector();

        T operator[](const int index);

        void push_back(T t);
        void push_back(T& t);
        int size() const;
        int capacity() const;

        // iterator
        T* begin();
        T* end();

    private:
        // NOTE: int _x{}; == int _x = 0;
        int _size{};
        int _cap{};
        T* _begin;

        // 构造函数相关
        void init(int cap = -1);
    };

    // 构造函数通用函数
    template <typename T>
    void vector<T>::init(int cap) {
        if (cap < 0) {
            cap = DEFAULT_CAPACITY;
        }

        _begin = data_allocator::allocate(cap);
        _size = 0;
        _cap = cap;
    }

    template <typename T>
    vector<T>::~vector() {
        delete[] _begin;
        _begin = nullptr;
    }

    template <typename T>
    T vector<T>::operator[](const int index) {
        return _begin[index];
    }

    template <typename T>
    void vector<T>::push_back(T t) {
        if (_size >= _cap) {
            _cap += DEFAULT_CAPACITY;
            // reallocate memory
            T* temp = data_allocator::allocate(_cap);

            for (int i=0; i<_size; i++) {
                temp[i] = _begin[i];
            }

            delete[] _begin;
            _begin = temp;
        }

        _begin[_size] = t;
        _size++;
    }

    template <typename T>
    void vector<T>::push_back(T& t) {
        if (_size >= _cap) {
            _cap += DEFAULT_CAPACITY;
            // reallocate memory
            T* temp = data_allocator::allocate(_cap);

            for (int i=0; i<_size; i++) {
                temp[i] = _begin[i];
            }

            delete[] _begin;
            _begin = temp;
        }

        _begin[_size] = t;
        _size++;
    }


    template <typename T>
    int vector<T>::size() const {
        return _size;
    }

    template <typename T>
    int vector<T>::capacity() const {
        return _cap;
    }

    template <typename T>
    T* vector<T>::begin() {
        return _begin;
    }

    template <typename T>
    T* vector<T>::end() {
        return _begin + _size;
    }
}

#endif //MYTINYSTL_VECTOR_H
