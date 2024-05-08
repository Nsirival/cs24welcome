#include "Stack.h"
#include <sstream>
// Implement your Stack member functions here.

Stack::Stack(){
    root = nullptr;
}
Stack::~Stack(){
    while (root != nullptr) {
        Node* temp = root;
        root = root->prev;
        delete temp->data; // Delete the AST object
        delete temp;       // Delete the node
    }
}


void Stack::push(AST* data){
    Node* current = new Node{data, root};
    root = current;
}

AST* Stack::pop(){
    if(root == nullptr){
        throw std::runtime_error("No input.");
    }
    Node*temp = root;
    AST* data = temp->data;
    root = root->prev;
    delete temp;
    return data;
}