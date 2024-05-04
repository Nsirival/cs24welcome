#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree
{
  // Member Variables
  Node *root;
  Node* best;
  size_t num = 0;
  size_t leftweight = 0;
  size_t rightweight = 0;
  size_t minsum = -1;
  // Private Helper Functions
  void recursivedelete(Node *rooot);
  size_t recursivecount(Node *rooot)const;
  size_t recursivefind(Node* rooot, std::string s)const;
  void recursiveprint(Node* rooot)const;
  void recursiveinsert(Node* rooot, Node* newnode);
  std::string recursivelookup(Node* rooot, size_t index) const;
  void incrementing (Node*rooot);
  void put(Node*rooot, size_t index);
  Node* finder (Node* rooot, size_t index);
  void findmin(Node* rooot, int side);
  void rotate();
public:
  Tree();
  ~Tree();

  // Public Member Functions
  void clear();
  size_t count() const;
  bool contains(const std::string &s) const;
  size_t find(const std::string &s)const;
  void insert(const std::string &s);
  std::string lookup(size_t index)const;
  void print()const;
  void remove(size_t index);
};

#endif