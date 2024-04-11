#include "FibVec.h"

// This provides exception types:
#include <stdexcept>

// FibVec Function Implementations
FibVec::FibVec(){
    cap = 1;
    cnt = 0;
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
void FibVec::insert(int value, size_t index){
    if(index > cnt){
        throw std::out_of_range("Index out of range");
    }

    if(cnt == cap){
        int a = 0;
        int b = 1;
        int fib = a + b;
        while(fib <= (int)cnt){
            a = b;
            b = fib;
            fib = a + b;
        }
        int *newf = new int[fib];
        for(size_t i = 0; i < cnt; i++){
            newf[i] = f[i];
        }
        delete[] f;
        f = newf;
        cap =fib;
    }
    for(size_t i = cnt; i > index-1; i--){
        f[i] = f[i-1];
    }
    f[index] = value;
    cnt ++;
}
size_t FibVec::lookup(size_t index) const{
    if(index >= cnt){
        throw std::out_of_range("Index out of range");
    }
    return f[index];
}
size_t FibVec::pop(){
    if (cnt <= 0){
        throw std::underflow_error("Underflow error");
    }
    

    int temp = f[cnt-1];
    f[cnt-1] = 0;
    cnt --;
    return temp;
    
}
void FibVec::push(int value){
    FibVec::insert(value, cnt);
}
size_t FibVec::remove(size_t index){
    if(index > cnt){
        throw std::out_of_range("Index out of range");
    }
    int ret = f[index];
    for(int i = index; i < (int)cnt -1; i++){
        f[i] = f[i+1];
    }
    cnt --;
    return ret;
}
