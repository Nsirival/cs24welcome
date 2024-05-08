#include "Stack.h"
#include <sstream>
// Implement your Stack member functions here.

Stack::Stack(){
    
    
    index = -1;
}
Stack::~Stack(){
    for (int i = 0; i <= index; ++i)
    {
        delete data[i];
    }
}

void Stack::push(AST* node){
    if (index >= 20)
    {
        throw std::runtime_error("Stack overflow.");
    }
    index ++;
    data[index] = node;
}

AST* Stack::pop(){
    if (index <= 0)
    {
        throw std::runtime_error("No input.");
    }
    index --;
    return data[index+1];
    
}
