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
  void resize(int newcap);
public:
  // Constructor and Destructor
  FibVec();
  ~FibVec();
  
  // Member Functions
  size_t capacity()const;
  size_t count() const;
  void insert(size_t value, int index);
  size_t lookup(int index) const;
  size_t pop();
  void push(size_t value);
  size_t remove(int index);
};

#endif
