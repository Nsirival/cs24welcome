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
  std::string printstatment = "";
  // Private Helper Functions
  void recursivedelete(Node *rooot);
  size_t recursivecount(Node *rooot);
  size_t recursivefind(Node* rooot, const std::string &s);
  void recursiveprint(Node* rooot);
  void recursiveinsert(Node* rooot, Node* newnode);
  Node* promotion(Node* rooot); int nodecount(Node*rooot);
  std::string recursiveindex(Node*rooot, int idx);
  void recursiveprint(Node*rooot);

public:
  Tree();
  ~Tree();

  // Public Member Functions
  void clear();
  size_t count();
  bool contains(const std::string &s);
  size_t find(const std::string &s);
  void insert(const std::string &s);
  std::string lookup(size_t index);
  void print();
  void remove(size_t index);
};

#endif