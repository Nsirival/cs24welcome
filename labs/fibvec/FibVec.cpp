#include "FibVec.h"
#include <vector>
// This provides exception types:
#include <stdexcept>

// FibVec Function Implementations
FibVec::FibVec(){
    this-> cap = 1;
    this-> cnt = 0;
    f = new int[cap];
}
FibVec::~FibVec(){
    delete[] f;
}
size_t FibVec::capacity() const{
    return cap;
}
size_t FibVec::count() const{
    return cnt;
}
void FibVec::insert(size_t value, size_t index){
    
    cnt ++;
}
size_t FibVec::lookup(size_t index) const{
    if(index > cnt){
        throw std::out_of_range("Index out of range");
    }
    return f[index];
}
void FibVec::pop(){
    
}
void FibVec::push(size_t value){

}
void FibVec::remove(size_t index){
    cnt --;
}

