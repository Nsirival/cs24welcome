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
  
public:
  // Constructor and Destructor
  FibVec();
  ~FibVec();
  
  // Member Functions
  size_t capacity()const;
  size_t count() const;
  void insert(size_t value, size_t index);
  size_t lookup(size_t index) const;
  void pop();
  void push(size_t value);
  void remove(size_t index);
};

#endif
