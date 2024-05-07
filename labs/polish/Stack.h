#ifndef STACK_H
#define STACK_H
#include "Nodes.h"
// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.

struct Stack{
    struct Node {
        AST* daata;
        Node* prev;
    };
    Node* root;

    Stack();
    ~Stack();
    void push(AST* data);
    AST* pop();
    
};

#endif
