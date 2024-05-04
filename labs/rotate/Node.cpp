#include "Node.h"

// Node Function Implementations

Node::Node(std::string value){

    data = value;
    up = nullptr;
    downleft = nullptr;
    downright = nullptr;
    index = 0;
}
Node::Node(){

    up = nullptr;
    downleft = nullptr;
    downright = nullptr;
    index = 0;
    
}


