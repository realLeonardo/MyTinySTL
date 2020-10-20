/*
 * Vector
 * Need Achieve: Random access,
 * Methods:
 * * void push_back(T), int size()
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
  // Default ctor
  vector() {
    init(DEFAULT_CAPACITY);
  }
  explicit vector(const size_t cap) {
    init(cap);
  }
  // Copy ctor
  vector(const vector& v);
  // dtor
  ~vector();

  // Copy assignment operator
  vector& operator=(const vector& v);
  T operator[](const int index);

  void push_back(const T& t);
  const int size() const;
  const int capacity() const;

  // iterator
  T* begin();
  T* end();

private:
  size_t _size = 0;
  size_t _cap = 0;
  T* _begin;
  T* _end;

  // 构造函数相关
  void init(size_t cap = -1);
};

// 构造函数通用函数
template <typename T>
void vector<T>::init(size_t cap) {
  if (cap < 0) {
    cap = DEFAULT_CAPACITY;
  }

  _begin = data_allocator::allocate(cap);
  _size = 0;
  _cap = cap;
}

template <typename T>
vector<T>::vector(const vector<T> &v) {
  _cap = v._cap;
  _size = v._size;

  _begin = data_allocator::allocate(_cap);
  for (size_t i=0; i<_size; i++) {
    // 这里是否需要考虑自定义类型的复制操作符？
    _begin[i] = v[i];
  }
}

template <typename T>
vector<T>& vector<T>::operator=(const vector<T> &v) {
  _cap = v._cap;
  _size = v._size;

  _begin = data_allocator::allocate(_cap);
  for (size_t i=0; i<_size; i++) {
    _begin[i] = v[i];
  }

  return *this;
}

template <typename T>
vector<T>::~vector() {
  data_allocator::deallocate(_begin, _cap);
  _begin = nullptr;
  _end = nullptr;
}

template <typename T>
T vector<T>::operator[](const int index) {
  return _begin[index];
}

template <typename T>
void vector<T>::push_back(const T& t) {
  if (_size >= _cap) {
    _cap += DEFAULT_CAPACITY;
    // reallocate memory
    T* temp = data_allocator::allocate(_cap);

    for (int i=0; i<_size; i++) {
      temp[i] = _begin[i];
    }

    data_allocator::deallocate(_begin, _cap);
    _begin = temp;
  }

  _begin[_size] = t;
  _size++;
}

template <typename T>
const int vector<T>::size() const {
  return _size;
}

template <typename T>
const int vector<T>::capacity() const {
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
