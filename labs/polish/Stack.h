#ifndef STACK_H
#define STACK_H
#include "Nodes.h"
// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.

struct Stack{
    AST* data[20];
    int index;

    Stack();
    ~Stack();
    void push(AST* data);
    AST* pop();
    
};

#endif
