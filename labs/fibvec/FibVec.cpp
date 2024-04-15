#include "FibVec.h"

// This provides exception types:
#include <stdexcept>

// FibVec Function Implementations
void FibVec::fibnum(int newcap){
    int a = 0;
    int b = 1;
    int fib = a + b;
    while(fib <= newcap){
        fib = a + b;
        a = b;
        b = fib;
    }
    int *newf = new int[fib];
    for(size_t i = 0; i < cnt; i++){
        newf[i] = f[i];
    }
    delete[] f;
    f = newf;
    cap = fib;
}

size_t FibVec::fibnum1(int newcap){
    int a = 0;
    int b = 1;
    int fib = a + b;
    while(fib +b<= 30){
        a = b;
        b = fib;
        fib = a + b;
    }
    return (size_t)fib;
}

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
        FibVec::fibnum(cnt);
    }
    for(size_t i = cnt ; i > index; i--){
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
    return FibVec::remove(cnt-1);
    
}
void FibVec::push(int value){
    FibVec::insert(value, cnt);
}
size_t FibVec::remove(size_t index){
    if(index > cnt){
        throw std::out_of_range("Index out of range");
    }
    
    if(cnt < cap){
        FibVec::fibnum(cnt);
    }
    if (cnt < fibnum1(cnt)){
    int a = 0;
    int b = 1;
    int fib = a + b;
    while(fib <= (int)cnt){
        fib = a + b;
        a = b;
        b = fib;
    }
    cap = fib;
    }
    int ret = f[index];
    for(int i = index; i < (int)cnt -1; i++){
        f[i] = f[i+1];
    }
    cnt --;
    return ret;
}
