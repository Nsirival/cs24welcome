#include "Counter.h"
#include <functional> // For std::hash
#include "Index.h"
#include <iostream>

size_t totall;
int countt;
Counter::Iterator::Iterator(Node *n) : curr(n) {}

void Counter::Iterator::operator++()
{
    curr = curr->next;
}

bool Counter::Iterator::operator==(const Iterator &z) const
{
    return curr == z.curr;
}

bool Counter::Iterator::operator!=(const Iterator &z) const
{
    return curr != z.curr;
}

// Counter implementation
Counter::Counter() {}

Counter::~Counter() {}

size_t Counter::count() const
{
    return countt;
}
int Counter::total() const
{
    return totall;
}

void Counter::inc(const std::string &k, int h) {
    Node* n = index.find(k);
    if (n == nullptr) {
        index.add(k, list.insert(k, h));
        countt++;
        totall+= h;
    } else {
        n-> data += h;
        totall+= h;
    }
}

void Counter::dec(const std::string &k, int h) {
    Node* n = index.find(k);
    if (n == nullptr) {
        index.add(k, list.insert(k, h));
        countt ++;
        totall+= h;
    } else {
        n-> data -= h;
        totall-=h;
    }
}

void Counter::del(const std::string &k) {
    Node* n = index.find(k);
    if (n != nullptr) {
        countt --;
        totall-n->data;
        index.rem(k); 
    }
}

int Counter::get(const std::string &k) const {
    Node* n = index.find(k);
    if(n != nullptr){
        return n-> data;
    }
    return 0;
}

void Counter::set(const std::string &k, int h) {
    Node* n = index.find(k);
    if (n == nullptr) {
            inc(k, h);
    } else {
        totall -= n->data;
        totall += h;
        n->data = h;
    }
}

Counter::Iterator Counter::begin() const
{
    return Iterator(list.getHead());
}

Counter::Iterator Counter::end() const
{
    return Iterator(nullptr);
}