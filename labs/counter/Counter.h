#ifndef COUNTER_H
#define COUNTER_H

#include "List.h"
#include <cstddef>
#include <string>

// This is the Counter class you need to implement.
// It includes the Counter::Iterator as a nested class.

class Counter {
public: 
  class Iterator {
    // Member Variables

    friend class Counter;
    Node* curr;
  public:
    Iterator(Node* n);
    

    const std::string& key() const { return curr->key; }
    int value() const { return curr->data; }

    void operator ++ ();
    bool operator == (const Iterator& other) const;
    bool operator != (const Iterator& other) const;
  };

private:
  List list;

private:
  // Helper Functions

public:
  Counter();
  ~Counter();

  size_t count() const;
  int    total() const;

  void inc(const std::string& key, int by = 1);
  void dec(const std::string& key, int by = 1);
  void del(const std::string& key);
  int  get(const std::string& key) const;
  void set(const std::string& key, int count);

  Iterator begin() const;
  Iterator end() const;
};

#endif