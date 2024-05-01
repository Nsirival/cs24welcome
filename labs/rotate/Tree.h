#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree
{
  size_t num;
  Node *hi;
  size_t nodecount = 0;
  size_t randomnum = -1;
  // Private Helper Functions
  size_t recursivecount(Node *start);
  void recursiveclear(Node *start);
  size_t recursivefind(Node *start, std::string value);

public:
  Tree();
  ~Tree();

  // Public Member Functions
  void clear();
  size_t count() const;
  bool contains(const std::string &s);
  size_t find(const std::string &s);
  void insert(const std::string &s);
  std::string lookup(size_t index) const;
  void print() const;
  void remove(size_t index);
};

#endif
