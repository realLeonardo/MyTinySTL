/*
 * iterator
 *
 */

#ifndef TINYSTL_ITERATOR_H
#define TINYSTL_ITERATOR_H

namespace tiny_stl {
template <typename T>
class iterator {
 public:
  static T* iterate(T t) { return static_cast<T*>(t); }
};
}  // namespace tiny_stl

#endif  // TINYSTL_ITERATOR_H
