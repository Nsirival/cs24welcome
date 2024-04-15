#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>


class FibVec {
  // Member Variables
  int *f;
  size_t cnt;
  size_t cap;
  // Helper Functions
  void fibnum(int newcap);
  size_t fibnum1(int newcap);
  size_t number1(int x);
public:
  // Constructor and Destructor
  FibVec();
  ~FibVec();
  
  // Member Functions
  size_t capacity()const;
  size_t count() const;
  void insert(int value, size_t index);
  size_t lookup(size_t index) const;
  size_t pop();
  void push(int value);
  size_t remove(size_t index);
};

#endif
