#include "Counter.h"

// Counter Member Functions
size_t Counter::count() const{
    return x.size();
}
int Counter::total() const{
    
}
void Counter::inc(const std::string &k, int p = 1){
    if(x.find(k) == nullptr){
        list.insert(k, p);

    }
        
}
void Counter::dec(const std::string &k, int p = 1){

}
void Counter::del(const std::string &k){

}
int Counter::get(const std::string &k) const{

}
void Counter::set(const std::string &k, int count){

}
