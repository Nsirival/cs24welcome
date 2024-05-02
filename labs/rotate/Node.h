#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
  size_t index;
  std::string data;
  Node* up;
  Node* downleft;
  Node* downright;
  Node();
  Node(std::string value);
};

#endif