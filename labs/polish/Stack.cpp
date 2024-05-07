#include "Stack.h"
#include <sstream>
// Implement your Stack member functions here.

Stack::Stack(){
    root = nullptr;
}
Stack::~Stack(){
     while (root) {
        Node* temp = root;
        root = root->prev;
        delete temp->daata; // Delete the AST object
        delete temp;       // Delete the node
    }
}


void Stack::push(AST* data){
    Node* current = new Node{data, root};
    root = current;
}

AST* Stack::pop(){
    if(root == nullptr){
        throw std::runtime_error("No Input");
    }
    Node*temp = root;
    AST* data = temp->daata;
    root = root->prev;
    delete temp;
    return data;
}
