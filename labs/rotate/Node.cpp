#include "Node.h"

// Node Function Implementations
Node::Node(std::string val){
    data = val;
    up = nullptr;
    downleft = nullptr;
    downright = nullptr;
}
Node::Node(){
    
    up = nullptr;
    downleft = nullptr;
    downright = nullptr;
}