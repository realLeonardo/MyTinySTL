#ifndef TINYSTL_VECTOR_TEST_H
#define TINYSTL_VECTOR_TEST_H

#include <iostream>

#include "../src/vector.h"

namespace tiny_stl_test {
using std::cout;
using std::endl;
using tiny_stl::vector;

void vector_test() {
  vector<int> v(10);
  int x = 5;
  int& y = x;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(x);
  v.push_back(y);

  for (auto i = v.begin(); i < v.end(); i++) {
    cout << *i << endl;
  }

  cout << "size: " << v.size() << endl;
  cout << "capacity: " << v.capacity() << endl;
}

}  // namespace tiny_stl_test

#endif  // TINYSTL_VECTOR_TEST_H
