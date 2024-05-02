#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree
{
  // Member Variables
  Node *root;
  int index = 0;
  int leftweight;
  int rightweight;
  // Private Helper Functions
  void recursivedelete(Node *rooot);
  size_t recursivecount(Node *rooot)const;
  size_t recursivefind(Node* rooot, std::string s)const;
  void recursiveprint(Node* rooot)const;
  void recursiveinsert(Node* rooot, Node* newnode);
  // Node* promotion(Node* rooot); int nodecount(Node*rooot);
  // std::string recursiveindex(Node*rooot, int idx);
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