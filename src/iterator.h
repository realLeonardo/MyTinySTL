/*
 * iterator
 *
 */

#ifndef MYTINYSTL_ITERATOR_H
#define MYTINYSTL_ITERATOR_H

namespace tiny_stl{
    template <typename T>
    class iterator{
    public:
        static T* iterate(T t) {
            return static_cast<T*>(t);
        }
    };
}

#endif //MYTINYSTL_ITERATOR_H
