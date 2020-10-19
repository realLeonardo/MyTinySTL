#ifndef MYTINYSTL_VECTOR_TEST_H
#define MYTINYSTL_VECTOR_TEST_H

#include "../src/vector.h"
#include <iostream>

namespace tiny_stl_test{
using tiny_stl::vector;
using std::cout;
using std::endl;

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

  for(auto i=v.begin(); i<v.end(); i++){
    cout << *i << endl;
  }

  cout << "size: " << v.size() << endl;
  cout << "capacity: " << v.capacity() << endl;
}

}

#endif //MYTINYSTL_VECTOR_TEST_H
